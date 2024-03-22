/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** create_towers
*/

#include "../../include/radar.h"

void create_tower(radar_t *radar)
{
    radar->tower_sprite = sfSprite_create();
    sfSprite_setTexture(radar->tower_sprite, radar->tower_texture, sfTrue);
    radar->tower_radius = sfCircleShape_create();
    sfCircleShape_setFillColor(radar->tower_radius, sfTransparent);
    sfCircleShape_setOutlineColor(radar->tower_radius, sfCyan);
    sfCircleShape_setOutlineThickness(radar->tower_radius, 1.0f);
    sfCircleShape_setPointCount(radar->tower_radius, 100);
}

tower_t *tower_create(sfVector2f position, float radius_percentage)
{
    float screen_width = 1920;
    float actual_radius = screen_width * (radius_percentage / 100.0);
    tower_t *tower = malloc(sizeof(tower_t));

    tower->pos = position;
    tower->radius = actual_radius;
    tower->next = NULL;
    return tower;
}
