/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-bsminishell1-leo.quinzler
** File description:
** my_strdup
*/

#include "my_string.h"
#include "my_stdlib.h"
#include "my_stdio.h"

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

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = 0;

    if (dest == 0 || src == 0) {
        return (0);
    }
    while (dest[a] != '\0') {
        a++;
    }
    while (src[b] != '\0') {
        dest[a] = src[b];
        a++;
        b++;
    }
    dest[a] = '\0';
    return (dest);
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

char *my_strdup(const char *str)
{
    size_t len = my_strlen(str) + 1;
    char *new = malloc(len);

    if (new == NULL)
        return NULL;
    my_memcpy(new, str, len);
    return new;
}
