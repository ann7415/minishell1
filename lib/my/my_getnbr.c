/*
** EPITECH PROJECT, 2023
** setting_up542
** File description:
** my_getnbr
*/

int my_getnbr(char *str)
{
    int nb = 0;
    int k = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            k = k * -1;
        }
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10 + (str[i] - '0');
            i = i + 1;
        } else {
            break;
        }
    }
    return (nb * k);
}
