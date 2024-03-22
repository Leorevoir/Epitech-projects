/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** draw_radar
*/

#include "../../include/radar.h"

void draw_timer(radar_t *radar)
{
    char *timer_str = number_to_string(radar->timer);

    sfText_setString(radar->timer_value, timer_str);
    sfText_setString(radar->timer_text, "Time : ");
    sfRenderWindow_drawText(radar->window, radar->timer_value, NULL);
    sfRenderWindow_drawText(radar->window, radar->timer_text, NULL);
    free(timer_str);
}

void draw_stats(radar_t *radar)
{
    char *exploded_str = number_to_string(radar->planes_exploded);
    char *landed_str = number_to_string(radar->planes_landed);

    sfText_setString(radar->stats_exploded, exploded_str);
    sfText_setString(radar->stats_landed, landed_str);
    sfText_setString(radar->landed_text, "Landed: ");
    sfText_setString(radar->exploded_text, "Exploded: ");
    sfRenderWindow_drawText(radar->window, radar->landed_text, NULL);
    sfRenderWindow_drawText(radar->window, radar->exploded_text, NULL);
    sfRenderWindow_drawText(radar->window, radar->stats_landed, NULL);
    sfRenderWindow_drawText(radar->window, radar->stats_exploded, NULL);
    free(exploded_str);
    free(landed_str);
}

void radar_draw(radar_t *radar)
{
    sfRenderWindow_drawSprite(radar->window, radar->world_sprite, NULL);
    draw_planes(radar);
    draw_towers(radar);
    draw_timer(radar);
    draw_stats(radar);
}
