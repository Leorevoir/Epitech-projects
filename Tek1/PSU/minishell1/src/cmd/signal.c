/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** signal
*/

#include "minishell.h"
#include "my_stdio.h"
#include "my_string.h"

void what_signal(int termsig, int status, cmd_t *cmd)
{
    if (termsig == SIGSEGV) {
        my_printf("Segmentation fault");
        cmd->status = 139;
        if (WCOREDUMP(status))
            my_printf(" (core dumped)");
        my_printf("\n");
    }
}

void check_segfault(int status, cmd_t *cmd)
{
    int termsig = 0;

    if (WIFSIGNALED(status)) {
        termsig = WTERMSIG(status);
        what_signal(termsig, status, cmd);
    }
}

void check_out(pid_t pid, int status, cmd_t *cmd)
{
    if (pid > 0) {
        waitpid(pid, &status, 0);
        check_segfault(status, cmd);
    } else {
        perror("fork");
        exit(cmd->status);
    }
}
