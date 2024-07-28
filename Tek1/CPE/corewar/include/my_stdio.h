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

#ifndef MY_STDIO_H_
    #define MY_STDIO_H_
    #define IS_FORMAT(c) ((c) == 's' || (c) == 'x')
    #define HEX_DIGIT(v) ((v) < 10 ? '0' + (v) : 'a' + (v) - 10)

typedef void(*format_function_t)(va_list args);

typedef struct buffer_s {
    char *buf;
    int written;
} buffer_t;

void print_char(va_list args);
void print_string(va_list args);
void print_int(va_list args);
void print_float(va_list args);
void my_putchar(char c);
void my_putnbr(int num);
void my_putstr(const char *str);
int my_getnbr(const char *str);
void print_hexa(va_list args);
void my_error(const char *str);
void my_error_nb(int num);
int my_printf(const char *format, ...);
void print_binary(va_list args);
int my_sprintf(char *s, const char *format, ...);

#endif /*MY_STDIO_H_*/
