/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** remove_alias
*/

#include "alias.h"

void remove_alias_by_name(char *alias_name, alias_t **head)
{
    alias_t *current = *head;
    alias_t *previous = NULL;

    if (!alias_name)
        return;
    while (current != NULL && strcmp(current->name, alias_name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous != NULL)
            previous->next = current->next;
        else
            *head = current->next;
        free(current->name);
        free(current->cmd);
        free(current);
        return;
    }
}

void remove_all_aliases(alias_t **head)
{
    alias_t *temp = NULL;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp->name);
        free(temp->cmd);
        free(temp);
    }
}
