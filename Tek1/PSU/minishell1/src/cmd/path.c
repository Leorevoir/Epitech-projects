/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** search_path
*/

#include "minishell.h"
#include "my_stdio.h"
#include "my_string.h"

static char *init_path(cmd_t *cmd)
{
    char *path = my_getenv(cmd->env, "PATH");

    if (!path || !*path)
        return NULL;
    return path;
}

static char *try_path(const char *dir, const char *cmd_name)
{
    char *full_path = malloc(my_strlen(dir) + my_strlen(cmd_name) + 2);

    if (!full_path) {
        return NULL;
    }
    my_strcpy(full_path, dir);
    my_strcat(full_path, "/");
    my_strcat(full_path, cmd_name);
    if (is_executable(full_path)) {
        return full_path;
    }
    free(full_path);
    return NULL;
}

static char *search_path_list(char **paths, const char *cmd_name)
{
    char *full_path;

    for (int i = 0; paths[i]; i++) {
        full_path = try_path(paths[i], cmd_name);
        if (full_path) {
            return full_path;
        }
    }
    return NULL;
}

char *search_in_path(cmd_t *cmd)
{
    char *default_paths[] = {"/bin/", "/usr/bin/", NULL};
    char *path = init_path(cmd) ? init_path(cmd) : "";
    char *path_copy = my_strdup(path);
    char *full_path = NULL;
    char *dir = strtok(path_copy, ":");

    while (dir) {
        full_path = try_path(dir, cmd->name);
        if (full_path) {
            free(path_copy);
            return full_path;
        }
        dir = strtok(NULL, ":");
    }
    full_path = search_path_list(default_paths, cmd->name);
    free(path_copy);
    return full_path;
}
