/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** my_revstr
*/

#include "../../include/radar.h"

char *my_revstr(char *str)
{
    int a;
    int b;
    char *rev_str = str;
    int str_size = my_strlen(str);

    for (int i = 0; i < str_size / 2; i++) {
        a = str[str_size - i - 1];
        b = str[i];
        rev_str[i] = a;
        rev_str[str_size - i - 1] = b;
    }
    return rev_str;
}

char *add_char(char *str, char c)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    str[i] = c;
    str[i + 1] = '\0';
    return str;
}
