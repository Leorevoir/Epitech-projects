/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** cd
*/

#include "my_string.h"
#include "my_stdio.h"
#include "minishell.h"

static void update_last_directory(cmd_t *cmd, const char *new_ldir)
{
    if (new_ldir) {
        free(LDIR);
        LDIR = my_strdup(new_ldir);
    }
    cmd->status = 0;
}

static char *parse_cd_arg(const char *buffer)
{
    char *arg = NULL;
    int i = 0;

    if (!buffer)
        return my_strdup("~");
    while (buffer[i] == ' ')
        i++;
    if (buffer[i] == '\0' || buffer[i] == '\n')
        return my_strdup("~");
    arg = my_strdup(&buffer[i]);
    if (my_strrchr(arg, ' ')) {
        free(arg);
        my_printf("cd: Too many arguments.\n");
        return NULL;
    }
    return arg;
}

static void go_home(cmd_t *cmd)
{
    const char *home = my_getenv(cmd->env, "HOME");

    if (home) {
        if (chdir(home) == 0)
            update_last_directory(cmd, my_getenv(cmd->env, "PWD"));
        else
            perror("chdir to home failed");
    } else
        my_printf("HOME variable not set.\n");
}

static void cd_error(const char *path, cmd_t *cmd)
{
    struct stat st;

    if (stat(path, &st) == -1) {
        my_printf("%s: No such file or directory.\n", path);
        cmd->status = 1;
        return;
    }
    if (!S_ISDIR(st.st_mode)) {
        my_printf("%s: Not a directory.\n", path);
        cmd->status = 1;
        return;
    }
}

static void go_to_directory(cmd_t *cmd, const char *path)
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd failed");
        return;
    }
    if (path && my_strcmp(path, "-") == 0) {
        if (LDIR && chdir(LDIR) == 0) {
            update_last_directory(cmd, cwd);
        } else
            perror("chdir to last directory failed");
    } else {
        if (chdir(path) == 0)
            update_last_directory(cmd, cwd);
        else
            cd_error(path, cmd);
    }
}

void my_cd(cmd_t *cmd)
{
    char **args = my_str_to_word_array(cmd->arguments);
    char *arg = NULL;

    if (!args || !args[0]) {
        go_home(cmd);
        return;
    }
    arg = parse_cd_arg(args[0]);
    if (!arg) {
        cmd->status = 1;
        free_word_array(args);
        return;
    }
    if (my_strcmp(arg, "~") == 0 || my_strcmp(arg, "--") == 0)
        go_home(cmd);
    else
        go_to_directory(cmd, arg);
    free(arg);
    free_word_array(args);
}
