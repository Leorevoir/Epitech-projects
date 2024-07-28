/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** my_calloc
*/

#include "my_string.h"
#include <stdlib.h>

void *my_calloc(size_t num_elements, size_t element_size)
{
    void *ptr = NULL;
    size_t total_size = 0;

    if (num_elements == 0 || element_size == 0)
        return NULL;
    total_size = num_elements * element_size;
    ptr = malloc(total_size);
    if (ptr != NULL)
        my_memset(ptr, 0, total_size);
    return ptr;
}
