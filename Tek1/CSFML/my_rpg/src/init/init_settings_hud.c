/*
** EPITECH PROJECT, 2024
** init_settings.c
** File description:
** init_settings
*/

#include "../../include/my_rpg.h"

static void init_plate(settings_t **sett, sfVector2f pos)
{
    (*sett)->plate = sfTexture_createFromFile(PLATE, NULL);
    (*sett)->plate_sprite = sfSprite_create();
    sfSprite_setTexture((*sett)->plate_sprite, (*sett)->plate, 0);
    sfSprite_setOrigin((*sett)->plate_sprite, (sfVector2f) {478, 478});
    sfSprite_setPosition((*sett)->plate_sprite, pos);
}

static void init_language_string(settings_t **sett, sfVector2f pos)
{
    (*sett)->language = sfText_create();
    (*sett)->font = sfFont_createFromFile(FONT);
    sfText_setFont((*sett)->language, (*sett)->font);
    sfText_setString((*sett)->language, "Language");
    pos.x -= 75;
    sfText_setPosition((*sett)->language, pos);
    sfText_setColor((*sett)->language, sfBlack);
}

static void init_language_french(settings_t **sett, sfVector2f pos)
{
    (*sett)->ifrench = sfTexture_createFromFile(I_FR, NULL);
    (*sett)->hfrench = sfTexture_createFromFile(H_FR, NULL);
    (*sett)->pfrench = sfTexture_createFromFile(P_FR, NULL);
    (*sett)->french_sprite = sfSprite_create();
    sfSprite_setTexture((*sett)->french_sprite, (*sett)->ifrench, 0);
    pos.y += 80;
    sfSprite_setPosition((*sett)->french_sprite, pos);
    sfSprite_setOrigin((*sett)->french_sprite, (sfVector2f) {115, 35});
    (*sett)->french_rect = sfRectangleShape_create();
    sfRectangleShape_setSize((*sett)->french_rect, (sfVector2f) {230, 70});
    sfRectangleShape_setOrigin((*sett)->french_rect, (sfVector2f) {115, 35});
    sfRectangleShape_setPosition((*sett)->french_rect, pos);
}

static void init_language_english(settings_t **sett, sfVector2f pos)
{
    (*sett)->ienglish = sfTexture_createFromFile(I_ENG, NULL);
    (*sett)->henglish = sfTexture_createFromFile(H_ENG, NULL);
    (*sett)->penglish = sfTexture_createFromFile(P_ENG, NULL);
    (*sett)->english_sprite = sfSprite_create();
    sfSprite_setTexture((*sett)->english_sprite, (*sett)->ienglish, 0);
    sfSprite_setPosition((*sett)->english_sprite, pos);
    sfSprite_setOrigin((*sett)->english_sprite, (sfVector2f) {114, 35});
    (*sett)->english_rect = sfRectangleShape_create();
    sfRectangleShape_setSize((*sett)->english_rect, (sfVector2f) {229, 71});
    sfRectangleShape_setOrigin((*sett)->english_rect, (sfVector2f) {114, 35});
    sfRectangleShape_setPosition((*sett)->english_rect, pos);
}

static void init_sound_bar(settings_t **sett, sfVector2f pos)
{
    sfVector2f position;

    (*sett)->vol_bar = sfRectangleShape_create();
    sfRectangleShape_setSize((*sett)->vol_bar, (sfVector2f) {600, 6});
    sfRectangleShape_setFillColor((*sett)->vol_bar, sfBlack);
    sfRectangleShape_setOrigin((*sett)->vol_bar, (sfVector2f) {300, 3});
    sfRectangleShape_setPosition((*sett)->vol_bar, pos);
    (*sett)->vol_point = sfCircleShape_create();
    sfCircleShape_setRadius((*sett)->vol_point, 20);
    sfCircleShape_setFillColor((*sett)->vol_point, sfBlack);
    position = sfCircleShape_getPosition((*sett)->vol_point);
    position.x = position.x + 20;
    position.y = position.y + 20;
    sfCircleShape_setOrigin((*sett)->vol_point, position);
    pos.x += 300;
    sfCircleShape_setPosition((*sett)->vol_point, pos);
}

void init_volume_string(settings_t **sett, sfVector2f pos)
{
    (*sett)->volume = sfText_create();
    sfText_setFont((*sett)->volume, (*sett)->font);
    sfText_setString((*sett)->volume, "Volume");
    pos.y -= 90;
    sfText_setPosition((*sett)->volume, pos);
    sfText_setColor((*sett)->volume, sfBlack);
    sfText_setOrigin((*sett)->volume, (sfVector2f) {50, 5});
}

void init_settings_hud(hud_t **hud, rpg_t *rpg)
{
    sfVector2u size = sfRenderWindow_getSize(rpg->window);
    sfVector2f pos = {size.x / 2, size.y / 2};

    (*hud)->sett = malloc(sizeof(settings_t));
    (*hud)->sett->res_sprite = malloc(sizeof(sfSprite *) * 2);
    (*hud)->sett->display = false;
    (*hud)->sett->display_res = false;
    rpg->volume = 100;
    init_plate(&(*hud)->sett, pos);
    pos.y -= 370;
    init_language_string(&(*hud)->sett, pos);
    pos.y += 100;
    init_language_english(&(*hud)->sett, pos);
    init_language_french(&(*hud)->sett, pos);
    pos.y = size.y / 2;
    init_sound_bar(&(*hud)->sett, pos);
    init_volume_string(&(*hud)->sett, pos);
    pos.x -= 200;
    pos.y += 170;
    init_all_res(&(*hud)->sett, pos);
}
