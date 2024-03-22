/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** my_strlen
*/

#include "my_string.h"

void my_error(const char *error)
{
    write(2, error, my_strlen(error));
}

size_t my_strlen(const char *str)
{
    size_t i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
