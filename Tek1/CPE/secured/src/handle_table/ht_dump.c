/*
** EPITECH PROJECT, 2024
** secured
** File description:
** ht_dump
*/

#include "../../include/hashtable.h"

void print_list_entry(linked_list_t *entry)
{
    if (entry->value != NULL)
        mini_printf("> %d - %s\n", entry->key, entry->value);
    else
        mini_printf("> %d - %s\n", entry->key, "");
}

void ht_dump(hashtable_t *ht)
{
    linked_list_t **head = NULL;
    linked_list_t *current = NULL;

    if (ht == NULL)
        return;
    head = ht->tab_list;
    for (int i = 0; i < ht->len; i++) {
        current = head[i];
        mini_printf("[%d]:\n", i);
        while (current != NULL) {
            print_list_entry(current);
            current = current->next;
        }
    }
}
