/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** handle_events
*/

#include "my_rpg.h"

static void switch_key_released(rpg_t *rpg, sfEvent *event)
{
    switch (event->key.code) {
        case sfKeyLShift:
            if (rpg->player.quest < MOVE2)
                return;
            rpg->player.speed.x -= 0.6;
            rpg->player.speed.y -= 0.6;
            break;
        default:
            break;
    }
}

static void check_weapons_selected(rpg_t *rpg)
{
    sfFloatRect rct_sword = sfSprite_getGlobalBounds(CMD_INV.sword_obj.sprite);
    sfFloatRect rct_spear = sfSprite_getGlobalBounds(CMD_INV.spear_obj.sprite);
    sfVector2i pos = sfMouse_getPositionRenderWindow(rpg->window);

    if (sfFloatRect_contains(&rct_sword, (float)pos.x, (float)pos.y)) {
        sfSprite_setColor(CMD_INV.sword_obj.sprite, sfRed);
        destroy_object(&CMD_INV.curr_weapon);
        CMD_INV.curr_weapon = init_object(SWORD_PIC, (VECT){0, 0});
        CMD_INV.sword.equippied = !CMD_INV.sword.equippied;
        CMD_INV.spear.equippied = false;
    }
    if (sfFloatRect_contains(&rct_spear, (float)pos.x, (float)pos.y)) {
        sfSprite_setColor(CMD_INV.spear_obj.sprite, sfRed);
        destroy_object(&CMD_INV.curr_weapon);
        CMD_INV.curr_weapon = init_object(SPEAR_PIC, (VECT){0, 0});
        CMD_INV.spear.equippied = !CMD_INV.spear.equippied;
        CMD_INV.sword.equippied = false;
    }
}

static void key_released_event(rpg_t *rpg, sfEvent *event, hud_t *hud)
{
    if (event->type == sfEvtMouseButtonReleased && CMD_INV.show) {
        if (event->mouseButton.button == sfMouseLeft)
            check_weapons_selected(rpg);
        if (event->mouseButton.button == sfMouseLeft && is_in_vertex(rpg))
            rpg->inventory.show_quest = !rpg->inventory.show_quest;
    }
    if (event->type == sfEvtMouseButtonReleased && hud->sett->display == true)
        if (event->mouseButton.button == sfMouseLeft)
            update_resolution(hud->sett, rpg);
    if (event->type == sfEvtMouseButtonReleased && hud->sett->display == true)
        if (event->mouseButton.button == sfMouseLeft)
            update_musical(hud->sett, rpg);
    if (event->type == sfEvtKeyReleased)
        switch_key_released(rpg, event);
}

static void event_game(rpg_t *rpg, sfEvent *event, hud_t *hud)
{
    key_released_event(rpg, event, hud);
    key_pressed_event(rpg, event, hud);
}

void handle_events(rpg_t *rpg, sfEvent *event, hud_t *hud)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (hud->display == false)
        handle_save(rpg, event);
    event_game(rpg, event, hud);
}
