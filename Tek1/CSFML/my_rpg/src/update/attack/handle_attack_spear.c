/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** handle_attack_spear
*/

#include "my_rpg.h"

void handle_attack_down_spear(rpg_t *rpg, sfVector2f pos)
{
    sfSprite_setRotation(rpg->inventory.spear.object.sprite, 0);
    pos.x += 2;
    pos.y += 16;
    sfSprite_setTexture(rpg->player.object.sprite,
    rpg->player.textures[ATCK_DOWN], sfTrue);
    sfSprite_setPosition(rpg->inventory.spear.object.sprite, pos);
}

void handle_attack_up_spear(rpg_t *rpg, sfVector2f pos)
{
    sfSprite_setRotation(rpg->inventory.spear.object.sprite, 180);
    pos.x += 8;
    sfSprite_setTexture(rpg->player.object.sprite,
    rpg->player.textures[ATCK_UP], sfTrue);
    sfSprite_setPosition(rpg->inventory.spear.object.sprite, pos);
}

void handle_attack_left_spear(rpg_t *rpg, sfVector2f pos)
{
    sfSprite_setRotation(rpg->inventory.spear.object.sprite, 90);
    pos.y += 9;
    sfSprite_setTexture(rpg->player.object.sprite,
    rpg->player.textures[ATCK_LEFT], sfTrue);
    sfSprite_setPosition(rpg->inventory.spear.object.sprite, pos);
}

void handle_attack_right_spear(rpg_t *rpg, sfVector2f pos)
{
    sfSprite_setRotation(rpg->inventory.spear.object.sprite, 270);
    pos.y += 15;
    pos.x += 16;
    sfSprite_setTexture(rpg->player.object.sprite,
    rpg->player.textures[ATCK_RIGHT], sfTrue);
    sfSprite_setPosition(rpg->inventory.spear.object.sprite, pos);
}
