/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** mini printf header
*/

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#ifndef MINI_PRINTF_H
    #define MINI_PRINTF_H

typedef void(*format_function)(va_list args);

void print_char(va_list args);
void print_string(va_list args);
void print_int(va_list args);
void print_float(va_list args);
void my_putchar(char c);
void my_putnbr(int num);
void my_putstr(const char *str);
int my_getnbr(const char *str);
int my_printf(const char *format, ...);

#endif /*MINI_PRINTF_H*/
