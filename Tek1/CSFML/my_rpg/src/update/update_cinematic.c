/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_cinematic
*/

#include "update.h"

void update_cinematic(rpg_t *rpg, sfVector2f s, sfVector2f e)
{
    sfTime time = sfClock_getElapsedTime(rpg->boss->clock);
    float elapsed = sfTime_asSeconds(time);
    float dt = elapsed / 3.0f;
    float x = 0.0f;
    float y = 0.0f;
    sfVector2f current_pos = {0, 0};

    if (dt > 1.0f) {
        dt = 1.0f;
        rpg->cinema = false;
        rpg->last_cinema = false;
    }
    x = INTERPOLATE(s.x, e.x, dt);
    y = INTERPOLATE(s.y, e.y, dt);
    current_pos.x = x;
    current_pos.y = y;
    sfView_setCenter(rpg->view, current_pos);
    sfRenderWindow_setView(rpg->window, rpg->view);
}

void update_cinema(rpg_t *rpg)
{
    sfVector2f start = {303.91, 184.71};
    sfVector2f end = {303.91, 484.71};

    update_cinematic(rpg, start, end);
}

void update_last_cinema(rpg_t *rpg)
{
    sfVector2f v_start = {358.76, 93.93};
    sfVector2f v_end = {217.78, 386.42};

    update_cinematic(rpg, v_start, v_end);
}
