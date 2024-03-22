/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** my_atoi
*/

#include "../../include/my_navy.h"

int my_atoi(char *str)
{
    int i = 0;
    int res = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        res = res * 10 + str[i] - '0';
        i++;
    }
    return res;
}
