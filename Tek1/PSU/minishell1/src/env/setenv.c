/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** setenv
*/

#include "minishell.h"
#include "my_stdio.h"
#include "my_string.h"

char *create_env_entry(const char *key, const char *value)
{
    size_t key_len = my_strlen(key);
    size_t value_len = my_strlen(value);
    char *entry = malloc(key_len + value_len + 2);

    for (size_t j = 0; j < key_len; ++j)
        entry[j] = key[j];
    entry[key_len] = '=';
    for (size_t j = 0; j < value_len; ++j)
        entry[key_len + 1 + j] = value[j];
    entry[key_len + 1 + value_len] = '\0';
    return entry;
}

void update_var_env(char ***env, char *entry, size_t i, cmd_t *cmd)
{
    size_t size = sizeof(char *) * (i + 2);
    char **new_env = NULL;

    if (i > 0 && (*env)[i - 1]) {
        (*env)[i] = entry;
    } else {
        new_env = my_realloc(*env, size);
        if (!new_env) {
            free(entry);
            exit(cmd->status);
        }
        *env = new_env;
        (*env)[i] = entry;
        (*env)[i + 1] = NULL;
    }
}

size_t array_length(char **env)
{
    size_t i = 0;

    while (env[i])
        i++;
    return (i);
}

void set_env(cmd_t *cmd)
{
    const char *key = NULL;
    const char *value = NULL;
    char *entry = NULL;

    if (!cmd->arguments[0] || !cmd->arguments[1]) {
        my_printf("setenv: Incorrect number of arguments.\n");
        return;
    }
    key = cmd->arguments[0];
    value = cmd->arguments[1];
    entry = create_env_entry(key, value);
    for (size_t i = 0; cmd->env[i]; ++i) {
        if (!strncmp(cmd->env[i], key, my_strlen(key))
            && cmd->env[i][my_strlen(key)] == '=') {
            free(cmd->env[i]);
            cmd->env[i] = entry;
            return;
        }
    }
    update_var_env(&cmd->env, entry, array_length(cmd->env), cmd);
}
