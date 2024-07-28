/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_music
*/

#include "my_rpg.h"

static void launch_menu_music(rpg_t *rpg, hud_t *hud)
{
    if (hud->display == true && hud->menu->escape == false
    && rpg->music.music == true)
        if (sfMusic_getStatus(rpg->music.menu) != sfPlaying) {
            sfMusic_setLoop(rpg->music.menu, sfTrue);
            sfMusic_play(rpg->music.menu);
        }
}

static void launch_road_music(rpg_t *rpg, hud_t *hud)
{
    if (!hud->display && sfMusic_getStatus(rpg->music.road) != sfPlaying
    && strcmp(rpg->maps.name_curr, "road") == 0
    && rpg->music.music == true) {
        sfMusic_stop(rpg->music.menu);
        sfMusic_stop(rpg->music.village);
        sfMusic_stop(rpg->music.boss);
        if (sfMusic_getStatus(rpg->music.road) != sfPlaying) {
            sfMusic_setLoop(rpg->music.road, sfTrue);
            sfMusic_play(rpg->music.road);
        }
    }
}

static void launch_village_music(rpg_t *rpg, hud_t *hud)
{
    if (!hud->display && sfMusic_getStatus(rpg->music.village) != sfPlaying
    && strcmp(rpg->maps.name_curr, "village") == 0
    && rpg->music.music == true) {
        sfMusic_stop(rpg->music.menu);
        sfMusic_stop(rpg->music.road);
        sfMusic_stop(rpg->music.boss);
        if (sfMusic_getStatus(rpg->music.village) != sfPlaying
        && !rpg->rebuilt) {
            sfMusic_setLoop(rpg->music.village, sfTrue);
            sfMusic_play(rpg->music.village);
        }
        if (sfMusic_getStatus(rpg->music.win) != sfPlaying
        && rpg->rebuilt) {
            sfMusic_setLoop(rpg->music.win, sfTrue);
            sfMusic_play(rpg->music.win);
        }
    }
}

static void launch_boss_music(rpg_t *rpg, hud_t *hud)
{
    if (!hud->display && sfMusic_getStatus(rpg->music.boss) != sfPlaying
    && strcmp(rpg->maps.name_curr, "boss") == 0
    && rpg->music.music == true) {
        sfMusic_stop(rpg->music.menu);
        sfMusic_stop(rpg->music.road);
        sfMusic_stop(rpg->music.village);
        if (sfMusic_getStatus(rpg->music.boss) != sfPlaying) {
            sfMusic_setLoop(rpg->music.boss, sfTrue);
            sfMusic_play(rpg->music.boss);
        }
    }
}

static void launch_lose_music(rpg_t *rpg, hud_t *hud)
{
    if (!hud->display && sfMusic_getStatus(rpg->music.boss) != sfPlaying
    && rpg->player.state == IS_DEAD
    && rpg->music.music == true) {
        sfMusic_stop(rpg->music.menu);
        sfMusic_stop(rpg->music.road);
        sfMusic_stop(rpg->music.village);
        sfMusic_stop(rpg->music.boss);
        if (sfMusic_getStatus(rpg->music.lose) != sfPlaying) {
            sfMusic_setLoop(rpg->music.lose, sfTrue);
            sfMusic_play(rpg->music.lose);
        }
    }
    if (rpg->player.state != IS_DEAD)
        sfMusic_stop(rpg->music.lose);
}

void update_music(rpg_t *rpg, hud_t *hud)
{
    launch_menu_music(rpg, hud);
    launch_road_music(rpg, hud);
    launch_village_music(rpg, hud);
    launch_boss_music(rpg, hud);
    launch_lose_music(rpg, hud);
    if (rpg->music.music == false) {
        sfMusic_stop(rpg->music.menu);
        sfMusic_stop(rpg->music.road);
        sfMusic_stop(rpg->music.boss);
        sfMusic_stop(rpg->music.village);
        sfMusic_stop(rpg->music.win);
        sfMusic_stop(rpg->music.lose);
    }
    if (rpg->music.sound == false) {
        sfMusic_stop(rpg->music.heal_sound);
        sfMusic_stop(rpg->music.swing_sound);
    }
}
