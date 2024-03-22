/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** getenv
*/

#include "my_string.h"
#include "minishell.h"

char **duplicate_environment(char **env)
{
    char **new_env = NULL;
    int count = 0;

    for (; env[count]; count++);
    new_env = malloc((count + 1) * sizeof(char *));
    if (!new_env) {
        exit(ERROR);
    }
    for (int i = 0; i < count; i++) {
        new_env[i] = my_strdup(env[i]);
        if (!new_env[i]) {
            free_new_env(new_env, i);
            exit(ERROR);
        }
    }
    new_env[count] = NULL;
    return new_env;
}

char *my_getenv(char **env, const char *name)
{
    size_t name_len = 0;

    if (!name || !env)
        return NULL;
    name_len = my_strlen(name);
    for (int i = 0; env[i]; i++)
        if (!my_strncmp(env[i], name, name_len) && env[i][name_len] == '=')
            return env[i] + name_len + 1;
    return NULL;
}
