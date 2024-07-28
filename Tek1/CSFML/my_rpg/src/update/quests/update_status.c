/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_status
*/

#include "my_rpg.h"

void update_status_lvl3(rpg_t *rpg)
{
    if (atoi(sfText_getString(rpg->inventory.level->text)) != 3) {
        rpg->disp_lvl_up = true;
        sfText_setString(rpg->inventory.level->text, "3");
        sfText_setString(rpg->inventory.agility->text, "5");
        sfText_setString(rpg->inventory.strength->text, "7");
        sfText_setString(rpg->inventory.constitution->text, "5");
        sfText_setString(rpg->inventory.intelligence->text, "4");
    }
}

void update_status_lvl2(rpg_t *rpg)
{
    rpg->disp_lvl_up = true;
    sfText_setString(rpg->inventory.level->text, "2");
    sfText_setString(rpg->inventory.agility->text, "4");
    sfText_setString(rpg->inventory.strength->text, "6");
    sfText_setString(rpg->inventory.constitution->text, "4");
    sfText_setString(rpg->inventory.intelligence->text, "2");
    sfText_setString(rpg->text->validate, "V");
    sfText_setColor(rpg->text->validate, sfGreen);
}
