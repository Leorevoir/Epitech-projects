/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** radar_event
*/

#include "../../include/radar.h"

void parse_event(radar_t *radar, sfEvent *event)
{
    if (event->key.code == sfKeyL)
        radar->show_hitboxes = !radar->show_hitboxes;
    if (event->key.code == sfKeyS)
        radar->show_sprites = !radar->show_sprites;
}

void radar_event(radar_t *radar, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(radar->window);
    if (event->type == sfEvtKeyPressed)
        parse_event(radar, event);
}
