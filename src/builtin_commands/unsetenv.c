/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** unsetenv
*/

#include "../../include/my.h"

void unsetenv_command(command_t *command, shell_info_t *shell_info)
{
    if (command->arg[1] == NULL) {
        mprintf("unsetenv: Too few arguments.\n");
        shell_info->status = 1;
        return;
    } else {
        for (int i = 0; command->arg[i] != NULL; i++) {
            delete_in_list(shell_info->env_list, command->arg[i],
                compare_env_variable, destroy_env_variable);
        }
    }
}
