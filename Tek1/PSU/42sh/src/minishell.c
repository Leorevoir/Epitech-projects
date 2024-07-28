/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell1
*/

#include "my.h"
#include "alias.h"
#include "struct.h"
#include "scripting.h"

bool check_redirection(char *str, mini_t *mini, char **env)
{
    int pos = 0;

    if (is_double_redirection(str, &pos, '>'))
        return redir_double_sup(str, mini, env, pos);
    if (is_double_redirection(str, &pos, '<'))
        return redir_double_inf(str, mini, env, pos);
    if (is_simple_redirection(str, &pos, '>'))
        return (redir_superior(str, mini, env, pos));
    if (is_simple_redirection(str, &pos, '<'))
        return (redir_inferior(str, mini, env, pos));
    return 0;
}

int semi_colon(mini_t *mini, char **env)
{
    int size = my_strlen(mini->cleaned);
    char **semicolon;

    if (mini->cleaned[size - 1] == ';')
        mini->cleaned[size - 1] = '\0';
    semicolon = my_str_to_word_array(mini->cleaned, ';');
    for (int i = 0; semicolon[i] != NULL; i++) {
        semicolon[i] = clean_semicolon(semicolon[i]);
        key_char(semicolon[i], mini);
        mini->clean_cmd = clean_semicolon(semicolon[i]);
        if (my_strcmp(mini->cleaned, "exit") == 0)
            return 1;
        if (is_separator(semicolon[i], mini, env) == 1)
            continue;
        if (!check_redirection(semicolon[i], mini, env)) {
            mini->tab_clean = my_str_to_word_array(semicolon[i], ' ');
            mini->rtn = my_builtins(mini, env);
        }
    }
}

static void handle_sigint(int __attribute__((unused)) sig)
{
    printf("\n$> ");
    fflush(stdout);
}

static char *is_tty_or_not(mini_t *mini, size_t bufsize)
{
    char *b = NULL;

    if (isatty(0) != 0){
        printf("$> ");
        fflush(stdout);
        mini->is_tty = 0;
        return get_command(mini->history);
    } else {
        if (getline(&b, &bufsize, stdin) == -1){
            printf("exit\n");
            exit(mini->rtn);
        }
        mini->is_tty = 1;
        return b;
    }
}

int minishell_loop(mini_t *mini, char **env, size_t bufsize)
{
    signal(SIGINT, handle_sigint);
    while (1 && !mini->nona) {
        mini->dpipe = 0;
        mini->input = is_tty_or_not(mini, bufsize);
        create_history(mini->input, &mini->history);
        str_available(mini);
        if (create_alias(mini->cleaned, &mini->alias))
            continue;
        if (my_strcmp(mini->input, "\n") == 0)
            continue;
        if (is_scripting(mini, env))
            continue;
        if (semi_colon(mini, env))
            return 0;
    }
}

static void load_var(var_t *head, mini_t *mini)
{
    char *term = getenv("TERM");
    char *cwd = (char *)malloc(4096);

    if (getcwd(cwd, 4096) != NULL)
        add_var(&head, "cwd", cwd);
    if (term != NULL)
        add_var(&head, "term", term);
    mini->var_list = head;
}

int minishell(mini_t *mini, char **env)
{
    char *b;
    size_t bufsize = 32;

    mini->input;
    mini->nona = false;
    b = mini->input;
    load_var(mini->var_list, mini);
    minishell_loop(mini, env, bufsize);
    nona_loop(mini, env, bufsize, b);
}
