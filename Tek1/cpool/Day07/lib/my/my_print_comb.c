/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_print_comb
*/

#include <unistd.h>

void my_print(int i, int j)
{
    for (int k = j + 1; k <= 9; k++) {
        my_putchar(i + '0');
        my_putchar(j + '0');
        my_putchar(k + '0');
        if (i != 7 || j != 8 || k != 9) {
            my_putchar(',');
            my_putchar(' ');
        }
    }
}

int my_print_comb(void)
{
    for (int i = 0; i <= 7; i++) {
        for (int j = i + 1; j <= 8; j++)
            my_print(i, j);
        }
    my_putchar('\n');
    return 0;
}
