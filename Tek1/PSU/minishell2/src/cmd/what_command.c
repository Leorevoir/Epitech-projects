/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** what_command
*/

#include "cmd.h"
#include "my_stdio.h"
#include "my_string.h"

void what_command(cmd_t *cmd)
{
    for (int i = 0; commands[i].name != NULL; i++) {
        if (my_strcmp(cmd->name, commands[i].name) == 0) {
            commands[i].handler(cmd);
            return;
        }
    }
    if (my_strcmp(cmd->name, "echo") == 0 && cmd->arguments
        && my_strcmp(cmd->arguments, "$?") == 0)
        my_printf("%d\n", cmd->status);
    else
        execute_cmd(cmd);
}
