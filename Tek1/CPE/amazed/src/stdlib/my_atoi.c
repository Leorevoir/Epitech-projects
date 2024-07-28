/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** my_atoi
*/

#include "my_stdlib.h"

int is_too_much(int *res, int *i, char *str, int sign)
{
    if (*res > INT_MAX / 10 || (*res == INT_MAX / 10
        && (str[*i] - '0') > INT_MAX % 10)) {
        if (sign == 1)
            return INT_MAX;
        else
            return INT_MIN;
    }
    *res = *res * 10 + str[*i] - '0';
    (*i)++;
    return *res;
}

int my_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;

    while (str[i] == ' ')
        i++;
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        res = is_too_much(&res, &i, str, sign);
        if (res == INT_MAX || res == INT_MIN)
            break;
    }
    return res * sign;
}
