/*
** EPITECH PROJECT, 2024
** asd
** File description:
** asd
*/

#include "my.h"
#include "struct.h"

history_t *copy_history(history_t *original)
{
    history_t *copy = NULL;
    history_t *temp = NULL;
    history_t **last = &copy;

    while (original != NULL) {
        temp = malloc(sizeof(history_t));
        if (temp == NULL)
            return NULL;
        memcpy(temp, original, sizeof(history_t));
        temp->prev = *last;
        *last = temp;
        last = &temp->next;
        original = original->next;
    }
    return copy;
}

void free_history(history_t *list)
{
    history_t *temp;

    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp->line);
        free(temp->time);
        free(temp);
    }
}

void *my_rev_list(history_t **begin)
{
    history_t *temp = NULL;
    history_t *now = *begin;
    history_t *prochain = NULL;

    while (now != NULL) {
        prochain = now->next;
        now->next = temp;
        temp = now;
        now = prochain;
    }
    *begin = temp;
}
