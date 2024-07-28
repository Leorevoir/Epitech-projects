/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** doublesup
*/

#include "../cmd.h"
#include "my_stdio.h"
#include "my_string.h"

int where_is_it_double(char *str, char c)
{
    if (!str || str[0] == '\0')
        return -1;
    for (int i = 0; str[i] && str[i + 1]; i++) {
        if (str[i] == c && str[i + 1] == c)
            return i;
    }
    return -1;
}

bool is_double_sup(cmd_t *cmd)
{
    char *before = NULL;
    char *after = NULL;
    int pos = where_is_it_double(ARGS, '>');

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

void double_sup(cmd_t *cmd)
{
    int fd = open(RDIR, O_WRONLY | O_CREAT | O_APPEND, 0666);
    int save_stdout = dup(STDOUT_FILENO);

    if (save_stdout == -1)
        return;
    if (dup2(fd, STDOUT_FILENO) == -1)
        return;
    execute_cmd(cmd);
    if (dup2(save_stdout, STDOUT_FILENO) == -1)
        return;
    close(fd);
    close(save_stdout);
}

void execute_double_sup(cmd_t *cmd)
{
    double_sup(cmd);
}
