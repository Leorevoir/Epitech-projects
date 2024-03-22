/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** mini_printf
*/

#include "../include/my_ls.h"

struct format_specifier {
    char specifier;
    format_function func;
    struct subflag *subflags_list;
};

struct format_specifier format_flag[] = {
    {'i', print_int},
    {'d', print_int},
    {'c', print_char},
    {'%', print_percent},
    {'s', print_string},
};

void print_char(va_list args)
{
    char c = va_arg(args, int);

    my_putchar(c);
}

void print_string(va_list args)
{
    char *str = va_arg(args, char *);

    my_put_str(str);
}

void print_int(va_list args)
{
    int num = va_arg(args, int);

    my_put_nbr(num);
}

void print_percent(va_list args)
{
    my_putchar('%');
}

static void process(const char *format, int *i, va_list args)
{
    size_t j = 0;
    int temp = *i;

    for (; j < sizeof(format_flag) / sizeof(format_flag[0]); j++) {
        if (*format == format_flag[j].specifier) {
            format_flag[j].func(args);
            return;
        }
    }
    my_putchar(*format);
}

static void check_percent(const char *format, int *i, va_list args)
{
    int j = *i;

    if (format[j]) {
        if (format[j] == ' ')
            process(format + j, &j, args);
        process(format + j, &j, args);
    } else
        return;
}

int my_printf(const char *format, ...)
{
    va_list args;
    int i = 0;

    va_start(args, format);
    while (format[i]) {
        if (format[i] == '%') {
            i++;
            check_percent(format, &i, args);
        } else
            my_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (0);
}
