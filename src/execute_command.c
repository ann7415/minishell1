/*
** EPITECH PROJECT, 2024
** PSU_minishell1_$2024
** File description:
** execute_command
*/

#include "../include/my.h"

bool if_coredump(shell_info_t *shell_info)
{
    if (shell_info->status == 139)
        mprintf("Segmentation fault");
    if (shell_info->status == 134)
        mprintf("Aborted");
    if (shell_info->status == 135)
        mprintf("Bus error");
    return true;
}

void handling_segfaults(pid_t pid, shell_info_t *shell_info, int status)
{
    waitpid(pid, &status, 0);
    if (WEXITSTATUS(status)) {
        mprintf("dans le if WEXITSTATUS, status: %d\n", status);
        shell_info->status = WEXITSTATUS(status);
    }
    else if (WIFSIGNALED(status))
        shell_info->status = WTERMSIG(status) + 128;
    if (if_coredump(shell_info) && WCOREDUMP(shell_info->status))
        mprintf(" (core dump)\n");
}

void execve_command_perm(command_t *command, shell_info_t *shell_info,
    char *path)
{
    struct stat st;

    if (stat(path, &st) == 0) {
        if (S_ISDIR(st.st_mode) || (S_ISREG(st.st_mode) &&
            access(path, X_OK) != 0)) {
            mprintf("%s: %s.", path, strerror(EACCES));
            shell_info->status = 1;
            exit(shell_info->status);
        }
    }
}

void execve_command(command_t *command, shell_info_t *shell_info, int i)
{
    char *path = command->arg[0];
    int nb = nb_slash(path);

    if ((command->arg[0][0] == '.' && command->arg[0][1] == '/') ||
        command->arg[0][0] == '/')
        execve_command_perm(command, shell_info, path);
    else if (nb == 0)
        path = my_strcat(my_strcat(shell_info->path[i], "/"), command->arg[0]);
    if (access(path, F_OK) == 0) {
        execve(path, command->arg, linked_list_to_array(shell_info->env_list));
    }
}

void execute_command(command_t *command, shell_info_t *shell_info)
{
    int status = 0;
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        for (int i = 0; shell_info->path[i] != NULL; i++)
            execve_command(command, shell_info, i);
        if (errno == ENOEXEC)
            mprintf("%s: Exec format error. Wrong Architecture.",
                command->arg[0]);
        if (errno == EACCES)
            mprintf("%s: Permission denied.", command->arg[0]);
        if (errno == ENOENT)
            mprintf("%s: Command not found.", command->arg[0]);
        exit(1);
    } else {
        handling_segfaults(pid, shell_info, status);
    }
}
