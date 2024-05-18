/*
** EPITECH PROJECT, 2023
** organized
** File description:
** my_strcmp
*/

#include "../../include/my.h"

bool my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') {
            return true;
        }
        i++;
    }
    return false;
}
