/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** my_sprintf
*/

#include "my_stdio.h"
#include "my_string.h"

static void append_str(buffer_t *buffer, const char *str)
{
    while (*str) {
        *buffer->buf = *str;
        buffer->buf++;
        str++;
        buffer->written++;
    }
}

static void append_hex(buffer_t *buffer, unsigned int num)
{
    char hex[9];
    int i = sizeof(hex) - 2;
    int digit = 0;

    hex[sizeof(hex) - 1] = '\0';
    do {
        digit = num % 16;
        hex[i] = HEX_DIGIT(digit);
        num /= 16;
        i--;
    } while (num && i >= 0);
    append_str(buffer, &hex[i + 1]);
}

static void handle_format(buffer_t *buffer, const char **p, va_list args)
{
    char *str = NULL;
    unsigned int num = 0;

    (*p)++;
    switch (**p) {
        case 's':
            str = va_arg(args, char *);
            append_str(buffer, str);
            break;
        case 'x':
            num = va_arg(args, unsigned int);
            append_hex(buffer, num);
            break;
    }
    (*p)++;
}

int my_sprintf(char *s, const char *format, ...)
{
    va_list args;
    buffer_t buffer = {s, 0};
    const char *p = format;

    va_start(args, format);
    while (*p) {
        if (*p == '%' && IS_FORMAT(*(p + 1))) {
            handle_format(&buffer, &p, args);
        } else {
            *buffer.buf = *p;
            buffer.buf++;
            p++;
            buffer.written++;
        }
    }
    *buffer.buf = '\0';
    va_end(args);
    return buffer.written;
}
