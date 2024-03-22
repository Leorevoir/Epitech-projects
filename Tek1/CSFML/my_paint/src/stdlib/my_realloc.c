/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** my_realloc
*/

#include "my_stdlib.h"

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr = NULL;

    if (size == 0 && ptr != NULL) {
        free(ptr);
        return NULL;
    }
    new_ptr = malloc(size);
    if (!new_ptr)
        return NULL;
    if (ptr != NULL) {
        my_memcpy(new_ptr, ptr, size);
        free(ptr);
    }
    return new_ptr;
}
