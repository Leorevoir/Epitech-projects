/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** my_htons
*/

#include "core.h"

uint16_t my_htons(uint16_t value)
{
    static const int num = 1;

    if (*(char *)&num == 1) {
        return ((value & 0xFF) << 8)
            | ((value & 0xFF00) >> 8);
    } else
        return value;
}
