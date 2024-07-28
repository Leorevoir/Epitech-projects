/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-bsminishell1-leo.quinzler
** File description:
** my_error
*/

#include "my_string.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strndup(const char *str, int n)
{
    int length;
    char *new_str;

    if (!str)
        return NULL;
    length = my_strlen(str);
    length = (n < length) ? n : length;
    new_str = malloc(length + 1);
    if (!new_str)
        return NULL;
    for (int i = 0; i < length; i++)
        new_str[i] = str[i];
    new_str[length] = '\0';
    return new_str;
}

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
