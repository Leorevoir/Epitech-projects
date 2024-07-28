/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** my_error
*/

#include "my_stdio.h"
#include "my_string.h"

void my_error(const char *str)
{
    write(2, str, my_strlen(str));
}

void my_error_nb(int num)
{
    if (num == 0) {
        my_error("0");
        return;
    }
    if (num < 0) {
        my_error("-");
        num = -num;
    }
    if (num >= 10)
        my_putnbr(num / 10);
    my_error(num % 10 + "0");
}
