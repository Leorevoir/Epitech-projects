/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** cd
*/

#include "my_string.h"
#include "my_stdio.h"
#include "minishell.h"

static char *parse_cd_arg(const char *buffer)
{
    char *arg = NULL;
    int i = 0;

    if (!buffer)
        return my_strdup("~");
    while (buffer[i] == ' ')
        i++;
    if (buffer[i] == '\0' || buffer[i] == '\n')
        return my_strdup("~");
    arg = my_strdup(&buffer[i]);
    if (my_strrchr(arg, ' ')) {
        free(arg);
        my_printf("cd: Too many arguments.\n");
        return NULL;
    }
    return arg;
}

static void go_home(const char *home)
{
    if (home) {
        if (chdir(home) != 0)
            perror("chdir to home failed");
    } else
        my_printf("HOME variable not set.\n");
}

void my_cd(cmd_t *cmd)
{
    const char *home = my_getenv(cmd->env, "HOME");
    char *arg = parse_cd_arg(cmd->arguments[0]);

    if (cmd->arguments[1]) {
        my_printf("cd: Too many arguments.\n");
        cmd->status = 1;
        free(arg);
        return;
    }
    if (my_strcmp(arg, "~") == 0)
        go_home(home);
    else if (chdir(arg) == -1)
        perror(arg);
    free(arg);
}
