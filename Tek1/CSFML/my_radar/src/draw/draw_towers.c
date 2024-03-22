/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** draw_towers
*/

#include "../../include/radar.h"

void draw_towers(radar_t *radar)
{
    for (tower_t *tower = radar->towers; tower != NULL;
        tower = tower->next) {
        sfSprite_setPosition(radar->tower_sprite,
            (sfVector2f){tower->pos.x - 32, tower->pos.y - 32});
        sfCircleShape_setPosition(radar->tower_radius,
            (sfVector2f){tower->pos.x - tower->radius,
                tower->pos.y - tower->radius});
        sfCircleShape_setRadius(radar->tower_radius, tower->radius);
        if (radar->show_sprites)
            sfRenderWindow_drawSprite(radar->window, radar->tower_sprite,
                NULL);
        if (radar->show_hitboxes)
            sfRenderWindow_drawCircleShape(radar->window, radar->tower_radius,
                NULL);
    }
}
