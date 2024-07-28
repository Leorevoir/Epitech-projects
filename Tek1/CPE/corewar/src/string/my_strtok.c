/*
** EPITECH PROJECT, 2024
** robot
** File description:
** my_strtok
*/

#include "my_string.h"

static char *where_is_it(char *str, const char *delim, int *found, int i)
{
    for (int j = 0; delim[j]; j++) {
        if (str[i] == delim[j]) {
            *found = 0;
            break;
        }
    }
    return str;
}

static char *find_next_token(char *str, const char *delim)
{
    int i = 0;
    int found;

    while (str[i] != '\0') {
        found = 1;
        where_is_it(str, delim, &found, i);
        if (found)
            break;
        i++;
    }
    return &str[i];
}

static char *where_is_my_token(char *str, const char *delim, int **found)
{
    for (int j = 0; delim[j] != '\0'; j++) {
        if (*str == delim[j]) {
            *str = '\0';
            **found = 1;
            break;
        }
    }
    return str;
}

static void find_other_token(char **ptr, const char *delim, int *found)
{
    while (**ptr != '\0') {
        *found = 0;
        where_is_my_token(*ptr, delim, &found);
        if (*found)
            break;
        (*ptr)++;
    }
}

char *my_strtok(char *str, const char *delim)
{
    static char *ptr = "";
    char *token = NULL;
    int found = 0;

    if (str != NULL)
        ptr = str;
    token = ptr;
    ptr = find_next_token(ptr, delim);
    find_other_token(&ptr, delim, &found);
    if (found)
        (ptr)++;
    if (*token == '\0')
        return NULL;
    else
        return token;
}
