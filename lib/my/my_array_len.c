/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_arraylen
*/

#include "../../include/my.h"

int my_arraylen(char **array)
{
    int len = 0;

    while (array[len] != NULL) {
        len++;
    }
    return len;
}
