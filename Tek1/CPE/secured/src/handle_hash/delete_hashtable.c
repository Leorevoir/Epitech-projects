/*
** EPITECH PROJECT, 2024
** secured
** File description:
** delete_hashtable
*/

#include "../../include/hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    linked_list_t *current = NULL;
    linked_list_t *next = NULL;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        current = ht->tab_list[i];
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
    }
    free(ht->tab_list);
    free(ht);
}
