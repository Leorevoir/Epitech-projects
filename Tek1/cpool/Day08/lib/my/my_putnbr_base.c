/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_putnbr_base
*/

#include <unistd.h>

void my_putnbr_base(int nbr, const char *base)
{
    int base_len = my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr >= base_len)
        my_putnbr_base(nbr / base_len, base);
    my_putchar(base[nbr % base_len]);
}
