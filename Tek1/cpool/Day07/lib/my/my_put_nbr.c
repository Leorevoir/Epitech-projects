/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_put_nbr
*/

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
    }
    my_putchar('0' + nb % 10);
}
