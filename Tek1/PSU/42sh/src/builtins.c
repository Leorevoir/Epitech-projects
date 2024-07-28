/*
** EPITECH PROJECT, 2024
** builtins
** File description:
** minishell1
*/

#include "alias.h"
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"
#include "scripting.h"

void unset_all(mini_t *mini)
{
    if (error_unset(mini) == 1)
        return;
    for (int i = 1; mini->tab_clean[i] != NULL; i++) {
        my_unsetenv(mini, i);
    }
}

bool my_isnum(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int my_exit(mini_t *mini)
{
    if (mini->tab_clean[1]) {
        if (my_isnum(mini->tab_clean[1])) {
            my_putstr("exit\n");
            exit(atoi(mini->tab_clean[1]));
        } else {
            my_putstr("exit: Expression Syntax.\n");
            mini->rtn = 1;
            return 0;
        }
    } else {
        my_putstr("exit\n");
        exit(mini->rtn);
    }
    return 0;
}

int my_builtins(mini_t *mini, char **env)
{
    is_input_alias(mini, mini->alias);
    if (handle_history(mini) != -1)
        return 0;
    if (handle_env(mini) != -1)
        return 0;
    if (handle_setenv(mini) != -1)
        return 0;
    if (handle_unsetenv(mini) != -1)
        return 0;
    if (handle_cd(mini) != -1) {
        update_cmdcwd(mini, env);
        return 0;
    }
    if (handle_exit(mini) != -1)
        return 0;
    return (shell_cmd(mini, env));
}
