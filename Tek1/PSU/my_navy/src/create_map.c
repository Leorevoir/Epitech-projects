/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** create_map
*/

#include "../include/my_navy.h"

static int char_to_index(char c)
{
    return c - 'A';
}

static void place_ship_horizontally(map_t *map, int row, int col, int length)
{
    for (int i = 0; i < length; i++)
        map->grid[row][col + i] = length;
}

static void place_ship_vertically(map_t *map, int row, int col, int length)
{
    for (int i = 0; i < length; i++)
        map->grid[row + i][col] = length;
}

void fill_grid(map_t *map, char *start, char *end, int ship_length)
{
    int start_col = char_to_index(start[0]);
    int start_row = start[1] - '1';

    if (start[0] == end[0])
        place_ship_vertically(map, start_row, start_col, ship_length);
    else
        place_ship_horizontally(map, start_row, start_col, ship_length);
}
