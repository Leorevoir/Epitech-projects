/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_POWER_IT
** File description:
** Raise to the power
*/

int my_compute_power_it(int nb, int p)
{
    int i;
    int temp = 1;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    for (i = 0; i < p; i++) {
        temp *= nb;
    }
    return temp;
}
