/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_save_menu
*/

#include "update.h"

static void save_contains_mouse(menu_t *menu, rpg_t *rpg)
{
    if (!rpg->lang)
            sfSprite_setTexture(menu->save.sprite, menu->save_h, 0);
    else
        sfSprite_setTexture(menu->save.sprite, menu->save_h_fr, 0);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (!rpg->lang)
            sfSprite_setTexture(menu->save.sprite, menu->save_p, 0);
        else
            sfSprite_setTexture(menu->save.sprite, menu->save_p_fr, 0);
        save_progression(rpg);
    }
}

void handle_save_escape_menu(hud_t *hud, rpg_t *rpg, sfVector2i mouse)
{
    menu_t *menu = hud->menu;
    sfFloatRect s = sfSprite_getGlobalBounds(menu->save.sprite);

    if (sfFloatRect_contains(&s, mouse.x, mouse.y)) {
        save_contains_mouse(menu, rpg);
    } else
        if (!rpg->lang)
            sfSprite_setTexture(menu->save.sprite, menu->save_i, 0);
        else
            sfSprite_setTexture(menu->save.sprite, menu->save_i_fr, 0);
}
