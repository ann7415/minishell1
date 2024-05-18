/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_check_setenv_arg
*/

#include "../../include/my.h"

bool is_arg_correct(char c)
{
    if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c != '_'))
        return false;
    return true;
}

bool my_isalnum(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9') || (c == '_'))
        return true;
    return false;
}

bool is_arg_correct2(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isalnum(str[i]))
            return false;
    }
    return true;
}
