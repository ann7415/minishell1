/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char *src, int n)
{
    char *dest_start = dest;

    while (n > 0 && *src != '\0') {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';
    return dest_start;
}
