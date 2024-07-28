/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** read
*/

#include "read.h"
#include "my_string.h"

char *remove_tab(const char *input)
{
    char *output = my_strdup(input);

    for (int i = 0; output[i] != '\0'; i++)
        if (output[i] == '\t')
            output[i] = ' ';
    return output;
}

void read_line(cmd_t *cmd)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    LINE = NULL;
    NAME = NULL;
    ARGS = NULL;
    RDIR = NULL;
    nread = getline(&line, &len, stdin);
    check_ctr_d(nread, line, cmd);
    if (line[nread - 1] == '\n')
        line[nread - 1] = '\0';
    LINE = my_strdup(remove_tab(line));
    if (my_strcmp(LINE, "exit") == 0)
        cleanup_and_exit(cmd);
    free(line);
}
