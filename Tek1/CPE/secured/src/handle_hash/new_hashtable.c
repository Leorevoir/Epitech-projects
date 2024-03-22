/*
** EPITECH PROJECT, 2024
** secured
** File description:
** new_hashtable
*/

#include "../../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hashtable = malloc(sizeof(hashtable_t));

    if (hashtable == NULL || len <= 0 || hash == NULL)
        return NULL;
    hashtable->hash_function = hash;
    hashtable->tab_list = malloc(sizeof(linked_list_t *) * (len + 1));
    hashtable->len = len;
    for (int i = 0; i < len; i++)
        hashtable->tab_list[i] = NULL;
    return hashtable;
}
