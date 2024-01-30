/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_str_is_num
*/

#include <unistd.h>

int my_str_isnum(char const *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}
