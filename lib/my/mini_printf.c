/*
** EPITECH PROJECT, 2024
** LIB
** File description:
** mini_printf
*/

#include "../../include/my.h"

void flags(va_list args, char flag)
{
    if (flag == 'd' || flag == 'i')
        my_put_nbr(va_arg(args, int));
    if (flag == 's')
        my_putstr(va_arg(args, char *));
    if (flag == 'c')
        my_putchar(va_arg(args, int));
    if (flag == '%')
        my_putchar('%');
}

int mprintf(const char *format, ...)
{
    int len = 0;
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            flags(args, format[i]);
        } else {
            my_putchar(format[i]);
        }
        len++;
    }
    va_end(args);
    return len;
}
