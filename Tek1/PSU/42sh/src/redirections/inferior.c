/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** inferior
*/

#include "my.h"
#include "struct.h"

void what_file_0_o(char *before, char *redir, mini_t *mini, char **env)
{
    int fd = open(redir, O_RDONLY);
    int save_stdin = dup(STDIN_FILENO);

    if (fd == -1) {
        fprintf(stderr, "%s: No such file or directory.\n", redir);
        error_handler(mini, fd, -1);
        return;
    }
    if (save_stdin == -1) {
        error_handler(mini, fd, -1);
        return;
    }
    if (dup2(fd, STDIN_FILENO) == -1)
        return;
    mini->tab_clean = my_str_to_word_array(before, ' ');
    mini->rtn = my_builtins(mini, env);
    if (dup2(save_stdin, STDIN_FILENO) == -1)
        perror("dup2");
    close(fd);
    close(save_stdin);
}

/// @brief le truc qui fait < lis le contenu
/// @param str cmd string
/// @param mini struct
/// @param env environment
/// @param pos position de < dans str
int redir_inferior(char *str, mini_t *mini, char **env, int pos)
{
    char *before = malloc(pos + 1);
    char *after = strdup(str + pos + 1);
    char *redir = NULL;

    strncpy(before, str, pos);
    before[pos] = '\0';
    if (before[0] != '\0')
        str = strdup(before);
    else
        str = NULL;
    redir = strdup(my_trim(after));
    what_file_0_o(before, redir, mini, env);
    free(before);
    free(after);
    return 1;
}
