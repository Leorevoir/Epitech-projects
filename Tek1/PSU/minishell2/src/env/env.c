/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** env
*/

#include "minishell.h"
#include "my_stdio.h"

void my_env(cmd_t *cmd)
{
    if (!cmd->env)
        return;
    for (int i = 0; cmd->env[i] != NULL; i++)
        my_printf("%s\n", cmd->env[i]);
    cmd->status = 0;
}
