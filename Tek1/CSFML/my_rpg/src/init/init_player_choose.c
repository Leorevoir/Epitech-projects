/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** init_player_choose.c
*/

#include "../../include/my_rpg.h"

static void init_log(characters_t **chars, sfVector2f pos)
{
    (*chars)->log = sfTexture_createFromFile(LOG, NULL);
    (*chars)->log_sprite = sfSprite_create();
    sfSprite_setTexture((*chars)->log_sprite, (*chars)->log, 0);
    sfSprite_setScale((*chars)->log_sprite, (sfVector2f) {0.7, 0.7});
    sfSprite_setOrigin((*chars)->log_sprite, (sfVector2f) {214, 174});
    pos.y += 300;
    sfSprite_setPosition((*chars)->log_sprite, pos);
}

static void init_boy(characters_t **chars, sfVector2f pos)
{
    (*chars)->boy = sfTexture_createFromFile(FACE_BOY, NULL);
    (*chars)->boy_sprite = sfSprite_create();
    sfSprite_setTexture((*chars)->boy_sprite, (*chars)->boy, 0);
    sfSprite_setScale((*chars)->boy_sprite, (sfVector2f) {4, 4});
    sfSprite_setOrigin((*chars)->boy_sprite, (sfVector2f) {19, 19});
    pos.y -= 200;
    pos.x -= 530;
    sfSprite_setPosition((*chars)->boy_sprite, pos);
    (*chars)->boy_rect = sfRectangleShape_create();
    (*chars)->cadre_boy = sfSprite_create();
    sfSprite_setTexture((*chars)->cadre_boy, (*chars)->cadre, 0);
    sfSprite_setScale((*chars)->cadre_boy, (sfVector2f) {4, 4});
    sfSprite_setOrigin((*chars)->cadre_boy, (sfVector2f) {24, 24});
    sfSprite_setPosition((*chars)->cadre_boy, pos);
    sfRectangleShape_setFillColor((*chars)->boy_rect, sfTransparent);
    sfRectangleShape_setSize((*chars)->boy_rect, (sfVector2f) {48, 48});
    sfRectangleShape_setOrigin((*chars)->boy_rect, (sfVector2f) {24, 24});
    sfRectangleShape_setScale((*chars)->boy_rect, (sfVector2f) {4, 4});
    sfRectangleShape_setPosition((*chars)->boy_rect, pos);
}

static void init_frog(characters_t **chars, sfVector2f pos)
{
    (*chars)->frog = sfTexture_createFromFile(FACE_FROG, NULL);
    (*chars)->frog_sprite = sfSprite_create();
    sfSprite_setTexture((*chars)->frog_sprite, (*chars)->frog, 0);
    sfSprite_setScale((*chars)->frog_sprite, (sfVector2f) {4, 4});
    sfSprite_setOrigin((*chars)->frog_sprite, (sfVector2f) {19, 19});
    pos.y -= 200;
    sfSprite_setPosition((*chars)->frog_sprite, pos);
    (*chars)->frog_rect = sfRectangleShape_create();
    (*chars)->cadre_frog = sfSprite_create();
    sfSprite_setTexture((*chars)->cadre_frog, (*chars)->cadre, 0);
    sfSprite_setScale((*chars)->cadre_frog, (sfVector2f) {4, 4});
    sfSprite_setOrigin((*chars)->cadre_frog, (sfVector2f) {24, 24});
    sfSprite_setPosition((*chars)->cadre_frog, pos);
    sfRectangleShape_setFillColor((*chars)->frog_rect, sfTransparent);
    sfRectangleShape_setSize((*chars)->frog_rect, (sfVector2f) {48, 48});
    sfRectangleShape_setOrigin((*chars)->frog_rect, (sfVector2f) {24, 24});
    sfRectangleShape_setScale((*chars)->frog_rect, (sfVector2f) {4, 4});
    sfRectangleShape_setPosition((*chars)->frog_rect, pos);
}

static void init_girl(characters_t **chars, sfVector2f pos)
{
    (*chars)->girl = sfTexture_createFromFile(FACE_GIRL, NULL);
    (*chars)->girl_sprite = sfSprite_create();
    sfSprite_setTexture((*chars)->girl_sprite, (*chars)->girl, 0);
    sfSprite_setScale((*chars)->girl_sprite, (sfVector2f) {4, 4});
    sfSprite_setOrigin((*chars)->girl_sprite, (sfVector2f) {19, 19});
    pos.y -= 200;
    pos.x += 530;
    sfSprite_setPosition((*chars)->girl_sprite, pos);
    (*chars)->girl_rect = sfRectangleShape_create();
    (*chars)->cadre_girl = sfSprite_create();
    sfSprite_setTexture((*chars)->cadre_girl, (*chars)->cadre, 0);
    sfSprite_setScale((*chars)->cadre_girl, (sfVector2f) {4, 4});
    sfSprite_setOrigin((*chars)->cadre_girl, (sfVector2f) {24, 24});
    sfSprite_setPosition((*chars)->cadre_girl, pos);
    sfRectangleShape_setFillColor((*chars)->girl_rect, sfTransparent);
    sfRectangleShape_setSize((*chars)->girl_rect, (sfVector2f) {48, 48});
    sfRectangleShape_setOrigin((*chars)->girl_rect, (sfVector2f) {24, 24});
    sfRectangleShape_setScale((*chars)->girl_rect, (sfVector2f) {4, 4});
    sfRectangleShape_setPosition((*chars)->girl_rect, pos);
}

void init_continue(characters_t **chars, sfVector2f pos)
{
    (*chars)->icontinue = sfTexture_createFromFile(I_CONTINUE_ENG, NULL);
    (*chars)->hcontinue = sfTexture_createFromFile(H_CONTINUE_ENG, NULL);
    (*chars)->pcontinue = sfTexture_createFromFile(P_CONTINUE_ENG, NULL);
    (*chars)->continue_sprite = sfSprite_create();
    sfSprite_setTexture((*chars)->continue_sprite, (*chars)->icontinue, 0);
    sfSprite_setOrigin((*chars)->continue_sprite, (sfVector2f) {115, 35});
    pos.x += 740;
    pos.y += 400;
    sfSprite_setPosition((*chars)->continue_sprite, pos);
    (*chars)->continue_rect = sfRectangleShape_create();
    sfRectangleShape_setSize((*chars)->continue_rect,
        (sfVector2f) {229, 71});
    sfRectangleShape_setOrigin((*chars)->continue_rect,
        (sfVector2f) {115, 35.5});
    sfRectangleShape_setPosition((*chars)->continue_rect, pos);
    sfRectangleShape_setFillColor((*chars)->continue_rect, sfTransparent);
}

void init_character_choose(hud_t **hud, rpg_t *rpg)
{
    sfVector2u size = sfRenderWindow_getSize(rpg->window);
    sfVector2f pos = {size.x / 2, size.y / 2};

    rpg = (void *)rpg;
    (*hud)->chars = malloc(sizeof(characters_t));
    (*hud)->chars->display = false;
    (*hud)->chars->cadre = sfTexture_createFromFile(CADRE, NULL);
    (*hud)->chars->who = 3;
    init_log(&(*hud)->chars, pos);
    init_boy(&(*hud)->chars, pos);
    init_frog(&(*hud)->chars, pos);
    init_girl(&(*hud)->chars, pos);
    init_continue(&(*hud)->chars, pos);
    (*hud)->chars->choosed = sfTexture_createFromFile(SELECTED, NULL);
}
