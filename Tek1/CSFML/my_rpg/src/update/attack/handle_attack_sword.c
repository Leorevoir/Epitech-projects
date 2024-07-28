/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** handle_attack
*/

#include "my_rpg.h"

void handle_attack_down_sword(rpg_t *rpg, sfVector2f pos)
{
    sfSprite_setRotation(rpg->inventory.sword.object.sprite, 0);
    pos.x += 2;
    pos.y += 16;
    sfSprite_setTexture(rpg->player.object.sprite,
    rpg->player.textures[ATCK_DOWN], sfTrue);
    sfSprite_setPosition(rpg->inventory.sword.object.sprite, pos);
}

void handle_attack_up_sword(rpg_t *rpg, sfVector2f pos)
{
    sfSprite_setRotation(rpg->inventory.sword.object.sprite, 180);
    pos.x += 8;
    sfSprite_setTexture(rpg->player.object.sprite,
    rpg->player.textures[ATCK_UP], sfTrue);
    sfSprite_setPosition(rpg->inventory.sword.object.sprite, pos);
}

void handle_attack_left_sword(rpg_t *rpg, sfVector2f pos)
{
    sfSprite_setRotation(rpg->inventory.sword.object.sprite, 90);
    pos.y += 9;
    sfSprite_setTexture(rpg->player.object.sprite,
    rpg->player.textures[ATCK_LEFT], sfTrue);
    sfSprite_setPosition(rpg->inventory.sword.object.sprite, pos);
}

void handle_attack_right_sword(rpg_t *rpg, sfVector2f pos)
{
    sfSprite_setRotation(rpg->inventory.sword.object.sprite, 270);
    pos.y += 15;
    pos.x += 16;
    sfSprite_setTexture(rpg->player.object.sprite,
    rpg->player.textures[ATCK_RIGHT], sfTrue);
    sfSprite_setPosition(rpg->inventory.sword.object.sprite, pos);
}
