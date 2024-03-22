/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** player_movements
*/

#include "../include/sokoban.h"

static void move_left(map_t *map)
{
    int x = map->x;
    int y = map->y;

    if (x - 1 < 0 || x - 2 < 0)
        return;
    if (map->actual[y][x - 1] == ' '
        || map->actual[y][x - 1] == 'O') {
        map->actual[y][x - 1] = 'P';
        map->actual[y][x] = (map->original[y][x] == 'O') ? 'O' : ' ';
        map->x -= 1;
    } else if (map->actual[y][x - 1] == 'X' && (map->actual[y][x - 2] == ' '
        || map->actual[y][x - 2] == 'O')) {
        map->actual[y][x - 2] = 'X';
        map->actual[y][x - 1] = 'P';
        map->actual[y][x] = (map->original[y][x] == 'O') ? 'O' : ' ';
        map->x -= 1;
    }
}

static void move_right(map_t *map)
{
    int x = map->x;
    int y = map->y;

    if (x + 1 >= map->col || x + 2 >= map->col)
        return;
    if (map->actual[y][x + 1] == ' '
        || map->actual[y][x + 1] == 'O') {
        map->actual[y][x + 1] = 'P';
        map->actual[y][x] = (map->original[y][x] == 'O') ? 'O' : ' ';
        map->x += 1;
    } else if (map->actual[y][x + 1] == 'X' && (map->actual[y][x + 2] == ' '
        || map->actual[y][x + 2] == 'O')) {
        map->actual[y][x + 2] = 'X';
        map->actual[y][x + 1] = 'P';
        map->actual[y][x] = (map->original[y][x] == 'O') ? 'O' : ' ';
        map->x += 1;
    }
}

static void move_up(map_t *map)
{
    int x = map->x;
    int y = map->y;

    if (y - 1 < 0 || y - 2 < 0)
        return;
    if (map->actual[y - 1][x] == ' '
        || map->actual[y - 1][x] == 'O') {
        map->actual[y - 1][x] = 'P';
        map->actual[y][x] = (map->original[y][x] == 'O') ? 'O' : ' ';
        map->y -= 1;
    } else if (map->actual[y - 1][x] == 'X' && (map->actual[y - 2][x] == ' '
        || map->actual[y - 2][x] == 'O')) {
        map->actual[y - 2][x] = 'X';
        map->actual[y - 1][x] = 'P';
        map->actual[y][x] = (map->original[y][x] == 'O') ? 'O' : ' ';
        map->y -= 1;
    }
}

static void move_down(map_t *map)
{
    int x = map->x;
    int y = map->y;

    if (y + 1 >= map->row || y + 2 >= map->row)
        return;
    if (map->actual[y + 1][x] == ' '
        || map->actual[y + 1][x] == 'O') {
        map->actual[y + 1][x] = 'P';
        map->actual[y][x] = (map->original[y][x] == 'O') ? 'O' : ' ';
        map->y += 1;
    } else if (map->actual[y + 1][x] == 'X' && (map->actual[y + 2][x] == ' '
        || map->actual[y + 2][x] == 'O')) {
        map->actual[y + 2][x] = 'X';
        map->actual[y + 1][x] = 'P';
        map->actual[y][x] = (map->original[y][x] == 'O') ? 'O' : ' ';
        map->y += 1;
    }
}

void move_player(map_t *map, int direction)
{
    switch (direction) {
        case LEFT:
            move_left(map);
            break;
        case RIGHT:
            move_right(map);
            break;
        case UP:
            move_up(map);
            break;
        case DOWN:
            move_down(map);
            break;
    }
}
