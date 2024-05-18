/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** manage_env_variable
*/

#include "../../include/my.h"

env_variable_t *create_env_variable(char *name, char *value)
{
    env_variable_t *env_variable = my_calloc(1, sizeof(env_variable_t));

    if (!env_variable) {
        mprintf("Error: unsuccessful calloc\n");
        return NULL;
    }
    env_variable->name = my_strdup(name);
    if (value == NULL) {
        env_variable->value = NULL;
        return env_variable;
    }
    env_variable->value = my_strdup(value);
    return env_variable;
}

void destroy_env_variable(env_variable_t *env_variable)
{
    free(env_variable->name);
    free(env_variable->value);
    free(env_variable);
}

list_t *reverse_list(list_t *list)
{
    list_t *reversed_list = create_list();
    node_t *current = list->first;
    node_t *new_node = NULL;

    while (current != NULL) {
        new_node = create_node(current->data);
        new_node->next = reversed_list->first;
        reversed_list->first = new_node;
        current = current->next;
    }
    return reversed_list;
}

bool compare_env_variable(env_variable_t *env_variable, char *name)
{
    return my_strcmp(env_variable->name, name);
}

void display_env_variable(env_variable_t *env_variable)
{
    if (env_variable->value == NULL)
        mprintf("%s=\n", env_variable->name);
    else
        mprintf("%s=%s\n", env_variable->name, env_variable->value);
}
