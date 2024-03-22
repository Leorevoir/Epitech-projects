/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** update_status
*/

#include "../../include/radar.h"

void detect_collisions(radar_t *radar)
{
    for (plane_t *plane = radar->planes; plane != NULL;
        plane = plane->next)
        for (plane_t *other = radar->planes; other != NULL;
            other = other->next)
            detect_collision(radar, plane, other);
}

void detect_collision(radar_t *radar, plane_t *plane,
    plane_t *other)
{
    if (plane == other
        || plane->status == WAITING
        || plane->status == EXPLOSION
        || other->status == WAITING
        || other->status == EXPLOSION)
        return;
    if (plane_collides(plane, other)) {
        if (!is_safe(radar, plane))
            plane->status = BOOM;
        if (!is_safe(radar, other))
            other->status = BOOM;
    }
}

void update_planes_status(radar_t *radar)
{
    int all_destroyed = 1;

    for (plane_t *plane = radar->planes; plane != NULL; plane = plane->next) {
        if (plane->status != EXPLOSION)
            all_destroyed = 0;
        if (plane->status == LANDED) {
            radar->planes_landed++;
            plane->status = EXPLOSION;
        }
        if (plane->status == BOOM) {
            radar->planes_exploded++;
            plane->status = EXPLOSION;
        }
    }
    if (all_destroyed)
        sfRenderWindow_close(radar->window);
}

void update_collisions_and_status(radar_t *radar)
{
    detect_collisions(radar);
    update_planes_status(radar);
}
