/*
** EPITECH PROJECT, 2024
** secured
** File description:
** ht_insert
*/

#include "../../include/hashtable.h"

int verify_input(hashtable_t *ht, char *key, char *value)
{
    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    return 0;
}

int check_key_already_exists(linked_list_t *current, int key_hashed,
    char *value)
{
    linked_list_t *tmp = current;

    while (tmp != NULL) {
        if (current->key == key_hashed) {
            current->key = key_hashed;
            current->value = value;
            return 0;
        }
        current = current->next;
        tmp = tmp->next;
    }
    return 1;
}

int add_element_to_hashtable(hashtable_t *ht, int key_hashed, char *value)
{
    int index = key_hashed % ht->len;
    linked_list_t *element = malloc(sizeof(*element));

    if (element == NULL)
        return 84;
    if (ht->tab_list[index] != NULL) {
        if (!check_key_already_exists(ht->tab_list[index], key_hashed, value))
            return 0;
    }
    element->key = key_hashed;
    element->value = value;
    element->next = ht->tab_list[index];
    ht->tab_list[index] = element;
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int key_hashed;
    int result;

    if (verify_input(ht, key, value) == 84)
        return 84;
    key_hashed = ht->hash_function(key, ht->len);
    result = add_element_to_hashtable(ht, key_hashed, value);
    return result;
}
