/*
** EPITECH PROJECT, 2024
** PSU_minishell1_$2024
** File description:
** main_loop
*/

#include "../include/my.h"

void main_loop(command_t *command, shell_info_t *shell_info)
{
    size_t name_size = 0;
    char *name = NULL;

    shell_info->status = 0;
    while (1) {
        if (isatty(0))
            mprintf("➩ ");
        if (getline(&name, &name_size, stdin) == -1)
            exit(shell_info->status);
        if (name_size > 0 && name[name_size - 1] == '\n')
            name[name_size - 1] = '\0';
        command->name = my_strdup(name);
        parse_builtin(command, shell_info);
    }
}
