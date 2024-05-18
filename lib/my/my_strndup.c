/*
** EPITECH PROJECT, 2024
** bsminishell
** File description:
** my_strndup
*/

#include "../../include/my.h"

char *my_strndup(const char *str, int n)
{
    int len = 0;
    char *dup = NULL;

    while (len < n && str[len] != '\0') {
        len++;
    }
    dup = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        dup[i] = str[i];
    }
    dup[len] = '\0';
    return dup;
}
