/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** process_cmd
*/

#include "my_string.h"
#include "my_stdio.h"
#include "cmd.h"

void process_redirections(cmd_t *cmd)
{
    if (is_double_sup(cmd)) {
        execute_double_sup(cmd);
        return;
    }
    if (is_double_inf(cmd)) {
        execute_double_inf(cmd);
        return;
    }
    if (is_superior(cmd)) {
        execute_superior(cmd);
        return;
    }
    if (is_inferior(cmd)) {
        execute_inferior(cmd);
        return;
    }
    what_command(cmd);
}

void process_pipes(cmd_t *cmd, char *token)
{
    char *pipe_segments[256];
    int num_segments = 0;
    char *pipe_saveptr = NULL;
    char *segment = strtok_r(token, "|", &pipe_saveptr);

    while (segment != NULL) {
        pipe_segments[num_segments] = segment;
        num_segments = num_segments + 1;
        segment = strtok_r(NULL, "|", &pipe_saveptr);
    }
    if (num_segments > 0) {
        execute_pipeline(cmd, pipe_segments, num_segments);
    }
}

void process_command(cmd_t *cmd)
{
    char *token = NULL;
    char *next_token = NULL;
    char *saveptr = NULL;
    int has_pipe = 0;

    if (my_strstr(LINE, "|")) {
        has_pipe = 1;
    }
    token = strtok_r(LINE, ";", &saveptr);
    while (token != NULL) {
        next_token = saveptr;
        if (has_pipe) {
            process_pipes(cmd, token);
        } else {
            NAME = strtok(token, " ");
            ARGS = strtok(NULL, "");
            process_redirections(cmd);
        }
        token = strtok_r(next_token, ";", &saveptr);
    }
}
