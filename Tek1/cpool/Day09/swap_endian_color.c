/*
** EPITECH PROJECT, 2024
** Epitech-projects
** File description:
** swap_endian_color
*/

#include "include/my.h"

union color {
    struct {
        int b : 8;
        int g : 8;
        int r : 8;
        int a : 8;
    } byte;
    int full_color;
};

int swap_endian_color(int color)
{
    union color u;

    u.full_color = color;
    return (u.byte.b << 24) | (u.byte.g << 16) | (u.byte.r << 8) | u.byte.a;
}
