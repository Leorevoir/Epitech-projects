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
    const char *real_name = path;
    char *bin_slash = NULL;

    if (args == NULL) {
        args = malloc(2 * sizeof(char *));
        args[0] = (char *)NAME;
        args[1] = NULL;
    }
    for (const char *p = path; *p; p++)
        if (*p == '/')
            bin_slash = (char *)p;
    if (bin_slash != NULL)
        real_name = bin_slash + 1;
    args[0] = (char *)real_name;
    if (execve(path, args, env) == -1) {
        perror(real_name);
        cmd->status = 1;
    }
    free_word_array(args);
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

char **prepare_args(char *arguments, char *full_path)
{
    char **args = NULL;
    char **tmp = NULL;
    int arg_count = 0;
    int i;

    if (arguments == NULL)
        return NULL;
    tmp = my_str_to_word_array(arguments);
    for (arg_count = 0; tmp[arg_count] != NULL; (arg_count)++);
    args = malloc((arg_count + 2) * sizeof(char *));
    args[0] = full_path;
    for (i = 0; i < arg_count; i++)
        args[i + 1] = tmp[i];
    args[arg_count + 1] = NULL;
    return args;
}

void execute_cmd(cmd_t *cmd)
{
    char *full_path = check_execute(cmd);
    char **arguments = NULL;
    pid_t pid;

    if (!full_path) {
        cmd->status = 127;
        return;
    }
    arguments = prepare_args(cmd->arguments, full_path);
    pid = fork();
    if (pid == 0) {
        execute_child_process(cmd, full_path, arguments, cmd->env);
    } else if (pid < 0) {
        perror("fork");
        cmd->status = ERROR;
    } else
        wait_for_child_process(pid, cmd);
    free(full_path);
}
