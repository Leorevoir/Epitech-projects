/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** setenv
*/

#include "env.h"
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

void update_var_env(char ***env, char *entry, size_t i)
{
    char **new_env = my_realloc(*env, sizeof(char *) * (i + 2));

    if (!new_env) {
        free(entry);
        return;
    }
    new_env[i] = entry;
    new_env[i + 1] = NULL;
    *env = new_env;
}

bool change_env(cmd_t *cmd, my_env_t *env_s, char **args)
{
    for (size_t i = 0; cmd->env[i]; ++i) {
        if (!my_strncmp(cmd->env[i], env_s->key, env_s->key_len)
            && cmd->env[i][env_s->key_len] == '=') {
            free(cmd->env[i]);
            cmd->env[i] = env_s->entry;
            free_word_array(args);
            return true;
        }
    }
    return false;
}

static my_env_t init_env_s(char **args)
{
    my_env_t env_s = {0};

    KEY = args[0];
    VALUE = args[1] ? args[1] : "";
    ENTRY = create_env_entry(KEY, VALUE);
    LEN = my_strlen(KEY);
    return env_s;
}

void set_env(cmd_t *cmd)
{
    my_env_t env_s = {0};
    size_t env_len = 0;
    char **args = NULL;

    if (!ARGS) {
        my_env(cmd);
        return;
    }
    args = my_str_to_word_array(ARGS);
    if (!is_valid(args)) {
        cmd->status = 1;
        free_word_array(args);
        return;
    }
    env_s = init_env_s(args);
    if (!change_env(cmd, &env_s, args)) {
        env_len = array_length(cmd->env);
        update_var_env(&cmd->env, ENTRY, env_len);
        free_word_array(args);
    }
}
