/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** update_planes
*/

#include "../../include/radar.h"

void update_flying_planes(radar_t *radar, float delta)
{
    sfVector2f movement;
    float distance;

    for (plane_t *plane = radar->planes; plane != NULL;
        plane = plane->next) {
        if (plane->status == WAITING
            || plane->status == EXPLOSION)
            continue;
        movement.x = plane->velocity.x * delta;
        movement.y = plane->velocity.y * delta;
        plane->pos.x += movement.x;
        plane->pos.y += movement.y;
        distance = sqrt(movement.x * movement.x + movement.y * movement.y);
        plane->distance -= distance;
        if (plane->distance <= 0)
            plane->status = LANDED;
    }
}

void update_waiting_planes(radar_t *radar, float delta)
{
    for (plane_t *plane = radar->planes; plane != NULL;
        plane = plane->next) {
        if (plane->status != WAITING)
            continue;
        plane->delay -= delta;
        if (plane->delay <= 0)
            plane->status = FLYING;
    }
}

void update_planes(radar_t *radar, float delta)
{
    update_waiting_planes(radar, delta);
    update_flying_planes(radar, delta);
}
