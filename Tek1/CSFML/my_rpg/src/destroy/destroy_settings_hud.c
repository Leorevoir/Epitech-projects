/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** destroy_settings_hud.c
*/

#include "../../include/my_rpg.h"

static void destroy_plate(settings_t *sett)
{
    sfTexture_destroy(sett->plate);
    sfSprite_destroy(sett->plate_sprite);
}

static void destroy_language(settings_t *sett)
{
    sfText_destroy(sett->language);
    sfFont_destroy(sett->font);
    sfTexture_destroy(sett->ienglish);
    sfTexture_destroy(sett->henglish);
    sfTexture_destroy(sett->penglish);
    sfTexture_destroy(sett->ifrench);
    sfTexture_destroy(sett->hfrench);
    sfTexture_destroy(sett->pfrench);
    sfSprite_destroy(sett->english_sprite);
    sfSprite_destroy(sett->french_sprite);
    sfRectangleShape_destroy(sett->english_rect);
    sfRectangleShape_destroy(sett->french_rect);
}

static void destroy_volume(settings_t *sett)
{
    sfRectangleShape_destroy(sett->vol_bar);
    sfCircleShape_destroy(sett->vol_point);
    sfText_destroy(sett->volume);
}

static void destroy_resolution(settings_t *sett)
{
    sfSprite_destroy(sett->res_sprite[0]);
    sfSprite_destroy(sett->res_sprite[1]);
    sfSprite_destroy(sett->res_sprite[2]);
    free(sett->res_sprite);
    sfSprite_destroy(sett->triangle_sprite);
    sfTexture_destroy(sett->res_round);
    sfTexture_destroy(sett->triangle);
    sfText_destroy(sett->resolution);
    sfText_destroy(sett->res_choosed);
    sfText_destroy(sett->resfull);
    sfText_destroy(sett->res1920);
}

static void destroy_musical(settings_t *sett)
{
    sfText_destroy(sett->music);
    sfText_destroy(sett->sound);
    sfSprite_destroy(sett->square_sprite[0]);
    sfSprite_destroy(sett->square_sprite[1]);
    sfSprite_destroy(sett->check_sprite[0]);
    sfSprite_destroy(sett->check_sprite[1]);
}

void destroy_settings_hud(settings_t *sett)
{
    destroy_plate(sett);
    destroy_language(sett);
    destroy_volume(sett);
    destroy_resolution(sett);
    destroy_musical(sett);
}
