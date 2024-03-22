/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-bsminishell1-leo.quinzler
** File description:
** my_error
*/

#include "my_string.h"

char *my_strrchr(const char *str, int c)
{
    char *ptr = NULL;

    if (str == NULL)
        return NULL;
    while (*str != '\0') {
        if (*str == c)
            ptr = (char *)str;
        str++;
    }
    if (*str == c)
        ptr = (char *)str;
    return ptr;
}
