/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-bsnavy-leo.quinzler
** File description:
** my_functions
*/

#include "../include/my_printf.h"

int my_getnbr(const char *str)
{
    int num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > '9' || str[i] < '0')
            return 84;
        num = num * 10 + str[i] - '0';
    }
    return num;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(const char *str)
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
