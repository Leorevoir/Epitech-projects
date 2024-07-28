/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** lib my_put_nbr
*/

#include <unistd.h>

int my_put_nbr(int nb)
{
    long b;
    char temp;

    b = nb;
    if (b < 0) {
        b *= -1;
        write(1, "-", 1);
    }
    if (b > 0) {
        if (b / 10)
            my_put_nbr(b / 10);
        temp = 48 + (b % 10);
        write(1, &temp, 1);
    }
    if (b == 0)
        write(1, "0", 1);
}
