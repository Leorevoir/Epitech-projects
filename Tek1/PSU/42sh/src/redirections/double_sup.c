/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** double_sup
*/

#include "my.h"

void execute_double_sup(char *before, char *redir, mini_t *mini, char **env)
{
    int fd = open(redir, O_WRONLY | O_CREAT | O_APPEND, 0666);
    int save_stdout = dup(STDOUT_FILENO);

    if (save_stdout == -1)
        return;
    if (dup2(fd, STDOUT_FILENO) == -1) {
        error_handler(mini, fd, save_stdout);
        return;
    }
    mini->tab_clean = my_str_to_word_array(before, ' ');
    mini->rtn = my_builtins(mini, env);
    if (dup2(save_stdout, STDOUT_FILENO) == -1) {
        error_handler(mini, fd, save_stdout);
        return;
    }
    close(fd);
    close(save_stdout);
}

/// @brief le truc qui fait >> écrit à la suite
/// @param str cmd string
/// @param mini struct
/// @param env environment
/// @param pos position de >> dans str
int redir_double_sup(char *str, mini_t *mini, char **env, int pos)
{
    char *before = malloc(pos + 1);
    char *after = NULL;
    char *redir = NULL;

    strncpy(before, str, pos);
    before[pos] = '\0';
    after = strdup(str + pos + 2);
    if (strlen(before) > 0)
        str = strdup(before);
    else
        str = NULL;
    redir = strdup(my_trim(after));
    execute_double_sup(before, redir, mini, env);
    free(before);
    free(after);
    return 1;
}

bool is_double_redirection(const char *str, int *pos, const char c)
{
    if (!str || str[0] == '\0')
        return false;
    for (int i = 0; str[i] && str[i + 1]; i++) {
        if (str[i] == c && str[i + 1] == c) {
            *pos = i;
            return true;
        }
    }
    return false;
}
