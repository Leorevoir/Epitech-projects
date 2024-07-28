/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** check_cmd
*/

#include "cmd.h"
#include "my_stdio.h"
#include "my_string.h"

char *build_path(char *cmd_name, char *path_segment)
{
    char *possible_path = NULL;

    possible_path = malloc(my_strlen(path_segment)
        + my_strlen(cmd_name) + 2);
    my_strcpy(possible_path, path_segment);
    my_strcat(possible_path, "/");
    my_strcat(possible_path, cmd_name);
    return possible_path;
}

char *resolve_command_path(char *cmd_name, cmd_t *cmd)
{
    struct stat st;
    char *path = my_getenv(cmd->env, "PATH");
    char *path_dup = my_strdup(path);
    char *path_segment = strtok(path_dup, ":");
    char *possible_path = NULL;

    while (path_segment != NULL) {
        possible_path = build_path(cmd_name, path_segment);
        if (stat(possible_path, &st) == 0 && st.st_mode & S_IXUSR) {
            free(path_dup);
            return possible_path;
        }
        free(possible_path);
        path_segment = strtok(NULL, ":");
    }
    free(path_dup);
    return NULL;
}

int is_executable(const char *path)
{
    struct stat st;

    return stat(path, &st) == 0 && (st.st_mode & S_IXUSR);
}

char *check_execute(cmd_t *cmd)
{
    char *full_path = NULL;

    if (cmd->name[0] == '/' || my_strncmp(cmd->name, "./", 2) == 0) {
        if (is_executable(cmd->name)) {
            return my_strdup(cmd->name);
        }
    } else {
        full_path = resolve_command_path(cmd->name, cmd);
        if (full_path) {
            return full_path;
        }
    }
    my_printf("%s: Command not found.\n", cmd->name);
    cmd->status = 1;
    return NULL;
}
