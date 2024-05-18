/*
** EPITECH PROJECT, 2024
** bsminishell
** File description:
** main
*/

#include "../include/my.h"

int main(int argc, char **argv, char **env)
{
    command_t *command = my_calloc(1, sizeof(command_t));
    shell_info_t *shell_info = my_calloc(1, sizeof(shell_info_t));

    if (argc != 1) {
        mprintf("Error: too many args.\n");
        return 84;
    }
    shell_info->env_list = array_to_linked_list(env);
    main_loop(command, shell_info);
    return 0;
}
