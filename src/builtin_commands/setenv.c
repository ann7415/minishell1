/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** setenv
*/

#include "../../include/my.h"

static void setenvv(env_variable_t *env_var, bool two_args,
    shell_info_t *shell_info)
{
    if (!replace_in_list(shell_info->env_list, env_var,
        my_strcmp))
        push_to_list_tail(shell_info->env_list, env_var);
}

void setenv_an_arg(command_t *command, shell_info_t *shell_info)
{
    if (command->arg[1] != NULL && command->arg[2] != NULL) {
        setenvv(create_env_variable(command->arg[1], command->arg[2]),
            false, shell_info);
        return;
    }
    if (command->arg[1] != NULL && command->arg[2] == NULL) {
        setenvv(create_env_variable(command->arg[1], command->arg[2]),
            false, shell_info);
        return;
    }
}

bool setenv_ckeck_arg(command_t *command, shell_info_t *shell_info)
{
    if (!is_arg_correct(command->arg[1][0])) {
        mprintf("setenv: Variable name must begin with a letter.\n");
        return false;
    }
    if (!is_arg_correct2(command->arg[1])) {
        mprintf("%s: Variable name must contain %s\n", "setenv",
            "alphanumeric characters.");
        return false;
    }
    return true;
}

void setenv_command(command_t *command, shell_info_t *shell_info)
{
    if (command->nb_args >= 4) {
        mprintf("setenv: Too many arguments.\n");
        shell_info->status = 1;
        return;
    }
    if (command->arg[0] != NULL && command->arg[1] == NULL) {
        display_list(shell_info->env_list, display_env_variable);
        return;
    }
    if (!setenv_ckeck_arg(command, shell_info)) {
        shell_info->status = 1;
        return;
    } else
        setenv_an_arg(command, shell_info);
    return;
}
