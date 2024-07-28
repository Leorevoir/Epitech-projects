/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** display_inventory
*/

#include "display.h"

void draw_weapons(rpg_t *rpg)
{
    if (rpg->inventory.has_sword)
        sfRenderWindow_drawSprite(rpg->window, CMD_INV.sword_obj.sprite, NULL);
    if (rpg->inventory.has_spear)
        sfRenderWindow_drawSprite(rpg->window, CMD_INV.spear_obj.sprite, NULL);
}

static void draw_inventory_stat(rpg_t *rpg)
{
    if (rpg->lang == ENGLISH)
        sfRenderWindow_drawSprite(rpg->window, CMD_INV.inventory.sprite, NULL);
    else
        sfRenderWindow_drawSprite(rpg->window,
            CMD_INV.inventaire.sprite, NULL);
    sfRenderWindow_drawText(rpg->window, CMD_INV.level->text, NULL);
    sfRenderWindow_drawText(rpg->window, CMD_INV.agility->text, NULL);
    sfRenderWindow_drawText(rpg->window, CMD_INV.strength->text, NULL);
    sfRenderWindow_drawText(rpg->window, CMD_INV.constitution->text, NULL);
    sfRenderWindow_drawText(rpg->window, CMD_INV.intelligence->text, NULL);
}

static void draw_inventory_quests(rpg_t *rpg)
{
    if (rpg->lang == ENGLISH)
        sfRenderWindow_drawSprite(rpg->window, CMD_INV.quests.sprite, NULL);
    else
        sfRenderWindow_drawSprite(rpg->window, CMD_INV.quetes.sprite, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->text->quest, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->text->validate, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->text->description, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->text->picture.sprite, NULL);
}

void display_inventory(rpg_t *rpg)
{
    const sfView *default_view = sfRenderWindow_getDefaultView(rpg->window);

    sfRenderWindow_setView(rpg->window, default_view);
    if (!rpg->inventory.show_quest) {
        draw_inventory_stat(rpg);
    } else {
        draw_inventory_quests(rpg);
    }
    sfRenderWindow_drawVertexArray(rpg->window, CMD_INV.button,
        &(CMD_INV.states_btn));
    draw_weapons(rpg);
    sfRenderWindow_drawText(rpg->window, CMD_INV.name->text, NULL);
    sfRenderWindow_drawSprite(rpg->window, CMD_INV.pp.sprite, NULL);
    sfRenderWindow_setView(rpg->window, rpg->view);
}
