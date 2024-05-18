/*
** EPITECH PROJECT, 2023
** organized
** File description:
** node
*/

#pragma once

typedef struct node_s {
    void *data;
    struct node_s *next;
    struct node_s *prev;
} node_t;

node_t *create_node(void *data);
void destroy_node(node_t *node, void(*destroy_data)());
