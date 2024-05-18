/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_calloc
*/

#include "../../include/my.h"

void *my_memset(void *ptr, int value, int num_bytes)
{
    char *byte_ptr = (char *)ptr;

    for (int i = 0; i < num_bytes; i++)
        byte_ptr[i] = (char)value;
    return ptr;
}

void *my_calloc(size_t nb_elements, size_t size_element)
{
    int total_size = 0;
    void *ptr = NULL;

    if (nb_elements == 0 || size_element == 0)
        return NULL;
    total_size = nb_elements * size_element;
    ptr = malloc(total_size);
    if (ptr != NULL)
        my_memset(ptr, 0, total_size);
    return ptr;
}
