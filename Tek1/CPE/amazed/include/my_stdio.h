/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** my_stdio
*/

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "macro.h"

#ifndef MY_STDIO_H_
    #define MY_STDIO_H_

typedef void(*format_function_t)(va_list args);

void print_char(va_list args);
void print_string(va_list args);
void print_int(va_list args);
void print_float(va_list args);
void my_putchar(char c);
void my_putnbr(int num);
void my_putstr(const char *str);
int my_getnbr(const char *str);
int my_printf(const char *format, ...);

#endif /*MY_STDIO_H_*/
