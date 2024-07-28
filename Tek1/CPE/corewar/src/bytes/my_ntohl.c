/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** my_ntohl
*/

#include "core.h"

uint32_t my_ntohl(uint32_t value)
{
    static const int num = 1;

    if (*(char *)&num == 1) {
        return ((value & 0xFF) << 24)
            | ((value & 0xFF00) << 8)
            | ((value & 0xFF0000) >> 8)
            | ((value & 0xFF000000) >> 24);
    } else
        return value;
}
