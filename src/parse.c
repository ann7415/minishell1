/*
** EPITECH PROJECT, 2024
** PSU_minishell1_$2024
** File description:
** parse
*/

#include "../include/my.h"

void parse_command(command_t *command, shell_info_t *shell_info)
{
    char *paths = NULL;
    char *one_path = NULL;
    int n = 0;

    if (search_in_list(shell_info->env_list, "PATH", my_strcmp) != NULL)
        paths = my_strdup(search_in_list(shell_info->env_list,
            "PATH", my_strcmp));
    if (paths == NULL)
        paths = my_strdup("/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin");
    one_path = strtok(paths, ":");
    shell_info->path = malloc((my_count_char(paths) + 1) * sizeof(char *));
    my_check_malloc_arr(shell_info->path);
    while (one_path != NULL) {
        shell_info->path[n] = malloc(sizeof(char) * (my_strlen(one_path) + 1));
        my_check_malloc_str(shell_info->path[n]);
        my_strcpy(shell_info->path[n], one_path);
        n++;
        one_path = strtok(NULL, ":");
    }
    shell_info->path[n] = NULL;
}

void parse_builtin(command_t *command, shell_info_t *shell_info)
{
    char *str = strtok(my_strdup(command->name), " \t\n");
    int n = 0;
    int nb_args = 0;

    while (str != NULL) {
        nb_args++;
        str = strtok(NULL, " \t\n");
    }
    command->arg = malloc((nb_args + 1) * sizeof(char *));
    str = strtok(my_strdup(command->name), " \t\n");
    while (str != NULL) {
        command->arg[n] = malloc(sizeof(char) * (my_strlen(str) + 1));
        my_check_malloc_str(command->arg[n]);
        my_strcpy(command->arg[n], str);
        n++;
        str = strtok(NULL, " \t\n");
    }
    command->arg[n] = NULL;
    command->nb_args = n;
    execute(command, shell_info);
}
