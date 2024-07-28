/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** builtfonc
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/struct.h"

int handle_history(mini_t *mini)
{
    if (my_strcmp(mini->tab_clean[0], "history") == 0) {
        display_history(mini, mini->history);
        return 0;
    }
    return -1;
}

int handle_env(mini_t *mini)
{
    if (my_strcmp(mini->tab_clean[0], "env") == 0)
        return display_env(mini, mini->linked);
    return -1;
}

int handle_setenv(mini_t *mini)
{
    if (my_strcmp(mini->tab_clean[0], "setenv") == 0)
        return my_setenv(mini);
    return -1;
}

int handle_unsetenv(mini_t *mini)
{
    if (my_strcmp(mini->tab_clean[0], "unsetenv") == 0) {
        unset_all(mini);
        return 0;
    }
    return -1;
}

int handle_cd(mini_t *mini)
{
    if (my_strcmp(mini->tab_clean[0], "cd") == 0)
        return my_cd(mini);
    return -1;
}
