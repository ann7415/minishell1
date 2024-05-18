/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_retrieve_str
*/


#include "../../include/my.h"

char *retrieve_str(char *path)
{
    int len = my_strlen(path);
    char *res;
    int j = 0;

    if (len > 0 && (path[len - 1] == '/' || path[len - 1] == '\\'))
        len--;
    for (j = len - 1; j >= 0; j--) {
        if (path[j] == '/' || path[j] == '\\')
            break;
    }
    res = (char *)malloc(sizeof(char) * len - j);
    my_strncpy(res, path + j + 1, len - j - 1);
    res[len - j - 1] = '\0';
    return res;
}
