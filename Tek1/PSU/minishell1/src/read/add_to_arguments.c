/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** add_to_arguments
*/

#include "read.h"
#include "my_stdio.h"
#include "my_string.h"

void check_ctr_d(ssize_t nread, char *line, cmd_t *cmd)
{
    if (nread == -1) {
        my_printf("exit\n");
        free(line);
        exit(cmd->status);
    }
}

void add_to_arguments(cmd_t *cmd, int arg_count)
{
    char *token = strtok(NULL, " ");
    size_t size = 0;

    while (token != NULL) {
        size = sizeof(char *) * (arg_count + 2);
        cmd->arguments = my_realloc(cmd->arguments, size);
        if (cmd->arguments == NULL) {
            exit(cmd->status);
        }
        cmd->arguments[arg_count] = my_strdup(token);
        arg_count++;
        cmd->arguments[arg_count] = NULL;
        token = strtok(NULL, " ");
    }
}
