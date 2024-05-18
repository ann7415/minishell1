/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_realloc
*/

#include "../../include/my.h"

static void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

char **my_realloc(char **array, int size)
{
    int len = 0;
    char **new_array = NULL;

    if (array == NULL)
        return malloc(size);
    if (size == 0) {
        free(array);
        return NULL;
    }
    len = my_arraylen(array);
    new_array = malloc(sizeof(char *) * (len + size + 1));
    for (int i = 0; i < len; i++) {
        new_array[i] = my_strdup(array[i]);
    }
    free_array(array);
    new_array[len + size] = NULL;
    return new_array;
}
