/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** superior
*/

#include "../cmd.h"
#include "my_string.h"

int where_is_it(cmd_t *cmd, char c)
{
    if (!ARGS || ARGS[0] == '\0')
        return -1;
    for (int i = 0; ARGS[i]; i++)
        if (ARGS[i] == c && ARGS[i + 1] != c)
            return i;
    return -1;
}

bool is_superior(cmd_t *cmd)
{
    char *before = NULL;
    char *after = NULL;
    int pos = where_is_it(cmd, '>');

    if (pos != -1) {
        before = malloc(pos + 1);
        after = my_strdup(ARGS + pos + 1);
        my_strncpy(before, ARGS, pos);
        before[pos] = '\0';
        ARGS = my_strdup(before);
        RDIR = my_strdup(my_trim(after));
        free(before);
        free(after);
        return true;
    }
    return false;
}

void error_handler(cmd_t *cmd, int fd1, int fd2)
{
    close(fd1);
    if (fd2 != -1)
        close(fd2);
    cmd->status = 1;
}

static void create_file(cmd_t *cmd)
{
    int fd = open(RDIR, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int old_stdout = dup(STDOUT_FILENO);

    if (old_stdout == -1) {
        error_handler(cmd, fd, -1);
        return;
    }
    if (dup2(fd, STDOUT_FILENO) == -1) {
        error_handler(cmd, fd, old_stdout);
        return;
    }
    execute_cmd(cmd);
    if (dup2(old_stdout, STDOUT_FILENO) == -1)
        perror("dup2");
    close(fd);
    close(old_stdout);
}

/// @brief le truc qui fait ça > en gros l'output
/// @param cmd
void execute_superior(cmd_t *cmd)
{
    create_file(cmd);
    return;
}
