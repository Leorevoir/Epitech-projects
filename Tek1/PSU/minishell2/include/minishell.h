/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-bsminishell1-leo.quinzler
** File description:
** minishell
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #define ERROR 84
    #define SUCCESS 0
    #define NAME cmd->name
    #define ARGS cmd->arguments
    #define LINE cmd->line
    #define RDIR cmd->redirection
    #define LDIR cmd->last_directory

typedef struct cmd_s cmd_t;

typedef void (*command_handler_t)(cmd_t *);

typedef struct command_mapping_s {
    char *name;
    command_handler_t handler;
} command_mapping_t;

typedef struct cd_s {
    char *last_directory;
} cd_t;

typedef struct cmd_s {
    char *redirection;
    char *name;
    char *path;
    char *line;
    char *last_directory;
    char *arguments;
    char **env;
    cd_t *cd_struct;
    int status;
} cmd_t;

/* handle memory */
void free_cmd(cmd_t *cmd);
void free_envi(cmd_t *cmd);
void cleanup_and_exit(cmd_t *cmd);
void free_new_env(char **new_env, int i);
void *my_realloc(void *ptr, size_t size);
void *my_memcpy(void *dest, const void *src, size_t n);

/* handle segfault */
int my_isspace(unsigned char c);
int is_only_spaces(const char *cmd);
void handle_sigint(int __attribute__((unused)) sig);

/* cmd */
void execute_cmd(cmd_t *cmd);
char *check_execute(cmd_t *cmd);
char *search_in_path(cmd_t *cmd);
void process_command(cmd_t *cmd);
int is_executable(const char *path);
void check_out(pid_t pid, int status, cmd_t *cmd);
char **prepare_args(char *arguments, char *full_path);

/* read */
void read_line(cmd_t *cmd);
int shell_loop(char **env);

/* env */
void my_env(cmd_t *cmd);
void set_env(cmd_t *cmd);
char **duplicate_environment(char **env);
char *my_getenv(char **env, const char *name);

#endif /* !MINISHELL_H_ */
