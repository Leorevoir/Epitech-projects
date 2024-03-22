/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** my_memcpy
*/

#include "minishell.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *dest_char = NULL;
    const char *src_char = NULL;

    if (dest == NULL || src == NULL)
        return NULL;
    dest_char = dest;
    src_char = src;
    if (dest_char == src_char)
        return dest;
    if (dest_char < src_char && src_char < dest_char + n)
        return NULL;
    for (size_t i = 0; i < n; i++) {
        dest_char[i] = src_char[i];
    }
    return (dest);
}
