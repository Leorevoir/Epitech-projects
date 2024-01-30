/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_compute_factorial_it
*/

int my_compute_factorial_it(int nb)
{
    int i;
    int fact = 1;

    if (nb < 0 || nb > 12)
        return 0;
    if (nb == 0 || nb == 1)
        return 1;
    for (i = 2; i <= nb; i++)
        fact = fact * i;
    return (fact);
}
