/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** destroy_entities
*/

#include "../../include/radar.h"

void plane_destroy(plane_t *plane)
{
    free(plane);
}

void tower_destroy(tower_t *tower)
{
    free(tower);
}

void destroy_sprite(radar_t *radar)
{
    plane_t *next_plane;
    tower_t *next_tower;

    for (plane_t *plane = radar->planes; plane != NULL;
        plane = next_plane) {
        next_plane = plane->next;
        plane_destroy(plane);
    }
    for (tower_t *tower = radar->towers; tower != NULL; tower = next_tower) {
        next_tower = tower->next;
        tower_destroy(tower);
    }
}
