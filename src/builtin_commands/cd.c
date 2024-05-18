/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** cd
*/

#include "../../include/my.h"

bool cd_to_a_file(command_t *command, shell_info_t *shell_info)
{
    struct stat st;

    if (stat(command->arg[1], &st) == 0) {
        if (S_ISREG(st.st_mode)) {
            mprintf("%s: %s.\n", command->arg[1], strerror(ENOTDIR));
            shell_info->status = 1;
            return true;
        }
    }
    return false;
}

void cd_to_a_folder(command_t *command, shell_info_t *shell_info)
{
    char *cwd;

    if (!my_strcmp(command->arg[1], "-") && !my_strcmp(command->arg[1], "~") &&
    !cd_to_a_file(command, shell_info)) {
        cwd = shell_info->curr_pwd;
        cd_to_a_file(command, shell_info);
        if (access(command->arg[1], F_OK) == 0 &&
            access(command->arg[1], X_OK) != 0) {
            mprintf("%s: %s.\n", command->arg[1], strerror(EACCES));
            shell_info->status = 1;
            return;
        }
        if (chdir(command->arg[1]) == -1) {
            mprintf("%s: %s.\n", command->arg[1], strerror(ENOENT));
            shell_info->status = 1;
            return;
        }
        shell_info->old_pwd = my_strdup(cwd);
        shell_info->curr_pwd = my_strdup(getcwd(NULL, 0));
    }
}

void cd_to_old_path(command_t *command, shell_info_t *shell_info)
{
    if (my_strcmp(command->arg[1], "-") && shell_info->old_pwd != NULL) {
        chdir(shell_info->old_pwd);
        shell_info->old_pwd = shell_info->curr_pwd;
        shell_info->curr_pwd = my_strdup(getcwd(NULL, 0));
        return;
    } else if (my_strcmp(command->arg[1], "-") &&
        shell_info->old_pwd == NULL) {
        mprintf(": %s.\n", strerror(ENOENT));
        shell_info->status = 1;
        return;
    }
}

void cd_to_home(command_t *command, shell_info_t *shell_info)
{
    if (command->arg[1] == NULL && chdir(search_in_list(shell_info->env_list,
        "HOME", my_strcmp)) != 0) {
        mprintf("cd: No home directory.\n");
        shell_info->status = 1;
        return;
    }
    if (command->arg[1] != NULL && my_strcmp(command->arg[1], "~") &&
        chdir(search_in_list(shell_info->env_list, "HOME", my_strcmp)) != 0) {
        mprintf("No $home variable set.\n");
        shell_info->status = 1;
        return;
    }
    shell_info->old_pwd = shell_info->curr_pwd;
    shell_info->curr_pwd = my_strdup(getcwd(NULL, 0));
}

void cd_command(command_t *command, shell_info_t *shell_info)
{
    shell_info->status = 0;
    shell_info->curr_pwd = my_strdup(getcwd(NULL, 0));
    if (command->arg[1] == NULL || my_strcmp(command->arg[1], "~")) {
        cd_to_home(command, shell_info);
    }
    if (command->arg[1] != NULL) {
        cd_to_a_folder(command, shell_info);
        cd_to_old_path(command, shell_info);
    }
    shell_info->curr_pwd = my_strdup(getcwd(NULL, 0));
}
