/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-robotfactory-leo.quinzler
** File description:
** my_strrchr
*/

#include "my_string.h"
#include "my_stdio.h"

char *my_strchr(const char *str, int c)
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
