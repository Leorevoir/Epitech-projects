/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_window
*/

#include "my_rpg.h"

static void update_fullscreen(rpg_t *rpg, settings_t *sett)
{
    if ((strcmp(sfText_getString(sett->res_choosed), "Fullscreen") == 0
    || strcmp(sfText_getString(sett->res_choosed), "Plein ecran") == 0)
    && (rpg->resolution == DFLT || rpg->resolution == TWOK)) {
        sfRenderWindow_close(rpg->window);
        sfRenderWindow_destroy(rpg->window);
        rpg->window = sfRenderWindow_create(
            (sfVideoMode){DFLT_HEIGHT, DFLT_WIDTH, 32}, "Little Adventure",
            sfFullscreen | sfClose, NULL);
        sfRenderWindow_setFramerateLimit(rpg->window, 60);
        rpg->resolution = FULLSCREEN;
        return;
    }
}

void update_window(rpg_t *rpg, settings_t *sett)
{
    if ((strcmp(sfText_getString(sett->res_choosed), "1920x1080") == 0)
    && (rpg->resolution == FULLSCREEN || rpg->resolution == TWOK)) {
        sfRenderWindow_close(rpg->window);
        sfRenderWindow_destroy(rpg->window);
        init_window(rpg);
        return;
    }
    update_fullscreen(rpg, sett);
    if ((strcmp(sfText_getString(sett->res_choosed), "2048x1080") == 0)
    && (rpg->resolution == DFLT || rpg->resolution == FULLSCREEN)) {
        sfRenderWindow_close(rpg->window);
        sfRenderWindow_destroy(rpg->window);
        rpg->window = sfRenderWindow_create(
        (sfVideoMode){TWOK_HEIGHT, TWOK_WIDTH, 32}, "Little Adventure",
        sfResize | sfClose, NULL);
        sfRenderWindow_setFramerateLimit(rpg->window, 60);
        rpg->resolution = TWOK;
        return;
    }
}
