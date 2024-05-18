/*
** EPITECH PROJECT, 2024
** PSU_minishell1_$2024
** File description:
** minishell
*/

#pragma once

#include "list.h"

typedef struct command_s {
    char *name;
    char **arg;
    int nb_args;
} command_t;

typedef struct shell_info_s {
    list_t *env_list;
    char **path;
    char *curr_pwd;
    char *old_pwd;
    int status;
} shell_info_t;

void main_loop(command_t *command, shell_info_t *shell_info);

//parsing
void parse_builtin(command_t *command, shell_info_t *shell_info);
void parse_command(command_t *command, shell_info_t *shell_info);

//execute
void execute(command_t *command, shell_info_t *shell_info);
bool execute_builtin(command_t *command, shell_info_t *shell_info);
void execute_command(command_t *command, shell_info_t *shell_info);

//built-in commands
void cd_command(command_t *command, shell_info_t *shell_info);
void cd_to_a_folder(command_t *command, shell_info_t *shell_info);
void cd_to_old_path(command_t *command, shell_info_t *shell_info);

void setenv_command(command_t *command, shell_info_t *shell_info);
void unsetenv_command(command_t *command, shell_info_t *shell_info);
void env_command(command_t *command, shell_info_t *shell_info);
void exit_command(command_t *command, shell_info_t *shell_info);
