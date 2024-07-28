/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** display_big_boss
*/

#include "display.h"

void display_big_boss(rpg_t *rpg, boss_t *boss)
{
    DRAW_SPRITE(rpg->window, boss->object.sprite, NULL);
    if (boss->fx.display_smoke) {
        DRAW_SPRITE(rpg->window, boss->fx.smoke1.sprite, NULL);
        DRAW_SPRITE(rpg->window, boss->fx.smoke2.sprite, NULL);
        DRAW_SPRITE(rpg->window, boss->fx.smoke3.sprite, NULL);
        DRAW_SPRITE(rpg->window, boss->fx.smoke4.sprite, NULL);
    }
    if (boss->fx.display_rocket)
        DRAW_SPRITE(rpg->window, boss->fx.rocket.sprite, NULL);
    if (boss->fx.display_red) {
        DRAW_SPRITE(rpg->window, boss->fx.red1.sprite, NULL);
        DRAW_SPRITE(rpg->window, boss->fx.red2.sprite, NULL);
    }
}
