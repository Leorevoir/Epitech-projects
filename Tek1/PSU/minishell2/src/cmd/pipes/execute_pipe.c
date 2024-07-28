/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** execute_pipe
*/

#include "../cmd.h"
#include "my_stdio.h"
#include "my_string.h"

static void execute_pipe_cmd(char *full_path, char **exec_args, cmd_t *cmd)
{
    if (execve(full_path, exec_args, cmd->env) == -1) {
        perror(NAME);
        free(full_path);
        cmd->status = 1;
        return;
    }
}

void check_execute_path(cmd_t *cmd, char *exec_args[5012], int i, pipe_t *PIPE)
{
    char *full_path = NULL;

    if (is_executable(exec_args[0])) {
        full_path = my_strdup(exec_args[0]);
    } else
        full_path = resolve_command_path(exec_args[0], cmd);
    if (full_path != NULL) {
        if (i < PIPE->num - 1)
            dup2(PIPE->FD[1], STDOUT_FILENO);
        execute_pipe_cmd(full_path, exec_args, cmd);
        free(full_path);
        if (i < PIPE->num - 1) {
            close(PIPE->FD[1]);
        }
        exit(cmd->status);
    } else {
        perror(exec_args[0]);
        cmd->status = 1;
        exit(cmd->status);
    }
}

void execute_pipe_command(cmd_t *cmd, int i, pipe_t *PIPE)
{
    char *exec_args[5012];

    split_command(PIPE->command[i], exec_args);
    NAME = exec_args[0];
    ARGS = exec_args[1];
    if (is_builtin_command(exec_args[0])) {
        if (i < PIPE->num - 1)
            dup2(PIPE->FD[1], STDOUT_FILENO);
        what_command(cmd);
        if (i < PIPE->num - 1)
            close(PIPE->FD[1]);
        exit(cmd->status);
    } else {
        check_execute_path(cmd, exec_args, i, PIPE);
    }
}

void execute_pipeline(cmd_t *cmd, char **commands, int num)
{
    int in_fd = 0;
    pid_t pid;
    pipe_t PIPE = init_my_pipe(commands, num);

    for (int i = 0; i < PIPE.num; i++) {
        if (i < PIPE.num - 1)
            pipe(PIPE.FD);
        pid = fork();
        if (pid == 0) {
            setup_io_for_pipe(in_fd, &PIPE, i);
            execute_pipe_command(cmd, i, &PIPE);
        }
        if (in_fd != 0)
            close(in_fd);
        if (i < PIPE.num - 1) {
            close(PIPE.FD[1]);
            in_fd = PIPE.FD[0];
        }
    }
    while (wait(NULL) > 0);
}
