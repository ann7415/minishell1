/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_array_2_linked_list
*/

#include "../include/my.h"

list_t *array_to_linked_list(char **array)
{
    list_t *list = create_list();

    for (int i = 0; array[i] != NULL; i++) {
        push_to_list_tail(list, str_to_env_variable(array[i]));
    }
    return list;
}
