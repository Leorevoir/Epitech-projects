/*
** EPITECH PROJECT, 2023
** my_put
** File description:
** my_put functions
*/

#include "../include/my_ls.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int num)
{
    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    if (num >= 10)
        my_put_nbr(num / 10);
    my_putchar('0' + num % 10);
}

int my_strlen(const char *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++);
    return i;
}

void my_put_str(char *str)
{
    write(1, str, my_strlen(str));
}

char *my_strcpy(char *dest, char const *src)
{
    int	i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
