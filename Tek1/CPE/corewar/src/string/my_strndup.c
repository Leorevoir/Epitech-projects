/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_strndup
*/

#include "my_stdlib.h"
#include "my_string.h"

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
