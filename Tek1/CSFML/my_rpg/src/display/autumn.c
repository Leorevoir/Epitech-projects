/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** autumn
*/

#include "display.h"

void autumn_vibrant(rpg_t *rpg)
{
    if (rpg->weather->autumn)
        sfRenderWindow_drawRectangleShape(
            rpg->window, rpg->weather->autumn_filter, NULL);
}
