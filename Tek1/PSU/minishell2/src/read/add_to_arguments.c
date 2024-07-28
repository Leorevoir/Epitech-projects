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
        cleanup_and_exit(cmd);
    }
}
