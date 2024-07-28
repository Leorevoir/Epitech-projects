/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** color
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

void add_line(mini_t *mini, char ***my_args)
{
    int size = 0;
    int idx = 0;

    for (; mini->tab_clean[size] != NULL; size++);
    *my_args = malloc(sizeof(char *) * (size + 2));
    for (; mini->tab_clean[idx] != NULL; idx++) {
        (*my_args)[idx] = my_strdup(mini->tab_clean[idx]);
    }
    (*my_args)[idx] = my_strdup("--color=tty");
    idx++;
    (*my_args)[idx] = NULL;
}

int color(mini_t *mini, char **env, int status)
{
    char **my_args;
    pid_t child;

    add_line(mini, &my_args);
    child = fork();
    if (child == 0) {
        status = execve("/bin/ls", my_args, env);
    } else {
        waitpid(child, &status, 0);
    }
}
