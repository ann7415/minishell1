/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** task02
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
