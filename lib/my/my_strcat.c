/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_strcat
*/

#include "../../include/my.h"

char *my_strcat(char *s1, char *s2)
{
    size_t len_s1 = my_strlen(s1);
    size_t len_s2 = my_strlen(s2);
    char *result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));

    my_strcpy(result, s1);
    my_strcpy(result + len_s1, s2);
    return result;
}
