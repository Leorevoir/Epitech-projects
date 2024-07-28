/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-robotfactory-leo.quinzler
** File description:
** my_memcpy
*/

#include "my_stdlib.h"

void my_memcpy(void *dest, void *src, size_t n)
{
    char *str_src = (char *)src;
    char *str_dest = (char *)dest;

    for (size_t i = 0; i < n; i++) {
        str_dest[i] = str_src[i];
    }
}
