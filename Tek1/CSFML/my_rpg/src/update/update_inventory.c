/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_inventory
*/

#include "update.h"

void update_inventory(rpg_t *rpg)
{
    const sfView *default_v = sfRenderWindow_getDefaultView(rpg->window);
    sfFloatRect rct_sword = sfSprite_getGlobalBounds(CMD_INV.sword_obj.sprite);
    sfFloatRect rct_spear = sfSprite_getGlobalBounds(CMD_INV.spear_obj.sprite);
    sfVector2i pos = convert_mouse_vertex(rpg->window, rpg, default_v);
    sfColor grey = {220, 220, 220, 100};

    if (sfFloatRect_contains(&rct_sword, (float)pos.x, (float)pos.y)
    || CMD_INV.sword.equippied)
        sfSprite_setColor(CMD_INV.sword_obj.sprite, sfRed);
    else
        sfSprite_setColor(CMD_INV.sword_obj.sprite, sfWhite);
    if (sfFloatRect_contains(&rct_spear, (float)pos.x, (float)pos.y)
    || CMD_INV.spear.equippied)
        sfSprite_setColor(CMD_INV.spear_obj.sprite, sfRed);
    else
        sfSprite_setColor(CMD_INV.spear_obj.sprite, sfWhite);
    if (is_in_vertex(rpg))
        set_vertex_color(CMD_INV.button, grey);
    else
        set_vertex_color(CMD_INV.button, sfTransparent);
}
