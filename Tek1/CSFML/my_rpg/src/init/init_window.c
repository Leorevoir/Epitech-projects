/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_window
*/

#include "my_rpg.h"

void init_window(rpg_t *rpg)
{
    sfVideoMode mode = {DFLT_HEIGHT, DFLT_WIDTH, 32};

    rpg->window = sfRenderWindow_create(mode, "Little Adventure",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->window, 60);
    rpg->resolution = DFLT;
}
