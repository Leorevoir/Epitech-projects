/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_rpg
*/

#include "my_rpg.h"

void init_view(rpg_t *rpg)
{
    rpg->view = sfView_create();
    sfView_setSize(rpg->view, (sfVector2f){384.0f, 216.0f});
    sfView_setCenter(rpg->view, rpg->player.object.position);
}

static void set_player_to_null(rpg_t *rpg)
{
    rpg->background = NULL;
    rpg->player.object.position = (sfVector2f){0};
    rpg->player.object.texture = NULL;
    rpg->player.object.sprite = NULL;
    for (int i = 0; i < COUNT; i++)
        rpg->player.textures[i] = NULL;
    rpg->player.hit_clock = NULL;
    rpg->game_finished = false;
}

void init_all_rpg(rpg_t *rpg, hud_t **hud, stats_t **stats)
{
    set_player_to_null(rpg);
    init_window(rpg);
    init_menu(hud, rpg);
    init_escape_menu(hud, rpg);
    init_character_choose(hud, rpg);
    init_settings_hud(hud, rpg);
    init_view(rpg);
    init_maps(rpg);
    init_boss(rpg);
    init_npc(rpg);
    init_text(rpg);
    init_inventory(rpg, stats);
    init_ui(rpg);
    init_music(rpg);
}

static void init_weather(rpg_t *rpg)
{
    rpg->weather = (weather_t *) malloc(sizeof(weather_t));
    rpg->weather->night = false;
    rpg->weather->autumn = false;
    rpg->weather->autumn_filter = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->weather->autumn_filter,
        (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(rpg->weather->autumn_filter,
        (sfColor){255, 165, 0, 45});
    rpg->weather->night_filter = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->weather->night_filter,
        (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(rpg->weather->night_filter,
        sfColor_fromRGBA(0, 0, 50, 160));
}

int init_all_chat_boxes(rpg_t *rpg)
{
    if (init_chat_box(rpg->dialogue, rpg, "assets/quest.conf") == 84)
        return FAILURE;
    if (init_chat_box_eng(rpg->dialogue_eng, rpg,
        "assets/quest_eng.conf") == 84)
        return FAILURE;
    return SUCCESS;
}

int init_rpg(rpg_t *rpg, tile_t **head, hud_t **hud, stats_t **stats)
{
    if (load_stats(stats, STATS) == 84)
        return FAILURE;
    if (load_tile(head, TILES) == 84)
        return FAILURE;
    if (init_all_chat_boxes(rpg) == 84)
        return FAILURE;
    if (!head)
        return FAILURE;
    init_all_rpg(rpg, hud, stats);
    rpg->cinema = false;
    rpg->last_cinema = false;
    rpg->tool.who = -1;
    rpg->tool.menu = true;
    rpg->clock = sfClock_create();
    init_weather(rpg);
    rpg->rebuilt = false;
    rpg->disp_lvl_up = false;
    rpg->lang = FRENCH;
    return SUCCESS;
}
