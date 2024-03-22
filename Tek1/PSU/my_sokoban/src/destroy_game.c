/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** destroy_game
*/

#include "../include/sokoban.h"

static void destroy_map(char **map, int rows)
{
    if (map != NULL) {
        for (int i = 0; i < rows; i++) {
            free(map[i]);
        }
        free(map);
    }
}

void destroy_game(map_t *map)
{
    if (map != NULL) {
        if (map->actual != NULL) {
            destroy_map(map->actual, map->row);
        }
        if (map->original != NULL) {
            destroy_map(map->original, map->row);
        }
        free(map->buffer);
        free(map);
    }
}
