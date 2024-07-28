/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** minishell1
*/

#ifndef MY_H_
    #define MY_H_
    #include "./struct.h"

int my_list(mini_t *mini, char **env);
int minishell(mini_t *mini, char **env);
int my_putstr(char const *str);
void my_putchar(char c);
int str_available(mini_t *mini);
int my_builtins(mini_t *mini, char **env);
int my_strlen(char const *str);
int display_env(mini_t *mini, linked_t *list);
char **my_str_to_word_array(char *str, char sep);
char **my_str_to_word_array_condition(char *str, char *condition);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int shell_cmd(mini_t *mini, char **env);
char *my_strcat(char *dest, char const *src);
int my_cd(mini_t *mini);
int put_in_list(linked_t **linked, char *line);
int my_setenv(mini_t *mini);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
void my_unsetenv(mini_t *mini, int i);
int is_asegv(int status);
int error_unset(mini_t *mini);
char *clean_semicolon(char *dirty);
int key_char(char *str, mini_t *mini);
int list_pipe(pipe_list_t **node, char *cmd);
int my_pipe(mini_t *mini);
int concatenate_pipe_cmd(mini_t *mini);
char *my_trim(char *str);
void free_word_array(char **array);
void execute_command(mini_t *mini, pipe_list_t **cur);
int handle_history(mini_t *mini);
int handle_env(mini_t *mini);
int handle_setenv(mini_t *mini);
int handle_unsetenv(mini_t *mini);
int handle_cd(mini_t *mini);
int handle_exit(mini_t *mini);
void unset_all(mini_t *mini);
int my_exit(mini_t *mini);
int color(mini_t *mini, char **env, int status);
int is_separator(char *cmd, mini_t *mini, char **env);

//------------------- HISTORY --------------------------//
void create_history(char *line, history_t **his);
void display_history(mini_t *mini, history_t *his);
int my_put_nbr(int nb);
void *my_rev_list(history_t **begin);
history_t *copy_history(history_t *original);
void free_history(history_t *list);


//-------------------- REDIRECTIONS --------------------//
void error_handler(mini_t *mini, int fd1, int fd2);
bool is_simple_redirection(char *str, int *pos, const char c);
int redir_superior(char *str, mini_t *mini, char **env, int pos);
int redir_inferior(char *str, mini_t *mini, char **env, int pos);
int redir_double_inf(char *str, mini_t *mini, char **env, int pos);
int redir_double_sup(char *str, mini_t *mini, char **env, int pos);
bool is_double_redirection(const char *str, int *pos, const char c);
void execute_double_inf(char *before, char *redir, mini_t *mini, char **env);
bool check_redirection(char *str, mini_t *mini, char **env);

//-------------------- LINE EDITION --------------------//
char *get_command(history_t *his);
int is_arrow(edit_t *edit, history_t **his);
void backspace(edit_t *edit);
void back_history(history_t *his);
void next_history(history_t *his);
void clear_line(edit_t *edit);
int autocompletion(edit_t *edit);

#endif
