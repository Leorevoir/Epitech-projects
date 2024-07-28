/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** env
*/

#include "minishell.h"

#ifndef ENV_H_
    #define ENV_H_
    #define KEY env_s.key
    #define VALUE env_s.value
    #define LEN env_s.key_len
    #define ENTRY env_s.entry

typedef struct my_env_s {
    const char *key;
    const char *value;
    char *entry;
    size_t key_len;
} my_env_t;

bool is_valid(char **args);
size_t array_length(char **env);

#endif /* !ENV_H_ */
