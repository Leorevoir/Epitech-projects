/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_str_is_lower
*/

#include <unistd.h>

int my_str_islower(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 1;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return 0;
    }
    return 1;
}
