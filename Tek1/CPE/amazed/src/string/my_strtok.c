/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-robotfactory-leo.quinzler
** File description:
** my_strtok
*/

#include "my_string.h"

char *my_strtok_helper(char *last, const char *delim)
{
    char *token;
    int found;

    token = last;
    while (*token && my_strchr(delim, *token))
        token++;
    if (*token == '\0')
        return NULL;
    while (*last) {
        found = (my_strchr(delim, *last) != NULL);
        if (found) {
            *last = '\0';
            last++;
            break;
        }
        last++;
    }
    if (!*last)
        last = NULL;
    return token;
}

char *my_strtok(char *str, const char *delim)
{
    static char *last = NULL;
    char *token;

    if (str) {
        last = str;
    }
    if (!last || *last == '\0') {
        return NULL;
    }
    token = my_strtok_helper(last, delim);
    return token;
}
