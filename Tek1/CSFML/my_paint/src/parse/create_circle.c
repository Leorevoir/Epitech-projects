/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** create_circle
*/

#include "button.h"

sfCircleShape *create_circle(float radius, sfVector2f pos)
{
    sfCircleShape* circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfBlack);
    sfCircleShape_setPosition(circle, pos);
    return circle;
}
