/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** is_finished
*/

#include "../include/my_navy.h"

int check_my_ship(map_t *map, int i)
{
    for (int j = 0; j < 8; j++) {
        if (map->grid[i][j] > 0 && map->grid[i][j] != 'x') {
            return 1;
        }
    }
    return 0;
}

int are_all_ships_sunk(map_t *map)
{
    for (int i = 0; i < 8; i++) {
        if (check_my_ship(map, i))
            return 0;
    }
    return 1;
}

int game_not_finished(map_t *my_map)
{
    return (!are_all_ships_sunk(my_map));
}
