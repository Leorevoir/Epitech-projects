/*
** EPITECH PROJECT, 2023
** MY_FIND_PRIME_SUP
** File description:
** Find prime
*/

int my_find_prime_sup(int nb)
{
    int a = nb;

    if (nb <= 2) {
        return (2);
    }
    while (my_is_prime(a) != 1) {
        a++;
    }
    return (a);
}
