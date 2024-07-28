/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** utilities
*/

#include "env.h"
#include "my_stdio.h"

static bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

static bool is_letter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

static bool is_alphanumeric(char *str)
{
    for (size_t i = 0; str[i]; ++i) {
        if (!is_letter(str[i]) && !is_digit(str[i]))
            return false;
    }
    return true;
}

bool is_valid(char **args)
{
    if (!args || !args[0])
        return false;
    if (!is_letter(args[0][0])) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return false;
    }
    if (!is_alphanumeric(args[0])) {
        my_printf(\
        "setenv: Variable name must contain alphanumeric characters.\n");
        return false;
    }
    if (args[2]) {
        my_printf("setenv: Too many arguments.\n");
        return false;
    }
    return true;
}

size_t array_length(char **env)
{
    size_t i = 0;

    while (env[i])
        i++;
    return i;
}
