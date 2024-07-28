/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_music
*/

#include "my_rpg.h"

void destroy_music(rpg_t *rpg)
{
    sfMusic_destroy(rpg->music.boss);
    sfMusic_destroy(rpg->music.road);
    sfMusic_destroy(rpg->music.menu);
    sfMusic_destroy(rpg->music.village);
    sfMusic_destroy(rpg->music.win);
    sfMusic_destroy(rpg->music.lose);
    sfMusic_destroy(rpg->music.swing_sound);
    sfMusic_destroy(rpg->music.heal_sound);
}
