/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_count_char
*/

#include "../../include/my.h"

int my_count_char(char *paths)
{
    int nb_paths = 0;

    if (paths == NULL)
        return 0;
    for (int i = 0; paths[i] != '\0'; i++) {
        if (paths[i] == ':')
            nb_paths++;
    }
    return nb_paths;
}
