/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_strdup
*/

#include <stdlib.h>

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
