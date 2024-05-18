/*
** EPITECH PROJECT, 2024
** LIB
** File description:
** my
*/

#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

#include "execute.h"

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
bool my_strcmp(char *s1, char *s2);
int my_strlen(char const *str);
char *my_strdup(char *str);
int my_getnbr(char *str);
int mprintf(const char *format, ...);
char *my_strndup(const char *str, int n);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, int n);
char *my_strcat(char *s1, char *s2);
char **my_realloc(char **path, int size);
int my_arraylen(char **array);
int linked_list_len(list_t *list);
int my_count_char(char *paths);
void my_check_malloc_arr(char **array);
void my_check_malloc_str(char *str);
bool is_arg_correct(char c);
bool is_arg_correct2(char *str);
bool my_isalnum(char c);
char *retrieve_str(char *path);
void *my_calloc(size_t num_elements, size_t element_size);
int nb_slash(char *path);
