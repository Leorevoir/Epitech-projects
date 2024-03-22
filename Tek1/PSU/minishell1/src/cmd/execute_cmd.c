/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** execute_cmd
*/

#include "cmd.h"
#include "my_string.h"
#include "my_stdio.h"

static void execute_child_process(cmd_t *cmd, const char *path, char **args,
    char **env)
{
    args[0] = cmd->name;
    if (execve(path, args, env) == -1) {
        perror(cmd->name);
        cmd->status = 1;
    }
}

static void wait_for_child_process(pid_t pid, cmd_t *cmd)
{
    int status = 0;

    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
        cmd->status = WEXITSTATUS(status);
    } else if (WIFSIGNALED(status)) {
        check_segfault(status, cmd);
    }
}

void execute_cmd(cmd_t *cmd)
{
    char *full_path = check_execute(cmd);
    char **args = NULL;
    int arg_count = 0;
    pid_t pid;

    if (!full_path) {
        cmd->status = 127;
        return;
    }
    args = prepare_args(cmd, full_path, &arg_count);
    pid = fork();
    if (pid == 0) {
        execute_child_process(cmd, full_path, args, cmd->env);
    } else if (pid < 0) {
        perror("fork");
        cmd->status = ERROR;
    } else
        wait_for_child_process(pid, cmd);
    free(full_path);
    free_args(args, arg_count);
}
