/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_inventory
*/

#include "my_rpg.h"

void destroy_text_font(inventory_t inventory, rpg_t *rpg)
{
    if (rpg->tool.who != -1)
        sfText_destroy(inventory.name->text);
    sfText_destroy(inventory.agility->text);
    sfText_destroy(inventory.strength->text);
    sfText_destroy(inventory.constitution->text);
    sfText_destroy(inventory.intelligence->text);
    sfText_destroy(inventory.level->text);
    if (rpg->tool.who != -1)
        sfFont_destroy(inventory.name->font);
    sfFont_destroy(inventory.agility->font);
    sfFont_destroy(inventory.strength->font);
    sfFont_destroy(inventory.constitution->font);
    sfFont_destroy(inventory.intelligence->font);
    sfFont_destroy(inventory.level->font);
}

void destroy_inventory(inventory_t inventory, rpg_t *rpg)
{
    destroy_object(&inventory.sword.object);
    destroy_object(&inventory.spear.object);
    destroy_object(&inventory.inventory);
    destroy_object(&inventory.quests);
    destroy_object(&inventory.inventaire);
    destroy_object(&inventory.quetes);
    destroy_object(&inventory.sword_obj);
    destroy_object(&inventory.spear_obj);
    destroy_object(&inventory.curr_weapon);
    destroy_object(&inventory.pp);
    destroy_text_font(inventory, rpg);
    sfVertexArray_destroy(inventory.button);
    free(inventory.name);
    free(inventory.agility);
    free(inventory.strength);
    free(inventory.constitution);
    free(inventory.intelligence);
    free(inventory.level);
}
