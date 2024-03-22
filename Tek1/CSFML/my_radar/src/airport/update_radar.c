/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** update_radar
*/

#include "../../include/radar.h"

void radar_update(radar_t *radar, float delta)
{
    radar->timer += delta;
    update_planes(radar, delta);
    update_collisions_and_status(radar);
}
