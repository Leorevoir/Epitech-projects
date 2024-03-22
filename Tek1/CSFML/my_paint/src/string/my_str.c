/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-bsminishell1-leo.quinzler
** File description:
** my_strdup
*/

#include "my_string.h"

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] == s2[i]
        && s1[i] != '\0'
        && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i]
        && s1[i] != '\0'
        && s2[i] != '\0'
        && i < n)
        i++;
    return (s1[i] - s2[i]);
}

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src)
{
    char *dest = NULL;

    if (src == NULL)
        return (NULL);
    dest = malloc(my_strlen(src) + 1);
    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}
