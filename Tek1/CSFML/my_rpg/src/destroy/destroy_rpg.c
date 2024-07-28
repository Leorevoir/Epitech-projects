/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_rpg
*/

#include "my_rpg.h"

void destroy_text_rpg(rpg_t *rpg)
{
    if (rpg->lvl_up)
        sfText_destroy(rpg->lvl_up);
    if (rpg->death.youre_dead)
        sfText_destroy(rpg->death.youre_dead);
    if (rpg->death.try_again)
        sfText_destroy(rpg->death.try_again);
}

void destroy_all_weather(weather_t *weather)
{
    if (!weather)
        return;
    sfRectangleShape_destroy(weather->autumn_filter);
    sfRectangleShape_destroy(weather->night_filter);
    free(weather);
}

void destroy_stats(stats_t *stats)
{
    stats_t *current = stats;
    stats_t *next = NULL;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

void destroy_rpg(rpg_t *rpg, tile_t *tiles, hud_t *hud, stats_t *stats)
{
    destroy_tiles(tiles);
    destroy_window(rpg->window);
    destroy_menu(hud);
    destroy_player(rpg->player);
    sfClock_destroy(rpg->player.hit_clock);
    destroy_all_boss(rpg->boss);
    destroy_all_npcs(&rpg->npc);
    destroy_all_dialogues(rpg->dialogue);
    destroy_all_dialogues(rpg->dialogue_eng);
    destroy_text(rpg->text);
    destroy_ui(rpg->ui);
    destroy_maps(rpg->maps);
    destroy_inventory(rpg->inventory, rpg);
    destroy_stats(stats);
    destroy_music(rpg);
    sfClock_destroy(rpg->clock);
    sfView_destroy(rpg->view);
    destroy_all_weather(rpg->weather);
    destroy_text_rpg(rpg);
}
