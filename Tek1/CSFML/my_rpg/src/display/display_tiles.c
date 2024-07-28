/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** display_tiles
*/

#include "display.h"

//---------- je vous expliquerai ces fonctions de display ----------//
//-------------------- ne pas toucher --------------------//
static void display_before(rpg_t *rpg, tile_t *head, int num)
{
    bool should_display;

    for (tile_t *current = head; current != NULL; current = current->next) {
        should_display = current->display_mode == 0
            || (current->display_mode == 1 && !rpg->weather->autumn)
            || (current->display_mode == 2 && rpg->weather->autumn);
        if (should_display && (TREE != 0 || BACK != 0)
            && current->map == num)
            draw_my_tiles(current, rpg);
    }
}

//---------- je vous expliquerai ces fonctions de display ----------//
//-------------------- ne pas toucher --------------------//
static void display_after(rpg_t *rpg, tile_t *head, int num)
{
    bool should_display;

    for (tile_t *current = head; current != NULL; current = current->next) {
        should_display = current->display_mode == 0
            || (current->display_mode == 1 && !rpg->weather->autumn)
            || (current->display_mode == 2 && rpg->weather->autumn);
        if (should_display && (TREE == 0 || BACK == 0)
            && current->map == num)
            draw_my_tiles(current, rpg);
    }
}

static void what_npc_should_i_display(npc_t *n, sfRenderWindow *w, int num)
{
    if (n->is_alive && n->map == num) {
        DRAW_SPRITE(w, n->object.sprite, NULL);
        if (n->show_weapon)
            DRAW_SPRITE(w, n->weapon.sprite, NULL);
    }
}

static void display_npc(npc_t *npc, sfRenderWindow *window, int num)
{
    for (npc_t *current = npc; current != NULL; current = current->next) {
        what_npc_should_i_display(current, window, num);
    }
}

static void display_destroy_village(rpg_t *rpg, tile_t *head)
{
    display_before(rpg, head, 1);
    display_npc(rpg->npc, rpg->window, 1);
    DRAW_SPRITE(rpg->window, rpg->player.object.sprite, NULL);
    if (rpg->inventory.sword.show)
        DRAW_SPRITE(rpg->window, rpg->inventory.sword.object.sprite, NULL);
    if (rpg->inventory.spear.show)
        DRAW_SPRITE(rpg->window, rpg->inventory.spear.object.sprite, NULL);
    display_after(rpg, head, 1);
}

static void display_rebuilt_village(rpg_t *rpg, tile_t *head)
{
    display_before(rpg, head, 2);
    display_npc(rpg->npc, rpg->window, 2);
    DRAW_SPRITE(rpg->window, rpg->player.object.sprite, NULL);
    if (rpg->inventory.sword.show)
        DRAW_SPRITE(rpg->window, rpg->inventory.sword.object.sprite, NULL);
    if (rpg->inventory.spear.show)
        DRAW_SPRITE(rpg->window, rpg->inventory.spear.object.sprite, NULL);
    display_after(rpg, head, 2);
}

static void display_road(rpg_t *rpg, tile_t *head)
{
    display_before(rpg, head, 0);
    display_npc(rpg->npc, rpg->window, 0);
    DRAW_SPRITE(rpg->window, rpg->player.object.sprite, NULL);
    if (rpg->inventory.sword.show)
        DRAW_SPRITE(rpg->window, rpg->inventory.sword.object.sprite, NULL);
    if (rpg->inventory.spear.show)
        DRAW_SPRITE(rpg->window, rpg->inventory.spear.object.sprite, NULL);
    display_after(rpg, head, 0);
}

static void display_boss(rpg_t *rpg, tile_t *head)
{
    display_before(rpg, head, 3);
    display_npc(rpg->npc, rpg->window, 3);
    DRAW_SPRITE(rpg->window, rpg->player.object.sprite, NULL);
    if (rpg->inventory.sword.show)
        DRAW_SPRITE(rpg->window, rpg->inventory.sword.object.sprite, NULL);
    if (rpg->inventory.spear.show)
        DRAW_SPRITE(rpg->window, rpg->inventory.spear.object.sprite, NULL);
    if (rpg->boss->alive)
        display_big_boss(rpg, rpg->boss);
    display_after(rpg, head, 3);
}

void display_tiles_and_player(rpg_t *rpg, tile_t *head)
{
    if (rpg->background == &(rpg->maps.map_road))
        display_road(rpg, head);
    if (rpg->background == &(rpg->maps.map_village)
        && !rpg->rebuilt)
        display_destroy_village(rpg, head);
    if (rpg->background == (&rpg->maps.map_village)
        && rpg->rebuilt)
        display_rebuilt_village(rpg, head);
    if (rpg->background == &(rpg->maps.map_boss))
        display_boss(rpg, head);
}
