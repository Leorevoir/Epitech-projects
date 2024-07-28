/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** print_binary
*/

#include "my_stdio.h"

void print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int binary[32];
    int i = 0;

    if (num == 0) {
        my_putchar('0');
        return;
    }
    while (num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_putnbr(binary[j]);
    }
}
