/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_POWER_REC
** File description:
** Nb power raised recursive
*/

int my_compute_power_rec(int nb, int p)
{
    int temp;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        temp = my_compute_power_rec(nb, p / 2);
        return (temp * temp);
    } else {
        return (nb * my_compute_power_rec(nb, p - 1));
    }
}
