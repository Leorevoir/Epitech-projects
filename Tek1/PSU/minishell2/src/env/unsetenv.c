/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** unsetenv
*/

#include "env.h"
#include "my_string.h"
#include "my_stdio.h"

void move_entries(cmd_t *cmd, int i)
{
    for (size_t j = i; cmd->env[j]; ++j)
        cmd->env[j] = cmd->env[j + 1];
}

int parse_environment(cmd_t *cmd, char **args)
{
    const char *key = args[0];
    size_t key_len = my_strlen(key);
    int found = 0;

    for (size_t i = 0; cmd->env[i]; ++i) {
        if (!my_strncmp(cmd->env[i], key, key_len)
            && cmd->env[i][key_len] == '=') {
            found = 1;
            free(cmd->env[i]);
            move_entries(cmd, i);
            break;
        }
    }
    return found;
}

void unset_env(cmd_t *cmd)
{
    char **args = NULL;
    int found = 0;

    args = my_str_to_word_array(cmd->arguments);
    if (!cmd->arguments || args == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        cmd->status = 1;
        return;
    }
    found = parse_environment(cmd, args);
    if (!found)
        return;
    cmd->status = 0;
}
