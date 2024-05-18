/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_linked_list_2_array
*/

#include "../include/my.h"

char **linked_list_to_array(list_t *list)
{
    int len_list = linked_list_len(list);
    char **array = my_calloc(len_list, sizeof(char *));
    node_t *node = NULL;
    int i = 0;

    if (list->first == NULL)
        return NULL;
    node = list->first;
    while (node != NULL) {
        array[i] = env_variable_to_str(node->data);
        node = node->next;
        i++;
    }
    array[len_list] = NULL;
    return array;
}
