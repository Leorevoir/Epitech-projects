/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** destroy_menu.c
*/

#include "../../include/my_rpg.h"

static void destroy_texture_eng(hud_t *hud)
{
    sfTexture_destroy(hud->menu->back);
    sfTexture_destroy(hud->menu->ingame_eng);
    sfTexture_destroy(hud->menu->hngame_eng);
    sfTexture_destroy(hud->menu->pngame_eng);
    sfTexture_destroy(hud->menu->ilgame_eng);
    sfTexture_destroy(hud->menu->hlgame_eng);
    sfTexture_destroy(hud->menu->plgame_eng);
    sfTexture_destroy(hud->menu->isetting_eng);
    sfTexture_destroy(hud->menu->hsetting_eng);
    sfTexture_destroy(hud->menu->psetting_eng);
    sfTexture_destroy(hud->menu->iexit_eng);
    sfTexture_destroy(hud->menu->hexit_eng);
    sfTexture_destroy(hud->menu->pexit_eng);
}

static void destroy_texture_fr(hud_t *hud)
{
    sfTexture_destroy(hud->menu->ingame_fr);
    sfTexture_destroy(hud->menu->hngame_fr);
    sfTexture_destroy(hud->menu->pngame_fr);
    sfTexture_destroy(hud->menu->ilgame_fr);
    sfTexture_destroy(hud->menu->hlgame_fr);
    sfTexture_destroy(hud->menu->plgame_fr);
    sfTexture_destroy(hud->menu->isetting_fr);
    sfTexture_destroy(hud->menu->hsetting_fr);
    sfTexture_destroy(hud->menu->psetting_fr);
    sfTexture_destroy(hud->menu->iexit_fr);
    sfTexture_destroy(hud->menu->hexit_fr);
    sfTexture_destroy(hud->menu->pexit_fr);
}

static void destroy_show_menu(menu_show_t *menu)
{
    sfTexture_destroy(menu->boy[DIR_UP]);
    sfTexture_destroy(menu->boy[DIR_DOWN]);
    sfTexture_destroy(menu->boy[DIR_LEFT]);
    sfTexture_destroy(menu->boy[DIR_RIGHT]);
    sfTexture_destroy(menu->girl[DIR_UP]);
    sfTexture_destroy(menu->girl[DIR_DOWN]);
    sfTexture_destroy(menu->girl[DIR_LEFT]);
    sfTexture_destroy(menu->girl[DIR_RIGHT]);
    sfTexture_destroy(menu->frog[DIR_UP]);
    sfTexture_destroy(menu->frog[DIR_DOWN]);
    sfTexture_destroy(menu->frog[DIR_LEFT]);
    sfTexture_destroy(menu->frog[DIR_RIGHT]);
    destroy_object(&menu->my_frog);
    destroy_object(&menu->my_girl);
    destroy_object(&menu->my_boy);
    free(menu);
}

static void destroy_hud_back(hud_t *hud)
{
    sfTexture_destroy(hud->iback_eng);
    sfTexture_destroy(hud->hback_eng);
    sfTexture_destroy(hud->pback_eng);
    sfTexture_destroy(hud->iback_fr);
    sfTexture_destroy(hud->hback_fr);
    sfTexture_destroy(hud->pback_fr);
    free(hud->sett);
    free(hud->menu);
}

static void destroy_hud_save(hud_t *hud)
{
    destroy_object(&(hud->menu->save));
    sfTexture_destroy(hud->menu->save_h);
    sfTexture_destroy(hud->menu->save_i);
    sfTexture_destroy(hud->menu->save_p);
    sfTexture_destroy(hud->menu->save_h_fr);
    sfTexture_destroy(hud->menu->save_i_fr);
    sfTexture_destroy(hud->menu->save_p_fr);
}

static void destroy_menu_sprite(hud_t *hud)
{
    sfSprite_destroy(hud->menu->back_sprite);
    sfSprite_destroy(hud->menu->ngame_sprite);
    sfSprite_destroy(hud->menu->lgame_sprite);
    sfSprite_destroy(hud->menu->settings_sprite);
    sfSprite_destroy(hud->menu->exit_sprite);
    sfSprite_destroy(hud->back_sprite);
    sfSprite_destroy(hud->menu->resume_sprite);
}

void destroy_menu(hud_t *hud)
{
    destroy_texture_eng(hud);
    destroy_texture_fr(hud);
    sfSprite_destroy(hud->menu->name_sprite);
    sfTexture_destroy(hud->menu->name);
    destroy_hud_save(hud);
    sfRectangleShape_destroy(hud->menu->ngame_rect);
    sfRectangleShape_destroy(hud->menu->lgame_rect);
    sfRectangleShape_destroy(hud->menu->setting_rect);
    sfRectangleShape_destroy(hud->menu->exit_rect);
    sfRectangleShape_destroy(hud->back_rect);
    sfRectangleShape_destroy(hud->menu->r_rect);
    destroy_menu_sprite(hud);
    destroy_player_choose(hud->chars);
    destroy_settings_hud(hud->sett);
    destroy_show_menu(hud->players);
    destroy_hud_back(hud);
    free(hud);
}
