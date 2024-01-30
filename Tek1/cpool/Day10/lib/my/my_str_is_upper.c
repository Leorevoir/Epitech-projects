/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_str_is_upper
*/

#include <unistd.h>

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 1;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return 0;
    }
    return 1;
}
