/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-leo.quinzler
** File description:
** my_sort
*/

#include "../include/my_ls.h"

int compare_names(char *a, char *b)
{
    return my_strcmp(a, b);
}

void sort_my(char **arg, int i, int j)
{
    char *temp;

    if (compare_names(arg[j], arg[j + 1]) > 0) {
        temp = arg[j];
        arg[j] = arg[j + 1];
        arg[j + 1] = temp;
    }
}

void my_sort(char **arg, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
            sort_my(arg, i, j);
    }
}
