/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** remove_var
*/

#include "scripting.h"

void remove_node(var_t **var_list, var_t *prev, var_t *current)
{
    if (prev)
        prev->next = current->next;
    else
        *var_list = current->next;
    free(current->name);
    free(current->value);
    free(current);
}

void remove_var(var_t **var_list, char *name)
{
    var_t *current = NULL;
    var_t *prev = NULL;

    if (!var_list || !*var_list || !name)
        return;
    current = *var_list;
    prev = NULL;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            remove_node(var_list, prev, current);
            break;
        }
        prev = current;
        current = current->next;
    }
}
