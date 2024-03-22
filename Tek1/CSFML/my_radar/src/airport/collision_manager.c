/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** collision_management
*/

#include "../../include/radar.h"

int is_safe(radar_t *radar, plane_t *plane)
{
    for (tower_t *tower = radar->towers; tower != NULL; tower = tower->next)
        if (tower_collides(tower, plane))
            return 1;
    return 0;
}

int is_inside(tower_t *tower, sfVector2f position)
{
    return (tower->pos.x - position.x) * (tower->pos.x - position.x)
        + (tower->pos.y - position.y) * (tower->pos.y - position.y)
        <= tower->radius * tower->radius;
}

int tower_collides(tower_t *tower, plane_t *plane)
{
    return is_inside(tower, plane->pos)
        || is_inside(tower, (sfVector2f){plane->pos.x + 20,
            plane->pos.y})
        || is_inside(tower, (sfVector2f){plane->pos.x,
            plane->pos.y + 20})
        || is_inside(tower, (sfVector2f){plane->pos.x + 20,
            plane->pos.y + 20});
}
