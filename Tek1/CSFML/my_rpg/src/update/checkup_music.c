/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** checkup_music
*/

#include "my_rpg.h"

static void checkup_road_music(rpg_t *rpg, hud_t *hud)
{
    if ((hud->display && hud->menu->escape == true)
    && sfMusic_getStatus(rpg->music.road) != sfPlaying
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

static void checkup_village_music(rpg_t *rpg, hud_t *hud)
{
    if ((hud->display && hud->menu->escape == true)
    && sfMusic_getStatus(rpg->music.village) != sfPlaying
    && strcmp(rpg->maps.name_curr, "village") == 0
    && rpg->music.music == true) {
        sfMusic_stop(rpg->music.menu);
        sfMusic_stop(rpg->music.road);
        sfMusic_stop(rpg->music.boss);
        if (sfMusic_getStatus(rpg->music.village) != sfPlaying) {
            sfMusic_setLoop(rpg->music.village, sfTrue);
            sfMusic_play(rpg->music.village);
        }
    }
}

static void checkup_boss_music(rpg_t *rpg, hud_t *hud)
{
    if ((hud->display && hud->menu->escape == true)
    && sfMusic_getStatus(rpg->music.boss) != sfPlaying
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

void checkup_music(rpg_t *rpg, hud_t *hud)
{
    checkup_road_music(rpg, hud);
    checkup_boss_music(rpg, hud);
    checkup_village_music(rpg, hud);
}
