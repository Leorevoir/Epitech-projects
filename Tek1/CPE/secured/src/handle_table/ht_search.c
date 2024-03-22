/*
** EPITECH PROJECT, 2024
** secured
** File description:
** ht_search
*/

#include "../../include/hashtable.h"

int compare_str_key(int a, int b)
{
    if (a == b)
        return 1;
    return 0;
}

char *search_str_key(linked_list_t **head, linked_list_t *current,
    linked_list_t *prev, int key_hashed)
{
    if (compare_str_key(current->key, key_hashed) == 1)
        return (current->value);
    return NULL;
}

char *find_str_in_list(linked_list_t **head, int key_hashed)
{
    linked_list_t *current = *head;
    linked_list_t *prev = NULL;

    while (current != NULL) {
        if (search_str_key(head, current, prev, key_hashed) != NULL)
            return (current->value);
        prev = current;
        current = current->next;
    }
}

char *ht_search(hashtable_t *ht, char *key)
{
    linked_list_t **head;
    int key_hashed;

    if (ht == NULL || key == NULL)
        return NULL;
    head = ht->tab_list;
    key_hashed = ht->hash_function(key, ht->len);
    for (int i = 0; i < ht->len; i++) {
        if (find_str_in_list(&head[i], key_hashed) != NULL)
            return (find_str_in_list(&head[i], key_hashed));
    }
    return NULL;
}
