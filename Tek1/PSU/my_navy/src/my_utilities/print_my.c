/*
** EPITECH PROJECT, 2023
** print int
** File description:
** print int
*/

#include "../../include/my_printf.h"

static void my_float(int prec, int integer, double dec)
{
    my_putnbr(integer);
    my_putchar('.');
    if (prec > 0) {
        dec = dec < 0 ? -dec : dec;
        for (int i = 0; i < prec; i++) {
            dec *= 10;
            my_putnbr((int)dec);
            dec -= (int)dec;
        }
    }
}

static void print_floatvoid(double num)
{
    int prec = 6;
    int integer = (int)num;
    double dec = num - integer;

    if (num != num) {
        if (num > 0.0)
            my_putstr("nan");
        else
            my_putstr("-nan");
        return;
    }
    if (num == 1.0 / 0.0) {
        my_putstr("inf");
        return;
    }
    if (num == -1.0 / 0.0) {
        my_putstr("-inf");
        return;
    }
    my_float(prec, integer, dec);
}

void print_char(va_list args)
{
    char c = va_arg(args, int);

    my_putchar(c);
}

void print_float(va_list args)
{
    double num = va_arg(args, double);

    print_floatvoid(num);
}

void print_int(va_list args)
{
    int num = va_arg(args, int);

    my_putnbr(num);
}

void print_string(va_list args)
{
    char *str = va_arg(args, char *);

    my_putstr(str);
}
