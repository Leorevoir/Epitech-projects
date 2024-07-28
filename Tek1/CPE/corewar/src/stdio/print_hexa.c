/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** print_hexa
*/

#include "my_stdio.h"

void print_hexaneg(int num, int i)
{
    if (num < 0)
        for (int j = 0; j < i; j++)
            my_putchar('f');
    if (num == 0)
        my_putchar('0');
}

void print_hexadec(int num)
{
    char numbers[8];
    char charhexa;
    int i = 8;
    unsigned int hexnum = num;
    int lastnum;

    while (hexnum != 0) {
        lastnum = hexnum % 16;
        if (lastnum < 10) {
            charhexa = lastnum + '0';
        } else
            charhexa = (lastnum - 10) + 'a';
        i--;
        numbers[i] = charhexa;
        hexnum /= 16;
    }
    if (num < 0 || num == 0)
        print_hexaneg(num, i);
    for (int j = i; j < 8; j++)
        my_putchar(numbers[j]);
}

void print_hexa(va_list args)
{
    int num = va_arg(args, int);

    print_hexadec(num);
}
