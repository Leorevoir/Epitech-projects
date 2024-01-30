/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** Square root int
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    if (nb < 0) {
        return 0;
    }
    while (i * i < nb) {
        i++;
    }
    if (i * i == nb) {
        return i;
    } else {
        return 0;
    }
}
