/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** game_loop
*/

#include "update.h"
#include "display.h"

static void game_loop_menu(hud_t *hud, rpg_t *rpg, tile_t *head)
{
    if (hud->menu->escape == true) {
        update_escape_menu(hud, rpg);
        if (hud->menu->escape == true)
            display_rpg(rpg, head, hud);
    } else {
        update_menu(hud, rpg);
        display_menu(hud, rpg);
    }
}

static void handle_rpg(rpg_t *rpg, sfEvent event, sfTimeSpan time_span)
{
    if (!rpg->inventory.show)
        update_rpg(rpg, &event, time_span);
    else
        update_inventory(rpg);
}

static void resolve_player_sprint(character_t *player)
{
    if (player->speed.x <= 0.7)
        player->speed = (sfVector2f){PLAYER_SPEED, PLAYER_SPEED};
}

void game_loop(rpg_t *rpg, tile_t *head, hud_t *hud, sfEvent event)
{
    sfTime time = sfClock_getElapsedTime(rpg->clock);
    int offset = sfTime_asMilliseconds(time);
    int length = sfTime_asMilliseconds(time) + 1000000.0;
    sfTimeSpan time_span = {{offset}, {length}};

    update_music(rpg, hud);
    if (!hud->display && hud->menu->escape == false) {
        if (rpg->player.state != IS_DEAD)
            handle_rpg(rpg, event, time_span);
        show_xy(&(rpg->player));
        resolve_player_sprint(&(rpg->player));
        display_rpg(rpg, head, hud);
    } else
        game_loop_menu(hud, rpg, head);
}

static void rpg_loop(rpg_t *rpg, tile_t *head, hud_t *hud)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &event))
            handle_events(rpg, &event, hud);
        game_loop(rpg, head, hud, event);
    }
}

int my_rpg(rpg_t *rpg, tile_t *head, hud_t *hud, stats_t *stats)
{
    if (loading_screen(rpg, &head, &hud, &stats) == 84)
        return 84;
    rpg_loop(rpg, head, hud);
    destroy_rpg(rpg, head, hud, stats);
    free_tiles(&head);
    return 0;
}
