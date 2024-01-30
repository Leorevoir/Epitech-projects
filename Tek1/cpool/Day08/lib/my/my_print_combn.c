/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_print_combn
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}

void print_combn_recursive(int n, int current, int digits[])
{
    int start;

    if (n == 0) {
        for (int i = 0; i < current; i++)
            my_putchar(digits[i] + '0');
        if (current < 10 - n) {
            my_putchar(',');
            my_putchar(' ');
        }
        return;
    }
    start = (current == 0) ? 0 : digits[current - 1] + 1;
    for (int i = start; i <= 9; i++) {
        digits[current] = i;
        print_combn_recursive(n - 1, current + 1, digits);
    }
}

int my_print_combn(int n)
{
    int digits[10];

    if (n < 1 || n > 10) {
        return 1;
    }
    print_combn_recursive(n, 0, digits);
    my_putchar('\n');
    return 0;
}
