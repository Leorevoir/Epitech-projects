/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_attack
*/

#include "update.h"

void check_sword(rpg_t *rpg, sfVector2f pos, sfTimeSpan time_span)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && CMD_INV.sword.equippied) {
        sfMusic_stop(rpg->music.swing_sound);
        sfMusic_setLoopPoints(rpg->music.swing_sound, time_span);
        if (sfMusic_getStatus(rpg->music.swing_sound) != sfPlaying)
            sfMusic_play(rpg->music.swing_sound);
        if (rpg->player.last_direction == WAS_DOWN)
            handle_attack_down_sword(rpg, pos);
        if (rpg->player.last_direction == WAS_UP)
            handle_attack_up_sword(rpg, pos);
        if (rpg->player.last_direction == WAS_LEFT)
            handle_attack_left_sword(rpg, pos);
        if (rpg->player.last_direction == WAS_RIGHT)
            handle_attack_right_sword(rpg, pos);
        rpg->inventory.sword.show = true;
    }
}

void check_spear(rpg_t *rpg, sfVector2f pos, sfTimeSpan time_span)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && CMD_INV.spear.equippied) {
        sfMusic_stop(rpg->music.swing_sound);
        sfMusic_setLoopPoints(rpg->music.swing_sound, time_span);
        if (sfMusic_getStatus(rpg->music.swing_sound) != sfPlaying)
            sfMusic_play(rpg->music.swing_sound);
        if (rpg->player.last_direction == WAS_DOWN)
            handle_attack_down_spear(rpg, pos);
        if (rpg->player.last_direction == WAS_UP)
            handle_attack_up_spear(rpg, pos);
        if (rpg->player.last_direction == WAS_LEFT)
            handle_attack_left_spear(rpg, pos);
        if (rpg->player.last_direction == WAS_RIGHT)
            handle_attack_right_spear(rpg, pos);
        rpg->inventory.spear.show = true;
    }
}

void handle_mouse_input(rpg_t *rpg, sfTimeSpan time_span)
{
    sfVector2f pos = rpg->player.object.position;

    rpg->inventory.sword.show = false;
    rpg->inventory.spear.show = false;
    check_sword(rpg, pos, time_span);
    check_spear(rpg, pos, time_span);
}

// OMG IT IS FOR PVE
// sfFloatRect sword;
// sfFloatRect enemy;
// sword = sfSprite_getGlobalBounds(rpg->inventory.sword.object.sprite);
// enemy = sfSprite_getGlobalBounds(rpg->enemy.object.sprite);
// if (sfFloatRect_intersects(&sword, &enemy, NULL))
//     write(1, "OUUUUUUUHHH !\n", 14);
