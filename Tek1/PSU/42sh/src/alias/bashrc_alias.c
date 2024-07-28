/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** bashrc_alias
*/

#include "alias.h"
#include "scripting.h"

static bool format_alias(char *line, alias_t **head)
{
    char *cmd[] = {NULL, NULL, NULL, NULL};
    char *name = NULL;
    char *command = NULL;
    char *token = NULL;

    if (strstr(line, "alias ") == line) {
        name = strtok(line + 6, "=");
        if (!name)
            return false;
        command = strtok(NULL, "'");
        if (!command)
            return false;
        cmd[0] = "alias";
        cmd[1] = name;
        cmd[2] = command;
        cmd[3] = NULL;
        create_new_alias(cmd, head);
    }
    return true;
}

void load_aliases_from_bashrc(const char *filename, alias_t **head)
{
    FILE *file = fopen(filename, "r");
    char line[MAX_BUFFER];

    if (!file)
        return;
    while (fgets(line, sizeof(line), file))
        if (!format_alias(line, head))
            continue;
    fclose(file);
}

static char *get_home_path(void)
{
    char *home_path = getenv("HOME");

    if (home_path == NULL)
        return NULL;
    return home_path;
}

char *get_bashrc_path(void)
{
    static char bashrc_path[MAX_BUFFER];
    char *home_path = get_home_path();

    if (home_path == NULL)
        return NULL;
    sprintf(bashrc_path, "%s/.bashrc", home_path);
    return bashrc_path;
}
