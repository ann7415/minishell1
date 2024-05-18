/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** nb_slash
*/

int nb_slash(char *path)
{
    int nb = 0;

    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == '/')
            nb++;
    }
    return nb;
}
