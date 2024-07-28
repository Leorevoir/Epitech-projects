/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** minishell1
*/

#ifndef STRUCU_H_
    #define STRUCU_H_
    #include <sys/wait.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include <fcntl.h>
    #include <ctype.h>
    #include <signal.h>
    #include <time.h>
    #include <termios.h>

//----------test scripting----------//
typedef struct cmd_pos_s {
    int i;
    int my_if;
    int my_fi;
    bool is_done;
    bool is_inside_if_block;
    char *if_condition;
    char **if_block_commands;
    int if_block_count;
} cmd_pos_t;

typedef struct var_s {
    char *name;
    char *value;
    struct var_s *next;
} var_t;

typedef struct my_if_s {
    char *condition;
    char **inside;
    char **array;
    char *op;
    int i;
    char *before;
    char *after;
    bool is_if;
} my_if_t;

//----------test scripting----------//

typedef struct linked_s {
    struct linked_s *next;
    char *line;
}linked_t;

typedef struct pipe_list_s {
    struct pipe_list_s *next;
    char *cmd;
    char **cmd_tab;
    char *bin_cmd;
}pipe_list_t;

typedef struct history_s {
    struct history_s *next;
    struct history_s *prev;
    int number;
    char *time;
    char *line;
    int index;
}history_t;

typedef struct alias_s {
    char *name;
    char *cmd;
    struct alias_s *next;
} alias_t;

typedef struct mini_s {
    pid_t child1;
    int rtn;
    int desper_worked;
    int dpipe_worked;
    int dpipe;
    char *input;
    char *cleaned;
    char **tab_clean;
    char **path;
    char *full_cmd;
    char *oldpwd;
    char *nooldpwd;
    char **pipe_tab;
    int pipe_nb;
    int is_tty;
    char *clean_cmd;
    history_t *history;
    linked_t *linked;
    pipe_list_t *pipe_list;
//----------scripting----------//
    var_t *var_list;
    my_if_t *my_if;
    bool nona;
//----------alias----------//
    alias_t *alias;
}mini_t;

//-----------LINE EDITION-----------//

typedef struct {
    char *rep;
    char buf;
    int i;
    int string_len;
} edit_t;

#endif
