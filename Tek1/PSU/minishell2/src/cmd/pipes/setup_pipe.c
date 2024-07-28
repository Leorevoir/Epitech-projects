/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** setup_pipe
*/

#include "../cmd.h"
#include "my_string.h"

bool is_builtin_command(const char *command)
{
    for (int i = 0; commands[i].name != NULL; i++)
        if (my_strcmp(command, commands[i].name) == 0)
            return true;
    return false;
}

void split_command(char *command, char **exec_args)
{
    int arg_index = 1;

    exec_args[0] = strtok(command, " ");
    exec_args[arg_index] = strtok(NULL, " ");
    while (exec_args[arg_index] != NULL) {
        arg_index++;
        exec_args[arg_index] = strtok(NULL, " ");
    }
}

void setup_io_for_pipe(int in_fd, pipe_t *PIPE, int i)
{
    if (in_fd != 0) {
        dup2(in_fd, STDIN_FILENO);
        close(in_fd);
    }
    if (i < PIPE->num - 1) {
        close(PIPE->FD[0]);
        dup2(PIPE->FD[1], STDOUT_FILENO);
    }
}

pipe_t init_my_pipe(char **commands, int num)
{
    pipe_t PIPE = {0};

    PIPE.command = commands;
    PIPE.num = num;
    return PIPE;
}
