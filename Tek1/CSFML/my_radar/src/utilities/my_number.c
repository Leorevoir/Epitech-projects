/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** my_number
*/

#include "../../include/radar.h"

int is_number(char const *string)
{
    for (unsigned long i = 0; string[i] != '\0'; i++)
        if (string[i] < '0' || string[i] > '9')
            return 0;
    return 1;
}

unsigned int str_to_int(char const *string)
{
    unsigned int number = 0;

    for (unsigned long i = 0; string[i] != '\0'; i++)
        number = number * 10 + string[i] - '0';
    return number;
}

char *number_to_string(int nb)
{
    char *str = malloc(sizeof(char) * 50);

    str[0] = '\0';
    do {
        add_char(str, nb % 10 + '0');
        nb /= 10;
    } while (nb > 0);
    return my_revstr(str);
}
