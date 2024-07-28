/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** inferior
*/

#include "../cmd.h"
#include "my_stdio.h"
#include "my_string.h"

bool is_inferior(cmd_t *cmd)
{
    char *before = NULL;
    char *after = NULL;
    int pos = where_is_it(cmd, '<');

    if (pos != -1) {
        before = malloc(pos + 1);
        after = my_strdup(ARGS + pos + 1);
        my_strncpy(before, ARGS, pos);
        before[pos] = '\0';
        if (before[0] != '\0') {
            ARGS = my_strdup(before);
        } else
            ARGS = NULL;
        RDIR = my_strdup(my_trim(after));
        free(before);
        free(after);
        return true;
    }
    return false;
}

void what_file_0_o(cmd_t *cmd)
{
    int fd = open(RDIR, O_RDONLY);
    int save_stdin = dup(STDIN_FILENO);

    if (fd == -1) {
        my_printf("%s: No such file or directory.\n", RDIR);
        error_handler(cmd, fd, -1);
        return;
    }
    if (save_stdin == -1) {
        error_handler(cmd, fd, -1);
        return;
    }
    if (dup2(fd, STDIN_FILENO) == -1) {
        return;
    }
    execute_cmd(cmd);
    if (dup2(save_stdin, STDIN_FILENO) == -1)
        perror("dup2");
    close(fd);
    close(save_stdin);
}

/// @brief le truc qui fait ça < en gros l'input
/// @param cmd
void execute_inferior(cmd_t *cmd)
{
    what_file_0_o(cmd);
    return;
}
