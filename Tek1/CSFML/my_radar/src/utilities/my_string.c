/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** my_str
*/

#include "../../include/radar.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

char *my_strndup(char const *string, unsigned long n)
{
    char *copy = malloc((n + 1) * sizeof(char));

    for (unsigned long i = 0; i < n; i++)
        copy[i] = string[i];
    copy[n] = '\0';
    return copy;
}

int my_strcmp(char const *s1, char const *s2)
{
    unsigned int i = 0;

    while (s1[i] == s2[i] && s1[i])
        i++;
    return s1[i] - s2[i];
}
