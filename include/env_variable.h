/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** env_variable
*/

#pragma once

#include "list.h"

typedef struct env_variable_s {
    char *name;
    char *value;
}env_variable_t;

env_variable_t *create_env_variable(char *name, char *value);
void destroy_env_variable(env_variable_t *env_variable);

env_variable_t *str_to_env_variable(char *str);
char *env_variable_to_str(env_variable_t *env_variable);

void display_env_variable(env_variable_t *env_variable);
bool compare_env_variable(env_variable_t *env_variable, char *name);

char *copy_value(char *value, int len_value, char *str, int k);
char *copy_name(char *name, int len_name, char *str);

char *copy_name(char *name, int len_name, char *str);
char *copy_value(char *value, int len_value, char *str, int k);
