/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** free
*/

#include "minishell.h"

void free_args(char **args, int count)
{
    if (args != NULL) {
        for (int j = 1; j <= count; j++) {
            free(args[j]);
            args[j] = NULL;
        }
        free(args);
    }
}

void free_cmd(cmd_t cmd)
{
    if (cmd.arguments != NULL) {
        free_args(cmd.arguments, 0);
    }
    if (cmd.name != NULL) {
        free(cmd.name);
    }
}

void free_new_env(char **new_env, int i)
{
    while (i) {
        i--;
        free(new_env[i]);
    }
    free(new_env);
}
