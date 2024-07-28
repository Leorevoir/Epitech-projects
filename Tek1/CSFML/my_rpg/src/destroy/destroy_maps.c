/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_maps
*/

#include "my_rpg.h"

void destroy_maps(maps_t maps)
{
    destroy_object(&maps.map_road);
    destroy_object(&maps.map_village);
    destroy_object(&maps.map_boss);
    sfImage_destroy(maps.map_road_collision);
    sfImage_destroy(maps.map_village_collision);
    sfImage_destroy(maps.map_boss_collision);
    free(maps.name_curr);
}
