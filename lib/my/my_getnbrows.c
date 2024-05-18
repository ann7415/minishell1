/*
** EPITECH PROJECT, 2024
** bsminishell
** File description:
** my_getnbrows
*/

int my_getnbrows(char **board)
{
    int cpt = 1;

    for (int i = 0; board[i] != '\0'; i++) {
        if (board[i] == '\n') {
            cpt++;
        }
    }
    return (cpt);
}
