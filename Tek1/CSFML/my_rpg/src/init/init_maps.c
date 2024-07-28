/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_maps
*/

#include "my_rpg.h"

void init_maps(rpg_t *rpg)
{
    sfVector2f pos = {0, 0};

    rpg->maps.map_road = init_object(MAP1, pos);
    rpg->maps.map_road_collision = sfImage_createFromFile(MAP1_COLLISIONS);
    rpg->maps.map_village_collision = sfImage_createFromFile(MAP2_COLLISIONS);
    rpg->maps.map_village = init_object(MAP2, pos);
    rpg->maps.map_boss = init_object(MAP3, pos);
    rpg->maps.map_boss_collision = sfImage_createFromFile(MAP3_COLLISIONS);
    rpg->background = &(rpg->maps.map_road);
    rpg->maps.current = rpg->maps.map_road_collision;
    rpg->maps.name_curr = strdup("road");
}
