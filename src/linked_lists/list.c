/*
** EPITECH PROJECT, 2023
** organized
** File description:
** list
*/

#include "../../include/my.h"

void push_to_list_tail(list_t *list, void *data)
{
    node_t *new_node = create_node(data);

    if (new_node == NULL)
        return;
    add_node(list, new_node);
}

bool replace_in_list(list_t *list, env_variable_t *env_variable,
    bool(*compare_data)())
{
    node_t *current = NULL;
    env_variable_t *ev = NULL;

    if (list == NULL || compare_data == NULL)
        return false;
    current = list->first;
    while (current != NULL) {
        ev = current->data;
        if (compare_data(ev->name, env_variable->name)) {
            ev = env_variable;
            current->data = ev;
            return true;
        }
        current = current->next;
    }
    return false;
}

void display_list(list_t *list, void(*display_data)())
{
    node_t *node = NULL;

    if (display_data == NULL)
        return;
    node = list->first;
    while (node != NULL) {
        display_data(node->data);
        node = node->next;
    }
}

bool delete_in_list(list_t *list, void const *ref, bool(*compare_data)(),
    void(*destroy_data)())
{
    node_t *current = NULL;
    node_t *prev = NULL;

    if (list == NULL || compare_data == NULL)
        return false;
    current = list->first;
    while (current != NULL) {
        if (compare_data(current->data, ref)) {
            delete_node(list, prev, current, destroy_data);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

static char *check_path(env_variable_t *ev)
{
    if (ev->value == NULL)
        return " ";
    else
        return ev->value;
}

char *search_in_list(list_t *list, char *ref, bool(*compare_data)())
{
    node_t *current = NULL;
    env_variable_t *ev = NULL;

    if (list == NULL || compare_data == NULL)
        return NULL;
    current = list->first;
    while (current != NULL) {
        ev = current->data;
        if (compare_data(ev->name, ref))
            return check_path(ev);
        current = current->next;
    }
    return NULL;
}
