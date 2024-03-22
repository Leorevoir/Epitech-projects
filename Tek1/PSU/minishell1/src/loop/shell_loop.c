/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** shell_loop
*/

#include "minishell.h"
#include "my_stdio.h"

void free_envi(cmd_t *cmd)
{
    for (int i = 0; cmd->env[i]; i++)
        free(cmd->env[i]);
    free(cmd->env);
}

int shell_loop(char **env)
{
    char **env_copy = duplicate_environment(env);
    cmd_t cmd = {.env = env_copy, .status = 0};

    signal(SIGINT, handle_sigint);
    while (1) {
        my_printf("$> ");
        read_line(&cmd);
        if (cmd.name == NULL || is_only_spaces(cmd.name))
            continue;
        check_exit(cmd.name, &cmd);
        process_command(&cmd);
        free_cmd(cmd);
    }
    free_envi(&cmd);
    return cmd.status;
}
