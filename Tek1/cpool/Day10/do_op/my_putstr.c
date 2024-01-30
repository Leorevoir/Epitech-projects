/*
** EPITECH PROJECT, 2024
** Epitech-projects
** File description:
** my_putstr
*/

#include "my.h"

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}

int get_num(const char *str, long result, int sign)
{
    int digit;

    while (*str >= '0' && *str <= '9') {
        digit = *str - '0';
        if (result > (LONG_MAX - digit) / 10) {
            result = (sign == 1) ? LONG_MAX : LONG_MIN;
            break;
        }
        result = result * 10 + digit;
        str++;
    }
    return result;
}

long my_strtol(const char *str, char **endptr)
{
    long result = 0;
    int sign = 1;

    if (str == NULL || *str == '\0') {
        if (endptr != NULL)
            *endptr = (char *)str;
        return 0;
    }
    while (*str == ' ')
        str++;
    if (*str == '+' || *str == '-') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }
    result = get_num(str, result, sign);
    if (endptr != NULL)
        *endptr = (char *)str;
    return result * sign;
}

int my_strcmp(const char *a, const char *b)
{
    int i = 0;

    while (a[i] == b[i] && a[i] != '\0' && b[i] != '\0')
        i++;
    return (a[i] - b[i]);
}
