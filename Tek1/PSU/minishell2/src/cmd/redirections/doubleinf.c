/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** doubleinf
*/

#include "../cmd.h"
#include "my_stdio.h"
#include "my_string.h"

bool is_double_inf(cmd_t *cmd)
{
    char *before = NULL;
    char *after = NULL;
    int pos = where_is_it_double(ARGS, '<');

    if (pos != -1) {
        before = malloc(pos + 1);
        my_strncpy(before, ARGS, pos);
        before[pos] = '\0';
        after = my_strdup(ARGS + pos + 2);
        if (my_strlen(before) > 0)
            ARGS = my_strdup(before);
        else
            ARGS = NULL;
        RDIR = my_strdup(my_trim(after));
        free(before);
        free(after);
        return true;
    }
    return false;
}

void execute_double_inf(cmd_t *cmd)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int pipefd[2];

    pipe(pipefd);
    do {
        read = getline(&line, &len, stdin);
        if (my_strstr(line, RDIR) == line
            && line[my_strlen(RDIR)] == '\n')
            break;
        write(pipefd[1], line, read);
    } while (read != -1);
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    execute_cmd(cmd);
    if (line)
        free(line);
}
