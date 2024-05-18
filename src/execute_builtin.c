/*
** EPITECH PROJECT, 2024
** PSU_minishell1_$2024
** File description:
** execute_builtin
*/

#include "../include/my.h"

char *builtin_commands[] = {"cd", "setenv", "unsetenv", "env", "exit"};
void (*builtin_fct[5])(command_t *, shell_info_t *) = {
    &cd_command, &setenv_command, &unsetenv_command,
    &env_command, &exit_command};

bool execute_builtin(command_t *command, shell_info_t *shell_info)
{
    if (command->arg[0] == NULL)
        return true;
    for (int i = 0; i < 5; i++) {
        if (my_strcmp(command->arg[0], builtin_commands[i])) {
            builtin_fct[i](command, shell_info);
            return true;
        }
    }
    return false;
}

void execute(command_t *command, shell_info_t *shell_info)
{
    if (!execute_builtin(command, shell_info)) {
        parse_command(command, shell_info);
        execute_command(command, shell_info);
        return;
    }
}
