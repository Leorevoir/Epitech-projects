/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** sklt_weapon_pos
*/

#include "update.h"

static void correct_weapon_pos(npc_t *s, float angle, float x, float y)
{
    s->show_weapon = true;
    sfSprite_setRotation(s->weapon.sprite, angle);
    sfSprite_setPosition(s->weapon.sprite, (sfVector2f)
    {
        s->object.position.x + x,
        s->object.position.y + y}
    );
}

void switch_weapon_pos(npc_t *s, direction_t d)
{
    switch (d) {
        case 8:
            correct_weapon_pos(s, 180, 8, 0);
            break;
        case 9:
            correct_weapon_pos(s, 0, 11, 13);
            break;
        case 10:
            correct_weapon_pos(s, 90, 0, 8);
            break;
        case 11:
            correct_weapon_pos(s, 270, 15, 16);
            break;
        default:
            break;
    }
}
