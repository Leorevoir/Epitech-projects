/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** create_planes
*/

#include "../../include/radar.h"

void create_plane(radar_t *radar)
{
    radar->plane_sprite = sfSprite_create();
    sfSprite_setTexture(radar->plane_sprite, radar->plane_texture,
        sfTrue);
    radar->plane_hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(radar->plane_hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(radar->plane_hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(radar->plane_hitbox, 1);
    sfRectangleShape_setOutlineColor(radar->plane_hitbox, sfMagenta);
}
