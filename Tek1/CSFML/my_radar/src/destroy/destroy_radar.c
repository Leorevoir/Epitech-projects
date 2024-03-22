/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** destroy_radar
*/

#include "../../include/radar.h"

void radar_destroy(radar_t *radar)
{
    destroy_sprite(radar);
    sfSprite_destroy(radar->world_sprite);
    sfSprite_destroy(radar->plane_sprite);
    sfSprite_destroy(radar->tower_sprite);
    sfRectangleShape_destroy(radar->plane_hitbox);
    sfCircleShape_destroy(radar->tower_radius);
    sfTexture_destroy(radar->world_texture);
    sfTexture_destroy(radar->plane_texture);
    sfTexture_destroy(radar->tower_texture);
    sfRenderWindow_destroy(radar->window);
    sfFont_destroy(radar->timer_font);
    sfText_destroy(radar->timer_value);
    sfText_destroy(radar->timer_text);
    sfText_destroy(radar->exploded_text);
    sfText_destroy(radar->landed_text);
    sfText_destroy(radar->stats_exploded);
    sfText_destroy(radar->stats_landed);
}
