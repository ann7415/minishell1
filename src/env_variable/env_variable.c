/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** env_variable
*/

#include "../../include/my.h"

char *copy_name(char *name, int len_name, char *str)
{
    name = malloc(sizeof(char) * (len_name));
    for (int j = 0; str[j] != '='; j++) {
        name[j] = str[j];
    }
    name[len_name - 1] = '\0';
    return name;
}

char *copy_value(char *value, int len_value, char *str, int k)
{
    value = malloc(sizeof(char) * (len_value + 1));
    if (len_value != 0) {
        for (int j = 0; str[k] != '\0'; j++) {
            value[j] = str[k];
            k++;
        }
        value[len_value] = '\0';
    } else {
        free(value);
        value = "";
    }
    return value;
}

env_variable_t *str_to_env_variable(char *str)
{
    char *name = NULL;
    char *value = NULL;
    int len_name = 0;
    int len_value = 0;
    int k = 0;

    while (str[len_name] != '=' && str[len_name] != '\0')
        len_name++;
    if (str[len_name] != '=')
        return NULL;
    len_name++;
    k = len_name;
    while (str[len_name] != '\0') {
        len_value++;
        len_name++;
    }
    name = copy_name(name, len_name, str);
    value = copy_value(value, len_value, str, k);
    return create_env_variable(name, value);
}

char *env_variable_to_str(env_variable_t *env_variable)
{
    char *name = env_variable->name;
    char *value = env_variable->value;
    char *res = my_strcat(my_strcat(name, "="), value);

    return res;
}
