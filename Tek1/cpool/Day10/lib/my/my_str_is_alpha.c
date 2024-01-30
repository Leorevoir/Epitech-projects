/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_str_is_alpha
*/

#include <unistd.h>

int my_str_isalpha(char const *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z')
            return 0;
    }
    return 1;
}
