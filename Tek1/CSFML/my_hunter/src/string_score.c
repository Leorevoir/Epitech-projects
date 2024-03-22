/*
** EPITECH PROJECT, 2023
** string score
** File description:
** my itoa
*/

#include "../include/game.h"

void my_reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char *my_itoa(int num, char *str)
{
    int i = 0;
    int is_neg = 0;

    if (num < 0) {
        is_neg = 1;
        num = -num;
    }
    do {
        str[i] = num % 10 + '0';
        i++;
        num = num / 10;
    } while (num);
    if (is_neg) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    my_reverse(str, i);
    return str;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
