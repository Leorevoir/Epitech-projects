/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_FACTORIAL_REC
** File description:
** Recursive factorial
*/

int my_compute_factorial_rec(int nb)
{
    if (nb < 0 || nb > 12) {
        return 0;
    } else if (nb == 0) {
        return 1;
    } else {
    return (nb * my_compute_factorial_rec(nb - 1));
    }
}
