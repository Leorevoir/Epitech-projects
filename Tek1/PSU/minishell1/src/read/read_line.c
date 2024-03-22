/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** read
*/

#include "read.h"
#include "my_string.h"
#include "my_stdio.h"

void read_line(cmd_t *cmd)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token;
    int arg_count = 0;

    nread = getline(&line, &len, stdin);
    check_ctr_d(nread, line, cmd);
    if (line[nread - 1] == '\n')
        line[nread - 1] = '\0';
    token = strtok(line, " ");
    cmd->name = my_strdup(token);
    cmd->arguments = malloc(sizeof(char *) * (arg_count + 1));
    if (cmd->arguments == NULL) {
        exit(cmd->status);
    }
    cmd->arguments[arg_count] = NULL;
    add_to_arguments(cmd, arg_count);
    free(line);
}
