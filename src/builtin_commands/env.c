/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** env
*/

#include "../../include/my.h"

void env_command(command_t *command, shell_info_t *shell_info)
{
    if (command->arg[1] != NULL) {
        mprintf("env: '%s': %s\n", command->arg[1], strerror(ENOENT));
        shell_info->status = 127;
        return;
    } else
        display_list(shell_info->env_list, display_env_variable);
}
