/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** display_menu.c
*/

#include "display.h"

void display_escape_back_button(hud_t *hud, rpg_t *rpg)
{
    if (hud->chars->display == true || hud->sett->display == true)
        sfRenderWindow_drawSprite(rpg->window, hud->back_sprite, NULL);
}

static void display_language_escape_menu(rpg_t *rpg, settings_t *sett)
{
    sfRenderWindow_drawText(rpg->window, sett->language, 0);
    sfRenderWindow_drawSprite(rpg->window, sett->english_sprite, 0);
    sfRenderWindow_drawSprite(rpg->window, sett->french_sprite, 0);
}

static void display_volume_escape_menu(rpg_t *rpg, settings_t *sett)
{
    sfRenderWindow_drawRectangleShape(rpg->window, sett->vol_bar, 0);
    sfRenderWindow_drawCircleShape(rpg->window, sett->vol_point, 0);
    sfRenderWindow_drawText(rpg->window, sett->volume, 0);
}

static void display_resolution_escape_menu(rpg_t *rpg, settings_t *sett)
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

void display_music_escape_menu(rpg_t *rpg, settings_t *sett)
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

void display_settings_hude_escape_menu(rpg_t *rpg, hud_t *hud)
{
    settings_t *sett = hud->sett;

    sfRenderWindow_drawSprite(rpg->window, sett->plate_sprite, 0);
    display_language_escape_menu(rpg, sett);
    display_volume_escape_menu(rpg, sett);
    display_resolution_escape_menu(rpg, sett);
    display_music_escape_menu(rpg, sett);
}

void display_escape_menu(hud_t *hud, rpg_t *rpg)
{
    const sfView *default_view = sfRenderWindow_getDefaultView(rpg->window);

    sfRenderWindow_setView(rpg->window, default_view);
    display_escape_back_button(hud, rpg);
    if (hud->sett->display == true) {
        display_settings_hude_escape_menu(rpg, hud);
        return;
    }
    sfRenderWindow_drawSprite(rpg->window, hud->menu->save.sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, hud->menu->resume_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, hud->menu->lgame_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, hud->menu->settings_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, hud->menu->exit_sprite, NULL);
}
