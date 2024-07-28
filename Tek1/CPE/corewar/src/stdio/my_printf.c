/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-bsnavy-leo.quinzler
** File description:
** my_printf
*/

#include "../../include/my_string.h"
#include "../../include/my_stdio.h"

struct format_specifier {
    char specifier;
    format_function_t func;
};

struct format_specifier format_flag[] = {
    {'d', print_int},
    {'c', print_char},
    {'f', print_float},
    {'s', print_string},
    {'b', print_binary},
    {'x', print_hexa}
};

static void process(const char *format, va_list args)
{
    size_t j = 0;

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
            process(format + j, args);
        process(format + j, args);
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
