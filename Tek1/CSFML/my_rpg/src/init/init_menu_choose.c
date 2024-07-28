/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_menu_choose
*/

#include "my_rpg.h"

static void create_menu_boy(menu_show_t *show)
{
    show->boy[DIR_UP] = sfTexture_createFromFile(BOY_IDLE_UP, NULL);
    show->boy[DIR_DOWN] = sfTexture_createFromFile(BOY_IDLE_DOWN, NULL);
    show->boy[DIR_LEFT] = sfTexture_createFromFile(BOY_IDLE_LEFT, NULL);
    show->boy[DIR_RIGHT] = sfTexture_createFromFile(BOY_IDLE_RIGHT, NULL);
    show->my_boy = init_object(BOY_IDLE_DOWN, (sfVector2f){850, 600});
}

static void create_menu_frog(menu_show_t *show)
{
    show->frog[DIR_UP] = sfTexture_createFromFile(FROG_IDLE_UP, NULL);
    show->frog[DIR_DOWN] = sfTexture_createFromFile(FROG_IDLE_DOWN, NULL);
    show->frog[DIR_LEFT] = sfTexture_createFromFile(FROG_IDLE_LEFT, NULL);
    show->frog[DIR_RIGHT] = sfTexture_createFromFile(FROG_IDLE_RIGHT, NULL);
    show->my_frog = init_object(FROG_IDLE_DOWN, (sfVector2f){850, 600});
}

static void create_menu_girl(menu_show_t *show)
{
    show->girl[DIR_UP] = sfTexture_createFromFile(GIRL_IDLE_UP, NULL);
    show->girl[DIR_DOWN] = sfTexture_createFromFile(GIRL_IDLE_DOWN, NULL);
    show->girl[DIR_LEFT] = sfTexture_createFromFile(GIRL_IDLE_LEFT, NULL);
    show->girl[DIR_RIGHT] = sfTexture_createFromFile(GIRL_IDLE_RIGHT, NULL);
    show->my_girl = init_object(GIRL_IDLE_DOWN, (sfVector2f){850, 600});
}

void init_players(hud_t *hud)
{
    hud->players = NULL;
    hud->players = (menu_show_t *)malloc(sizeof(menu_show_t));
    create_menu_boy(hud->players);
    create_menu_frog(hud->players);
    create_menu_girl(hud->players);
}
