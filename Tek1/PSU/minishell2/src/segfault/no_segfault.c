/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** no_segfault
*/

#include "minishell.h"
#include "my_stdio.h"
#include "my_string.h"

void handle_sigint(int __attribute__((unused)) sig)
{
    my_printf("\n\033[03;33m$>\033[00m ");
}

int my_isspace(unsigned char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int is_only_spaces(const char *cmd)
{
    for (int i = 0; cmd[i]; i++) {
        if (!my_isspace((unsigned char)cmd[i]))
            return 0;
    }
    return 1;
}
