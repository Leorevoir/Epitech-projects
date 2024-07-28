/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_hover_buttons
*/

#include "update.h"

void hover_new(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(menu->ngame_rect);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->ngame_sprite, menu->hngame_eng, 0);
        else
            sfSprite_setTexture(menu->ngame_sprite, menu->hngame_fr, 0);
    else
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->ngame_sprite, menu->ingame_eng, 0);
        else
            sfSprite_setTexture(menu->ngame_sprite, menu->ingame_fr, 0);
}

void hover_load(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(menu->lgame_rect);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->lgame_sprite, menu->hlgame_eng, 0);
        else
            sfSprite_setTexture(menu->lgame_sprite, menu->hlgame_fr, 0);
    else
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->lgame_sprite, menu->ilgame_eng, 0);
        else
            sfSprite_setTexture(menu->lgame_sprite, menu->ilgame_fr, 0);
}

void hov_seting(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(menu->setting_rect);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->settings_sprite, menu->hsetting_eng, 0);
        else
            sfSprite_setTexture(menu->settings_sprite, menu->hsetting_fr, 0);
    else
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->settings_sprite, menu->isetting_eng, 0);
        else
            sfSprite_setTexture(menu->settings_sprite, menu->isetting_fr, 0);
}

void hover_exit(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(menu->exit_rect);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->exit_sprite, menu->hexit_eng, 0);
        else
            sfSprite_setTexture(menu->exit_sprite, menu->hexit_fr, 0);
    else
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->exit_sprite, menu->iexit_eng, 0);
        else
            sfSprite_setTexture(menu->exit_sprite, menu->iexit_fr, 0);
}
