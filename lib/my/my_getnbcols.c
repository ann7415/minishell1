/*
** EPITECH PROJECT, 2024
** bsminishell
** File description:
** my_getnbcols
*/

void comparaison(int maxcol, int currentcol)
{
    if (currentcol > maxcol) {
        maxcol = currentcol;
    }
}

int my_getnbcols(char **board)
{
    int maxcol = 0;
    int currentcol = 0;

    for (int i = 0; board[i] != '\0'; i++) {
        if (board[i] == '\n') {
            comparaison(maxcol, currentcol);
            currentcol = 0;
        } else {
            currentcol++;
        }
    }
    if (currentcol > maxcol) {
        maxcol = currentcol;
    }
    return (maxcol + 1);
}
