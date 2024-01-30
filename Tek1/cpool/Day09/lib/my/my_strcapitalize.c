/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_strcapitalize
*/

#include <stdio.h>
#include <string.h>

char to_lowercase(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

char to_uppercase(char c)
{
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    return 1;
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int capitalize_next = 1;

    while (str[i] != '\0') {
        if (capitalize_next) {
            str[i] = to_uppercase(str[i]);
            capitalize_next = 0;
        } else
            str[i] = to_lowercase(str[i]);
        if (str[i] == ' ' || str[i] == '-'
            || str[i] == '\'' || str[i] == '+') {
            capitalize_next = 1;
            capitalize_next = is_digit(str[i]);
        }
        i++;
    }
    return str;
}
