/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** check_cmd
*/

#include "minishell.h"
#include "my_stdio.h"
#include "my_string.h"

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
        full_path = search_in_path(cmd);
        if (full_path) {
            return full_path;
        }
    }
    my_printf("%s: Command not found.\n", cmd->name);
    return NULL;
}
