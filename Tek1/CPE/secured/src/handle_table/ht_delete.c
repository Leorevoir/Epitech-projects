/*
** EPITECH PROJECT, 2024
** secured
** File description:
** ht_delete
*/

#include "../../include/hashtable.h"

int compare_key(int a, int b)
{
    if (a == b)
        return 0;
    return 1;
}

int search_key(linked_list_t **head, linked_list_t *current,
    linked_list_t *prev, int key_hashed)
{
    if (compare_key(current->key, key_hashed) == 0) {
        if (prev == NULL)
            *head = current->next;
        else
            prev->next = current->next;
        free(current);
        return 0;
    }
    return 1;
}

int find_key_in_list(linked_list_t **head, int key_hashed)
{
    linked_list_t *current = *head;
    linked_list_t *prev = NULL;

    while (current != NULL) {
        if (search_key(head, current, prev, key_hashed) == 0)
            return 0;
        prev = current;
        current = current->next;
    }
    return 1;
}

int ht_delete(hashtable_t *ht, char *key)
{
    linked_list_t **head;
    int key_hashed;

    if (ht == NULL || key == NULL)
        return 84;
    head = ht->tab_list;
    key_hashed = ht->hash_function(key, ht->len);
    for (int i = 0; i < ht->len; i++) {
        if (find_key_in_list(&head[i], key_hashed) == 0)
            return 0;
    }
    return 84;
}
