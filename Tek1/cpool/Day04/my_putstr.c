/*
** EPITECH PROJECT, 2023
** MY_PUTSTR
** File description:
** Displays string
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
