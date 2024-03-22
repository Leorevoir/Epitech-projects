/*
** EPITECH PROJECT, 2024
** secured
** File description:
** my_put_nbr
*/


#include <unistd.h>
#include "../../include/hashtable.h"

int my_put_nbr(int nb)
{
    int rest;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            rest = nb % 10;
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar(48 + rest);
        } else {
            my_putchar(48 + nb % 10);
        }
    }
    return (0);
}
