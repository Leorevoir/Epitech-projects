/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** my_check_file
*/

#include "../include/my_printf.h"
#include "../include/my_navy.h"

int check_letter(char cpos1, char cpos2)
{
    if (cpos1 < 'A' || cpos1 > 'H')
        return 84;
    if (cpos2 < 'A' || cpos2 > 'H')
        return 84;
    return 0;
}

int check_format_letter(int length, char cpos1, char cpos2)
{
    if (cpos1 - cpos2 != (length - 1) && cpos1 - cpos2 != -(length - 1))
        return 84;
    return 0;
}

int check_length(ship_t *ship)
{
    if (ship->length < 2 || ship->length > 5)
        return 84;
    if (ship->ipos1 - ship->ipos2 != (ship->length - 1)
    && ship->ipos1 - ship->ipos2 != -(ship->length - 1)) {
        if (ship->ipos1 != ship->ipos2)
            return 84;
        if (ship->ipos1 == ship->ipos2)
            return check_format_letter(ship->length, ship->cpos1, ship->cpos2);
    }
    if (ship->cpos1 != ship->cpos2)
        return 84;
    return 0;
}

int check_int(ship_t *ship)
{
    if (ship->ipos2 < 1 || ship->ipos2 > 8)
        return 84;
    if (ship->ipos1 < 1 || ship->ipos1 > 8)
        return 84;
    return 0;
}
