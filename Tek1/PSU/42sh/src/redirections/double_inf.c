/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** double_inf
*/

#include "my.h"

void execute_double_inf(char *before, char *redir, mini_t *mini, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int pipefd[2];

    pipe(pipefd);
    do {
        read = getline(&line, &len, stdin);
        if (strstr(line, redir) == line
            && line[strlen(redir)] == '\n')
            break;
        write(pipefd[1], line, read);
    } while (read != -1);
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    mini->tab_clean = my_str_to_word_array(before, ' ');
    mini->rtn = my_builtins(mini, env);
    if (line)
        free(line);
}

/// @brief le truc qui fait << redirige l'entrée standard
/// @param str cmd string
/// @param mini struct
/// @param env environment
/// @param pos position de << dans str
int redir_double_inf(char *str, mini_t *mini, char **env, int pos)
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
    execute_double_inf(before, redir, mini, env);
    free(before);
    free(after);
    return 1;
}
