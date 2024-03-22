/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** process_cmd
*/

#include "my_string.h"
#include "my_stdio.h"
#include "cmd.h"

char **prepare_args(cmd_t *cmd, char *full_path, int *arg_count)
{
    char **args;
    int i;

    for (*arg_count = 0; cmd->arguments[*arg_count] != NULL; (*arg_count)++);
    args = malloc((*arg_count + 2) * sizeof(char *));
    if (args == NULL) {
        exit(cmd->status);
    }
    args[0] = full_path;
    for (i = 0; i < *arg_count; i++)
        args[i + 1] = cmd->arguments[i];
    args[*arg_count + 1] = NULL;
    return args;
}

void process_command(cmd_t *cmd)
{
    for (int i = 0; commands[i].name != NULL; i++) {
        if (my_strcmp(cmd->name, commands[i].name) == 0) {
            commands[i].handler(cmd);
            return;
        }
    }
    if (my_strcmp(cmd->name, "echo") == 0 && cmd->arguments[0]
        && my_strcmp(cmd->arguments[0], "$?") == 0)
        my_printf("%d\n", cmd->status);
    else
        execute_cmd(cmd);
}
