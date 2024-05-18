/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** exit
*/

#include "../../include/my.h"

void exit_command(command_t *command, shell_info_t *shell_info)
{
    mprintf("exit\n");
    exit(shell_info->status);
}
