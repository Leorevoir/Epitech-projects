/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** binary_handling
*/

#include "../include/my_navy.h"

int convert_from_binary(int *binary)
{
    int number = 0;

    for (int i = 0; i < 16; i++) {
        number |= (binary[i] << i);
    }
    return number;
}

int *convert_to_binary(int number)
{
    int *binary = malloc(sizeof(int) * 16);

    if (binary == NULL)
        return NULL;
    for (int i = 0; i < 16; i++) {
        binary[i] = (number >> i) & 1;
    }
    return binary;
}
