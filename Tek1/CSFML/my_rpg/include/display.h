/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** display
*/

#include "my_rpg.h"

#ifndef DISPLAY_H_
    #define DISPLAY_H_
    #define DRAW_SPRITE sfRenderWindow_drawSprite

static inline void draw_my_tiles(tile_t *current, rpg_t *rpg)
{
    if (rpg->inventory.has_spear && strcmp(current->name, "spear") == 0)
        return;
    sfSprite_setPosition(current->sprite, (sfVector2f){
        current->posx, current->posy});
    DRAW_SPRITE(rpg->window, current->sprite, NULL);
}

////////// FUNCTIONS DISPLAY //////////
int loading_screen(rpg_t *rpg, tile_t **head, hud_t **hud,
    stats_t **stats);
void display_rpg(rpg_t *rpg, tile_t *head, hud_t *hud);
int get_map_id(rpg_t *rpg);
void display_menu(hud_t *hud, rpg_t *rpg);
void display_inventory(rpg_t *rpg);
void display_tiles_and_player(rpg_t *rpg, tile_t *head);
void display_text(text_t *text, rpg_t *rpg, npc_t *npc, sfEvent *event);
void autumn_vibrant(rpg_t *rpg);
void night_vibrant(rpg_t *rpg);
void display_big_boss(rpg_t *rpg, boss_t *boss);
void display_player_choose(rpg_t *rpg, hud_t *hud);
void display_settings_hud(rpg_t *rpg, hud_t *hud);
void display_escape_menu(hud_t *hud, rpg_t *rpg);

#endif /* !DISPLAY_H_ */
