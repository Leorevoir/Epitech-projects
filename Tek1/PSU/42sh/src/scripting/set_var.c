/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** set_var
*/

#include "scripting.h"

char *get_var_value(var_t *var_list, char *name)
{
    while (var_list != NULL) {
        if (strcmp(var_list->name, name) == 0) {
            return strdup(var_list->value);
        }
        var_list = var_list->next;
    }
    return NULL;
}

void add_var(var_t **var_list, char *name, char *value)
{
    var_t *new_var = NULL;

    remove_var(var_list, name);
    new_var = malloc(sizeof(var_t));
    memset(new_var, 0, sizeof(var_t));
    if (!new_var)
        return;
    new_var->name = strdup(name);
    new_var->value = strdup(value);
    new_var->next = *var_list;
    *var_list = new_var;
}

char *i_hate_spaces(char *str)
{
    char *src = NULL;
    char *dst = NULL;

    if (str == NULL)
        return NULL;
    src = str;
    dst = str;
    while (*src) {
        if (*src != ' '
            && *src != '\t'
            && *src != '\n'
            && *src != '\r') {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0';
    return str;
}

bool set_var(mini_t *mini)
{
    char *good = i_hate_spaces(mini->cleaned + 4);
    char *name = strtok(good, "=");
    char *value = strtok(NULL, "");

    if (name) {
        if (!value)
            value = "";
        add_var(&(mini->var_list), name, my_trim(value));
        return true;
    }
}
