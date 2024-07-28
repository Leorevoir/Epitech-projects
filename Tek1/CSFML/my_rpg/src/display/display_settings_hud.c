/*
** EPITECH PROJECT, 2024
** display_settings.c
** File description:
** display_settings
*/

#include "display.h"

void display_language(rpg_t *rpg, settings_t *sett)
{
    sfRenderWindow_drawText(rpg->window, sett->language, 0);
    sfRenderWindow_drawSprite(rpg->window, sett->english_sprite, 0);
    sfRenderWindow_drawSprite(rpg->window, sett->french_sprite, 0);
}

void display_volume(rpg_t *rpg, settings_t *sett)
{
    sfRenderWindow_drawRectangleShape(rpg->window, sett->vol_bar, 0);
    sfRenderWindow_drawCircleShape(rpg->window, sett->vol_point, 0);
    sfRenderWindow_drawText(rpg->window, sett->volume, 0);
}

void display_resolution(rpg_t *rpg, settings_t *sett)
{
    sfRenderWindow_drawSprite(rpg->window, sett->res_sprite[0], 0);
    if (sett->display_res == true) {
        sfRenderWindow_drawSprite(rpg->window, sett->res_sprite[1], 0);
        sfRenderWindow_drawText(rpg->window, sett->resfull, 0);
        sfRenderWindow_drawSprite(rpg->window, sett->res_sprite[2], 0);
        sfRenderWindow_drawText(rpg->window, sett->res1920, 0);
    }
    sfRenderWindow_drawSprite(rpg->window, sett->triangle_sprite, 0);
    sfRenderWindow_drawText(rpg->window, sett->res_choosed, 0);
    sfRenderWindow_drawText(rpg->window, sett->resolution, 0);
}

void display_music(rpg_t *rpg, settings_t *sett)
{
    sfRenderWindow_drawText(rpg->window, sett->music, 0);
    sfRenderWindow_drawSprite(rpg->window, sett->square_sprite[0], 0);
    sfRenderWindow_drawText(rpg->window, sett->sound, 0);
    sfRenderWindow_drawSprite(rpg->window, sett->square_sprite[1], 0);
    if (sett->music_check == true)
        sfRenderWindow_drawSprite(rpg->window, sett->check_sprite[0], 0);
    if (sett->sound_check == true)
        sfRenderWindow_drawSprite(rpg->window, sett->check_sprite[1], 0);
}

void display_settings_hud(rpg_t *rpg, hud_t *hud)
{
    settings_t *sett = hud->sett;

    sfRenderWindow_drawSprite(rpg->window, sett->plate_sprite, 0);
    display_language(rpg, sett);
    display_volume(rpg, sett);
    display_resolution(rpg, sett);
    display_music(rpg, sett);
    sfRenderWindow_display(rpg->window);
}
