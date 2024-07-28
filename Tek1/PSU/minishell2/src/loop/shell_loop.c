/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** shell_loop
*/

#include "minishell.h"
#include "my_stdio.h"

bool is_line_empty_or_tabs(const char *line)
{
    if (line == NULL)
        return true;
    while (*line) {
        if (!my_isspace((unsigned char)*line) || *line == '\n')
            return false;
        line++;
    }
    return true;
}

int shell_loop(char **env)
{
    cmd_t cmd = {0};

    cmd.env = duplicate_environment(env);
    signal(SIGINT, handle_sigint);
    while (1) {
        my_printf("\033[03;33m$>\033[00m ");
        read_line(&cmd);
        if (is_line_empty_or_tabs(cmd.line)) {
            free_cmd(&cmd);
            continue;
        }
        process_command(&cmd);
        free_cmd(&cmd);
    }
    free_envi(&cmd);
    return cmd.status;
}
