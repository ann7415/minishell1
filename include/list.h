/*
** EPITECH PROJECT, 2023
** organized
** File description:
** list
*/

#pragma once

#include "node.h"
#include "env_variable.h"

typedef struct list_s {
    node_t *first;
} list_t;

list_t *create_list(void);
void destroy_list(list_t *list, void(*destroy_data)());

void push_to_list_tail(list_t *list, void *data);
void add_node(list_t *list, node_t *new_node);
bool delete_in_list(list_t *list, void const *ref, bool(*compare_data)(),
    void(*destroy_data)());
char *search_in_list(list_t *list, char *ref, bool(*compare_data)());
void delete_node(list_t *list, node_t *prev, node_t *current,
    void(*destroy_data)());

void display_list(list_t *list, void(*display_data)());
int linked_list_len(list_t *list);

list_t *array_to_linked_list(char **array);
char **linked_list_to_array(list_t *list);

bool replace_in_list(list_t *list, env_variable_t *env_variable,
    bool(*compare_data)());
list_t *reverse_list(list_t *list);
