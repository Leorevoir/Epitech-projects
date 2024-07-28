/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** init_menu.c
*/

#include "../../include/my_rpg.h"

static void init_back(hud_t **hud)
{
    (*hud)->menu->back = sfTexture_createFromFile(BACKGROUND, NULL);
    (*hud)->menu->back_sprite = sfSprite_create();
    sfSprite_setScale((*hud)->menu->back_sprite, (sfVector2f) {1.1, 1.1});
    sfSprite_setTexture((*hud)->menu->back_sprite, (*hud)->menu->back, 0);
}

void init_name(hud_t *hud, sfVector2f pos)
{
    hud->menu->name = sfTexture_createFromFile(NAME, NULL);
    hud->menu->name_sprite = sfSprite_create();
    sfSprite_setScale(hud->menu->name_sprite, (sfVector2f) {0.8, 0.8});
    sfSprite_setTexture(hud->menu->name_sprite, hud->menu->name, 0);
    sfSprite_setOrigin(hud->menu->name_sprite, (sfVector2f){646, 271});
    pos.y -= 400;
    sfSprite_setPosition(hud->menu->name_sprite, pos);
}

static void init_ngame(hud_t **hud, sfVector2f pos)
{
    (*hud)->menu->ingame_eng = sfTexture_createFromFile(I_NGAME_ENG, NULL);
    (*hud)->menu->hngame_eng = sfTexture_createFromFile(H_NGAME_ENG, NULL);
    (*hud)->menu->pngame_eng = sfTexture_createFromFile(P_NGAME_ENG, NULL);
    (*hud)->menu->ingame_fr = sfTexture_createFromFile(I_NGAME_FR, NULL);
    (*hud)->menu->hngame_fr = sfTexture_createFromFile(H_NGAME_FR, NULL);
    (*hud)->menu->pngame_fr = sfTexture_createFromFile(P_NGAME_FR, NULL);
    (*hud)->menu->ngame_sprite = sfSprite_create();
    sfSprite_setTexture((*hud)->menu->ngame_sprite,
        (*hud)->menu->ingame_eng, 0);
    sfSprite_setOrigin((*hud)->menu->ngame_sprite, (sfVector2f) {114, 35});
    sfSprite_setPosition((*hud)->menu->ngame_sprite, pos);
    (*hud)->menu->ngame_rect = sfRectangleShape_create();
    sfRectangleShape_setSize((*hud)->menu->ngame_rect, (sfVector2f) {229, 70});
    sfRectangleShape_setOrigin((*hud)->menu->ngame_rect,
        (sfVector2f) {114, 35});
    sfRectangleShape_setPosition((*hud)->menu->ngame_rect, pos);
    sfRectangleShape_setFillColor((*hud)->menu->ngame_rect, sfTransparent);
}

static void init_lgame(hud_t **hud, sfVector2f pos)
{
    (*hud)->menu->ilgame_eng = sfTexture_createFromFile(I_LGAME_ENG, NULL);
    (*hud)->menu->hlgame_eng = sfTexture_createFromFile(H_LGAME_ENG, NULL);
    (*hud)->menu->plgame_eng = sfTexture_createFromFile(P_LGAME_ENG, NULL);
    (*hud)->menu->ilgame_fr = sfTexture_createFromFile(I_LGAME_FR, NULL);
    (*hud)->menu->hlgame_fr = sfTexture_createFromFile(H_LGAME_FR, NULL);
    (*hud)->menu->plgame_fr = sfTexture_createFromFile(P_LGAME_FR, NULL);
    (*hud)->menu->lgame_sprite = sfSprite_create();
    sfSprite_setTexture((*hud)->menu->lgame_sprite,
        (*hud)->menu->ilgame_eng, 0);
    sfSprite_setOrigin((*hud)->menu->lgame_sprite, (sfVector2f) {115, 35});
    sfSprite_setPosition((*hud)->menu->lgame_sprite, pos);
    (*hud)->menu->lgame_rect = sfRectangleShape_create();
    sfRectangleShape_setSize((*hud)->menu->lgame_rect, (sfVector2f) {230, 70});
    sfRectangleShape_setOrigin((*hud)->menu->lgame_rect, (sfVector2f)
        {115, 35});
    sfRectangleShape_setPosition((*hud)->menu->lgame_rect, pos);
    sfRectangleShape_setFillColor((*hud)->menu->lgame_rect, sfTransparent);
}

static void init_settings(hud_t **hud, sfVector2f pos)
{
    (*hud)->menu->isetting_eng = sfTexture_createFromFile(I_SETTING_ENG, NULL);
    (*hud)->menu->hsetting_eng = sfTexture_createFromFile(H_SETTING_ENG, NULL);
    (*hud)->menu->psetting_eng = sfTexture_createFromFile(P_SETTING_ENG, NULL);
    (*hud)->menu->isetting_fr = sfTexture_createFromFile(I_SETTING_FR, NULL);
    (*hud)->menu->hsetting_fr = sfTexture_createFromFile(H_SETTING_FR, NULL);
    (*hud)->menu->psetting_fr = sfTexture_createFromFile(P_SETTING_FR, NULL);
    (*hud)->menu->settings_sprite = sfSprite_create();
    sfSprite_setTexture((*hud)->menu->settings_sprite,
        (*hud)->menu->isetting_eng, 0);
    sfSprite_setOrigin((*hud)->menu->settings_sprite,
        (sfVector2f) {115, 35.5});
    sfSprite_setPosition((*hud)->menu->settings_sprite, pos);
    (*hud)->menu->setting_rect = sfRectangleShape_create();
    sfRectangleShape_setSize((*hud)->menu->setting_rect,
        (sfVector2f) {229, 71});
    sfRectangleShape_setOrigin((*hud)->menu->setting_rect,
        (sfVector2f) {115, 35.5});
    sfRectangleShape_setPosition((*hud)->menu->setting_rect, pos);
    sfRectangleShape_setFillColor((*hud)->menu->setting_rect, sfTransparent);
}

static void init_exit(hud_t **hud, sfVector2f pos)
{
    (*hud)->menu->iexit_eng = sfTexture_createFromFile(I_EXIT_ENG, NULL);
    (*hud)->menu->hexit_eng = sfTexture_createFromFile(H_EXIT_ENG, NULL);
    (*hud)->menu->pexit_eng = sfTexture_createFromFile(P_EXIT_ENG, NULL);
    (*hud)->menu->iexit_fr = sfTexture_createFromFile(I_EXIT_FR, NULL);
    (*hud)->menu->hexit_fr = sfTexture_createFromFile(H_EXIT_FR, NULL);
    (*hud)->menu->pexit_fr = sfTexture_createFromFile(P_EXIT_FR, NULL);
    (*hud)->menu->exit_sprite = sfSprite_create();
    sfSprite_setTexture((*hud)->menu->exit_sprite, (*hud)->menu->iexit_eng, 0);
    sfSprite_setOrigin((*hud)->menu->exit_sprite, (sfVector2f) {115, 35.5});
    sfSprite_setPosition((*hud)->menu->exit_sprite, pos);
    (*hud)->menu->exit_rect = sfRectangleShape_create();
    sfRectangleShape_setSize((*hud)->menu->exit_rect,
        (sfVector2f) {229, 71});
    sfRectangleShape_setOrigin((*hud)->menu->exit_rect,
        (sfVector2f) {115, 35.5});
    sfRectangleShape_setPosition((*hud)->menu->exit_rect, pos);
    sfRectangleShape_setFillColor((*hud)->menu->exit_rect, sfTransparent);
}

void init_back_button(hud_t **hud, sfVector2f pos)
{
    (*hud)->iback_eng = sfTexture_createFromFile(I_BACK_ENG, NULL);
    (*hud)->hback_eng = sfTexture_createFromFile(H_BACK_ENG, NULL);
    (*hud)->pback_eng = sfTexture_createFromFile(P_BACK_ENG, NULL);
    (*hud)->iback_fr = sfTexture_createFromFile(I_BACK_FR, NULL);
    (*hud)->hback_fr = sfTexture_createFromFile(H_BACK_FR, NULL);
    (*hud)->pback_fr = sfTexture_createFromFile(P_BACK_FR, NULL);
    (*hud)->back_sprite = sfSprite_create();
    sfSprite_setTexture((*hud)->back_sprite, (*hud)->iback_eng, 0);
    sfSprite_setOrigin((*hud)->back_sprite, (sfVector2f) {114, 35});
    pos.x -= 800;
    pos.y = 80;
    sfSprite_setPosition((*hud)->back_sprite, pos);
    (*hud)->back_rect = sfRectangleShape_create();
    sfRectangleShape_setSize((*hud)->back_rect,
        (sfVector2f) {229, 70});
    sfRectangleShape_setOrigin((*hud)->back_rect,
        (sfVector2f) {114, 35});
    sfRectangleShape_setPosition((*hud)->back_rect, pos);
    sfRectangleShape_setFillColor((*hud)->back_rect, sfTransparent);
}

void init_menu(hud_t **hud, rpg_t *rpg)
{
    sfVector2u size = sfRenderWindow_getSize(rpg->window);
    sfVector2f pos = {size.x / 2, size.y / 1.7};

    *hud = malloc(sizeof(hud_t));
    (*hud)->menu = malloc(sizeof(menu_t));
    (*hud)->display = true;
    (*hud)->menu->escape = false;
    init_players(*hud);
    init_back(hud);
    init_name(*hud, pos);
    init_ngame(hud, pos);
    pos.y += 100;
    init_lgame(hud, pos);
    pos.y += 100;
    init_settings(hud, pos);
    pos.y += 100;
    init_exit(hud, pos);
    init_back_button(hud, pos);
}
