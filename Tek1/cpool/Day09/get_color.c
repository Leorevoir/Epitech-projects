/*
** EPITECH PROJECT, 2024
** Epitech-projects
** File description:
** get_color
*/

#include "include/my.h"

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    return (red << 16) + (green << 8) + blue;
}
