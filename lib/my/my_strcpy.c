/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char *src)
{
    int n = 0;

    for (; src[n] != '\0'; n++) {
        dest[n] = src[n];
    }
    dest[n] = '\0';
    return (dest);
}
