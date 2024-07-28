/*
** EPITECH PROJECT, 2024
** shell_cmd
** File description:
** minishell1
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "../include/my.h"
#include "../include/struct.h"

int path_line(mini_t *mini, char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            mini->path = my_str_to_word_array(env[i] + 5, ':');
        }
    }
}

void concat_path_cmd(mini_t *mini, DIR *dir, int i)
{
    struct dirent *dirent;
    char *slash = NULL;

    dirent = readdir(dir);
    while (dirent != NULL) {
        if (my_strcmp(mini->tab_clean[0], dirent->d_name) == 0) {
            slash = my_strcat(mini->path[i], "/");
            mini->full_cmd = my_strcat(slash, mini->tab_clean[0]);
            return;
        }
        dirent = readdir(dir);
    }
    mini->full_cmd = NULL;
}

void is_empty(mini_t *mini)
{
    struct dirent *dirent;
    DIR *dir;

    for (int i = 0; mini->path[i] != NULL; i++) {
        dir = opendir(mini->path[i]);
        if (dir == NULL)
            continue;
        concat_path_cmd(mini, dir, i);
        if (mini->full_cmd != NULL)
            break;
    }
    if (mini->full_cmd == NULL) {
        mini->desper_worked = 1;
        mini->dpipe_worked = 0;
    } else {
        mini->dpipe_worked = 1;
    }
    if (mini->full_cmd == NULL) {
        mini->full_cmd = my_strdup(mini->tab_clean[0]);
    }
}

static int my_error_exec(mini_t *mini, int status)
{
    if (errno == ENOEXEC) {
        my_putstr(mini->full_cmd);
        my_putstr(": Exec format error. Wrong Architecture.\n");
        exit(status);
        return (1);
    }
}

static void perm_denied(mini_t *mini)
{
    my_putstr(mini->full_cmd);
    my_putstr(": Permission denied.\n");
}

static void cmd_not_found(mini_t *mini)
{
    my_putstr(mini->full_cmd);
    my_putstr(": Command not found.\n");
}

static void my_waiting(pid_t child, int status)
{
    waitpid(child, &status, 0);
    is_asegv(status);
}

int command_exe(mini_t *mini, char **env, int status)
{
    struct stat st;
    pid_t child;

    child = fork();
    if (child == 0) {
        status = execve(mini->full_cmd, mini->tab_clean, env);
        stat(mini->full_cmd, &st);
        if (my_error_exec(mini, status) == 1)
            return (1);
        if (S_ISDIR(st.st_mode) || S_ISREG(st.st_mode)) {
            perm_denied(mini);
            exit(status);
        } else {
            cmd_not_found(mini);
            exit(status);
        }
    } else {
        my_waiting(child, status);
    }
}

int shell_cmd(mini_t *mini, char **env)
{
    int status;

    path_line(mini, env);
    if (mini->path == NULL){
        printf("%s: Command not found.\n", mini->tab_clean[0]);
        return 0;
    }
    if (mini->pipe_nb >= 1 && mini->dpipe == 0) {
        my_pipe(mini);
        return (0);
    }
    is_empty(mini);
    if (my_strcmp(mini->full_cmd, "/usr/bin/ls") == 0) {
        color(mini, env, status);
        return 0;
    }
    command_exe(mini, env, status);
}
