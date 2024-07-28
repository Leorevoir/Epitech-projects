/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** night
*/

#include "display.h"

void night_vibrant(rpg_t *rpg)
{
    if (rpg->weather->night)
        sfRenderWindow_drawRectangleShape(rpg->window,
            rpg->weather->night_filter, NULL);
}
