/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** create_radar
*/

#include "../../include/radar.h"

void radar_create(radar_t *radar)
{
    radar->world_sprite = sfSprite_create();
    sfSprite_setTexture(radar->world_sprite, radar->world_texture,
        sfTrue);
    create_plane(radar);
    create_tower(radar);
}
