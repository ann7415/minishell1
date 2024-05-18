/*
** EPITECH PROJECT, 2023
** organized
** File description:
** my_strdup
*/

#include "../../include/my.h"

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *res = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i <= len; i++) {
        res[i] = str[i];
    }
    return (res);
}
