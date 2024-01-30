/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_sort_in_array
*/

#include <stdio.h>

int swap_my_array(int *array, int swapped, int i)
{
    int temp;

    if (array[i] > array[i + 1]) {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = 1;
    }
    return swapped;
}

void my_sort_int_array(int *array, int size)
{
    int swapped;

    do {
        swapped = 0;
        for (int i = 0; i < size - 1; i++) {
            swapped = swap_my_array(array, swapped, i);
        }
    } while (swapped);
}
