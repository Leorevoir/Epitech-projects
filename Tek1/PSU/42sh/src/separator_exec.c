/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** separator_exec
*/

#include "my.h"
#include "alias.h"
#include "struct.h"
#include "scripting.h"

int is_double_esperluette(char *cmd)
{
    for (int i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == '&' && cmd[i + 1] == '&')
            return (1);
    }
    return (0);
}

void exec_desper(char **separator, mini_t *mini, char **env)
{
    for (int i = 0; separator[i] != NULL; i++) {
        if (mini->desper_worked == 1)
            break;
        if (!check_redirection(separator[i], mini, env)) {
            mini->tab_clean = my_str_to_word_array(separator[i], ' ');
            mini->rtn = my_builtins(mini, env);
        }
    }
}

int is_double_pipe(char *cmd)
{
    for (int i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == '|' && cmd[i + 1] == '|')
            return (1);
    }
    return (0);
}

void exec_dpipe(char **separator, mini_t *mini, char **env)
{
    for (int i = 0; separator[i] != NULL; i++) {
        if (!check_redirection(separator[i], mini, env)) {
            mini->tab_clean = my_str_to_word_array(separator[i], ' ');
            mini->rtn = my_builtins(mini, env);
        }
        if (mini->dpipe_worked == 1) {
            break;
        }
    }
}

int is_separator(char *cmd, mini_t *mini, char **env)
{
    char **separator;

    mini->desper_worked = 0;
    mini->dpipe_worked = -1;
    if (is_double_esperluette(cmd) == 1) {
        separator = my_str_to_word_array(cmd, '&');
        exec_desper(separator, mini, env);
        return (1);
    }
    if (is_double_pipe(cmd) == 1) {
        mini->dpipe = 1;
        separator = my_str_to_word_array(cmd, '|');
        exec_dpipe(separator, mini, env);
        return (1);
    }
    return (0);
}
