/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** cmd
*/

#include "minishell.h"
#include <stdbool.h>
#include <fcntl.h>

#ifndef CMD_H_
    #define CMD_H_
    #define PIPE my_pipe
    #define FD pipefd

extern const command_mapping_t commands[];

typedef struct pipe_s {
    char **command;
    int pipefd[2];
    int num;
} pipe_t;

void my_cd(cmd_t *cmd);
void my_env(cmd_t *cmd);
void set_env(cmd_t *cmd);
void unset_env(cmd_t *cmd);
void execute_cmd(cmd_t *cmd);
bool is_superior(cmd_t *cmd);
bool is_inferior(cmd_t *cmd);
void what_command(cmd_t *cmd);
bool is_double_sup(cmd_t *cmd);
bool is_double_inf(cmd_t *cmd);
void execute_superior(cmd_t *cmd);
void execute_inferior(cmd_t *cmd);
void execute_double_inf(cmd_t *cmd);
void execute_double_sup(cmd_t *cmd);
int where_is_it(cmd_t *cmd, char c);
int where_is_it_double(char *str, char c);
void check_segfault(int status, cmd_t *cmd);
bool is_builtin_command(const char *command);
pipe_t init_my_pipe(char **commands, int num);
void error_handler(cmd_t *cmd, int fd1, int fd2);
void split_command(char *command, char **exec_args);
char *resolve_command_path(char *cmd_name, cmd_t *cmd);
void setup_io_for_pipe(int in_fd, pipe_t *PIPE, int i);
void execute_pipeline(cmd_t *cmd, char **commands, int num_commands);

#endif /* !CMD_H_ */
