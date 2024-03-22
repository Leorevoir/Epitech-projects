/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-bsnavy-leo.quinzler
** File description:
** my_functions
*/

#include "../../include/my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int nbr = 0;

    while (str[nbr] != '\0') {
        nbr++;
    }
    return (nbr);
}

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}

void my_putnbr(int num)
{
    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    if (num >= 10) {
        my_putnbr(num / 10);
    }
    my_putchar('0' + num % 10);
}
