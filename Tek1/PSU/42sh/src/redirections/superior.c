/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** superior
*/

#include "my.h"
#include "struct.h"

void error_handler(mini_t *mini, int fd1, int fd2)
{
    close(fd1);
    if (fd2 != -1)
        close(fd2);
    mini->rtn = 1;
}

void prepare_superior(mini_t *mini, char *before, char *after, char **env)
{
    int fd = open(after, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int old_stdout = dup(STDOUT_FILENO);

    if (old_stdout == -1) {
        error_handler(mini, fd, -1);
        return;
    }
    if (dup2(fd, STDOUT_FILENO) == -1) {
        error_handler(mini, fd, old_stdout);
        return;
    }
    mini->tab_clean = my_str_to_word_array(before, ' ');
    mini->rtn = my_builtins(mini, env);
    if (dup2(old_stdout, STDOUT_FILENO) == -1)
        perror("dup2");
    close(fd);
    close(old_stdout);
}

/// @brief le truc qui fait > écrit dans fd
/// @param str cmd string
/// @param mini struct
/// @param env environment
/// @param pos position de > dans str
int redir_superior(char *str, mini_t *mini, char **env, int pos)
{
    char *redirection = NULL;
    char *before = malloc(pos + 1);
    char *after = strdup(str + pos + 1);
    char *redir = NULL;

    strncpy(before, str, pos);
    before[pos] = '\0';
    redir = strdup(my_trim(after));
    prepare_superior(mini, before, redir, env);
    free(before);
    free(after);
    return 1;
}

bool is_simple_redirection(char *str, int *pos, const char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c && str[i + 1] != c) {
            *pos = i;
            return true;
        }
    }
    return false;
}
