/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** my_strdup
*/

#include "../include/my_ls.h"

char *my_strdup(const char *str)
{
    size_t length = 0;
    char *duplicate;

    if (str == NULL)
        return NULL;
    while (str[length] != '\0') {
        length++;
    }
    duplicate = (char *)malloc((length + 1) * sizeof(char));
    if (duplicate == NULL)
        return NULL;
    for (size_t i = 0; i <= length; i++)
        duplicate[i] = str[i];
    return duplicate;
}
