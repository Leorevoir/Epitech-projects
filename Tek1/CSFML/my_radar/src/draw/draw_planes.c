/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** draw_planes
*/

#include "../../include/radar.h"

void draw_planes(radar_t *radar)
{
    for (plane_t *plane = radar->planes; plane != NULL; plane = plane->next) {
        if (plane->status == EXPLOSION || plane->status == WAITING)
            continue;
        sfSprite_setPosition(radar->plane_sprite,
            (sfVector2f){plane->pos.x - 10, plane->pos.y - 10});
        sfRectangleShape_setPosition(radar->plane_hitbox,
            (sfVector2f){plane->pos.x - 10, plane->pos.y - 10});
        if (is_safe(radar, plane))
            sfRectangleShape_setOutlineColor(radar->plane_hitbox, sfYellow);
        else
            sfRectangleShape_setOutlineColor(radar->plane_hitbox, sfMagenta);
        if (radar->show_sprites)
            sfRenderWindow_drawSprite(radar->window,
                radar->plane_sprite, NULL);
        if (radar->show_hitboxes)
            sfRenderWindow_drawRectangleShape(radar->window,
                radar->plane_hitbox, NULL);
    }
}
