/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_check_malloc
*/

#include "../../include/my.h"

void my_check_malloc_arr(char **array)
{
    if (array == NULL) {
        mprintf("Error: unsuccessful malloc\n");
        return;
    }
}

void my_check_malloc_str(char *str)
{
    if (str == NULL) {
        mprintf("Error: unsuccessful malloc\n");
        return;
    }
}
