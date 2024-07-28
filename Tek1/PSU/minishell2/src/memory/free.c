/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** free
*/

#include "minishell.h"

void free_new_env(char **new_env, int i)
{
    while (i) {
        i--;
        free(new_env[i]);
    }
    free(new_env);
}

void free_envi(cmd_t *cmd)
{
    if (cmd->env) {
        for (int i = 0; cmd->env[i]; i++)
            free(cmd->env[i]);
        free(cmd->env);
    }
}

void free_cmd(cmd_t *cmd)
{
    if (LINE) {
        free(LINE);
        LINE = NULL;
    }
}

void cleanup_and_exit(cmd_t *cmd)
{
    free_cmd(cmd);
    free_envi(cmd);
    exit(cmd->status);
}
