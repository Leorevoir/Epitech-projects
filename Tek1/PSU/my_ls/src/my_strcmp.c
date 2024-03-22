/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-leo.quinzler
** File description:
** my_strcmp
*/

#include "../include/my_ls.h"

int	my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
        i++;
    return (s1[i] - s2[i]);
}

char *my_strcat(char *dest, const char *src)
{
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);

    for (int i = 0; i < size_src; i++) {
        dest[size_dest + i] = src[i];
    }
    dest[size_dest + size_src] = '\0';
    return dest;
}
