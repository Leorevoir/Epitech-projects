/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_str_is_printable
*/

#include <unistd.h>

int my_str_isprintable(char const *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126)
            return 0;
    }
    return 1;
}
