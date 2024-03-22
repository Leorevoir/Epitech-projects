/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** init_positions
*/

#include "../include/sokoban.h"

static void save_player_pos(map_t *map, int i, int *player_count)
{
    char cell;

    for (int j = 0; j < map->col; j++) {
        cell = map->actual[i][j];
        if (cell == 'P') {
            map->x = j;
            map->y = i;
            (*player_count)++;
        }
    }
}

static void count_o_in_map(map_t *map, int i, int *o_count)
{
    char cell;

    for (int j = 0; j < map->col; j++) {
        cell = map->actual[i][j];
        if (cell == 'O') {
            (*o_count)++;
        }
    }
}

void init_position(map_t *map)
{
    int player_count = 0;

    map->o_count = 0;
    for (int i = 0; i < map->row; i++) {
        save_player_pos(map, i, &player_count);
        count_o_in_map(map, i, &(map->o_count));
    }
    if (player_count != 1)
        exit(84);
    map->o = map->o_count;
    map->original_x = map->x;
    map->original_y = map->y;
}
