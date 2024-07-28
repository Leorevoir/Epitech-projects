/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_weapon
*/

#include "my_rpg.h"

void init_weapon(rpg_t *rpg)
{
    rpg->inventory.sword.object = init_object(SWORD, (VECT){0.0, 0.0});
    rpg->inventory.sword.show = false;
    rpg->inventory.sword.equippied = false;
    rpg->inventory.spear.object = init_object(SPEAR, (VECT){0.0, 0.0});
    rpg->inventory.spear.show = false;
    rpg->inventory.spear.equippied = false;
    rpg->inventory.curr_weapon = init_object(SWORD_PIC, (VECT){0.0, 0.0});
}
