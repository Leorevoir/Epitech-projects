/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** scripting_tool
*/

#include "scripting.h"

void is_it_an_if(char **cmd, bool *correct, mini_t *mini, cmd_pos_t *pos)
{
    if (strstr(cmd[pos->i], "if")) {
        pos->if_condition = strdup(cmd[pos->i]);
        pos->my_if = pos->i;
        pos->is_inside_if_block = true;
    }
    if (strcmp(cmd[pos->i], "fi") == 0) {
        pos->my_fi = pos->i;
        pos->is_done = true;
        pos->is_inside_if_block = false;
        *correct = true;
    }
    if (pos->is_inside_if_block)
        add_string_to_array(&pos->if_block_commands, cmd[pos->i],
            &(pos->if_block_count));
}

void add_string_to_array(char ***array, const char *string, int *count)
{
    *array = realloc(*array, (*count + 1) * sizeof(char *));
    if (*array == NULL)
        return;
    (*array)[*count] = strdup(string);
    (*count)++;
}

void free_command_array(char **array, int j, char *str)
{
    for (int i = 0; i < j; i++)
        free(array[i]);
    free(array);
    free(str);
}

char *remove_tab(char *str)
{
    char *start = str;
    char *better = NULL;

    while (*start == '\t' || *start == ' ')
        start++;
    better = strdup(start);
    return better;
}
