/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** my_str
*/

#include "../include/sokoban.h"

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}

int my_strcmp(const char *s1, const char *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
