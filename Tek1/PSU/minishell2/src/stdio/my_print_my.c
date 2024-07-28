/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-bsminishell1-leo.quinzler
** File description:
** my_print_my
*/

#include "my_string.h"
#include "my_stdio.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putnbr(int num)
{
    if (num == 0) {
        my_putchar('0');
        return;
    }
    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    if (num >= 10)
        my_putnbr(num / 10);
    my_putchar(num % 10 + '0');
}

static int check_sign(const char *str, int *i)
{
    int sign = 1;

    while (str[*i] == ' ' || str[*i] == '+'
        || str[*i] == '-') {
        if (str[*i] == '-')
            sign *= -1;
        (*i)++;
    }
    if (str[*i] < '0' || str[*i] > '9')
        return 0;
    return sign;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = check_sign(str, &i);
    int res = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        if (res > 2147483647 / 10
            || (res == 2147483647 / 10
            && (str[i] - '0') > (2147483647 % 10))) {
            return 0;
        }
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res * sign;
}

void my_putstr(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

size_t my_strlen(const char *str)
{
    size_t i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}
