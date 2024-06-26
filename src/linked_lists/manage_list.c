/*
** EPITECH PROJECT, 2023
** organized
** File description:
** manage_list
*/

#include "../../include/my.h"

list_t *create_list(void)
{
    list_t *list = my_calloc(1, sizeof(list_t));

    if (list == NULL)
        return NULL;
    list->first = NULL;
    return (list);
}

void destroy_list(list_t *list, void(*destroy_data)())
{
    node_t *current = NULL;
    node_t *next = NULL;

    if (list == NULL)
        return;
    current = list->first;
    while (current != NULL) {
        next = current->next;
        destroy_node(current, destroy_data);
        current = next;
    }
    free(list);
}
