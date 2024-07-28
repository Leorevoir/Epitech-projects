/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** create_alias
*/

#include "alias.h"
#include "scripting.h"

char *get_alias_by_name(char *alias_name, alias_t **head)
{
    alias_t *current = *head;

    while (current != NULL) {
        if (strcmp(current->name, alias_name) == 0)
            return current->cmd;
        current = current->next;
    }
    return NULL;
}

static void check_if_alias_exists(char *alias_name, alias_t **head)
{
    alias_t *current = *head;
    alias_t *previous = NULL;

    while (current != NULL && strcmp(current->name, alias_name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        free(current->name);
        free(current->cmd);
        if (previous != NULL)
            previous->next = current->next;
        else
            *head = current->next;
        free(current);
    }
}

void concat_alias_cmd(alias_t **head, alias_t *new_alias, char **cmd)
{
    alias_t *current = NULL;

    strcpy(new_alias->cmd, "");
    for (size_t i = 2; cmd[i] != NULL; i++) {
        strcat(new_alias->cmd, cmd[i]);
        if (cmd[i + 1] != NULL)
            strcat(new_alias->cmd, " ");
    }
    new_alias->next = NULL;
    if (*head == NULL)
        *head = new_alias;
    else {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_alias;
    }
}

void create_new_alias(char **cmd, alias_t **head)
{
    alias_t *new_alias = NULL;
    size_t cmd_len = 0;

    check_if_alias_exists(cmd[1], head);
    new_alias = malloc(sizeof(alias_t));
    new_alias->name = strdup(cmd[1]);
    for (size_t i = 2; cmd[i] != NULL; i++) {
        cmd_len += strlen(cmd[i]);
        if (cmd[i + 1] != NULL)
            cmd_len++;
    }
    new_alias->cmd = malloc(cmd_len + 1);
    if (!new_alias->cmd) {
        free(new_alias->name);
        free(new_alias);
        return;
    }
    concat_alias_cmd(head, new_alias, cmd);
}

static void print_all_aliases(alias_t **head)
{
    alias_t *current = *(head);

    if (!current || !head)
        return;
    while (current != NULL) {
        printf("%s\t(%s)\n", current->name, current->cmd);
        current = current->next;
    }
}

void debug_alias(alias_t **head, char **tmp)
{
    alias_t *current = *(head);

    if (!current || !head)
        return;
    if (tmp[0] && !tmp[1]) {
        print_all_aliases(head);
        return;
    }
    while (current != NULL) {
        if (strcmp(current->name, tmp[1]) == 0) {
            printf("%s\n", current->cmd);
            return;
        }
        current = current->next;
    }
}

bool create_alias(char *input, alias_t **head)
{
    char **tmp = my_str_to_word_array(input, ' ');

    if (tmp == NULL || tmp[0] == NULL)
        return false;
    if (strcmp(tmp[0], "unalias") == 0) {
        remove_alias_by_name(tmp[1], head);
        free_word_array(tmp);
        return true;
    }
    if (strcmp(tmp[0], "alias") != 0) {
        free_word_array(tmp);
        return false;
    }
    if (tmp[0] && tmp[1] && tmp[2])
        create_new_alias(tmp, head);
    else
        debug_alias(head, tmp);
    free_word_array(tmp);
    return true;
}
