/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** update_game
*/

#include "../include/sokoban.h"

static int sfr(map_t *map, int y, int x)
{
    int bbox_bouygues = 0;

    if (map->actual[y][x] == 'X' && map->original[y][x] == 'O') {
        bbox_bouygues++;
    }
    return bbox_bouygues;
}

static void check_win_condition(map_t *map)
{
    int bbox_bouygues = 0;

    for (int y = 0; y < map->row; y++) {
        for (int x = 0; x < map->col; x++)
            bbox_bouygues = sfr(map, y, x);
    }
    if (bbox_bouygues == map->o) {
        endwin();
        exit(0);
    }
}

static bool is_blocked(map_t *map, int x, int y)
{
    return (x < 0 || x >= map->col || y < 0
        || y >= map->row || map->actual[y][x] == '#'
        || map->actual[y][x] == 'X');
}

static bool is_player_blocked(map_t *map)
{
    int x = map->x;
    int y = map->y;

    return (is_blocked(map, x - 1, y) && is_blocked(map, x + 1, y)
        && is_blocked(map, x, y - 1) && is_blocked(map, x, y + 1));
}

static bool is_wall_or_box(map_t *map, int x, int y)
{
    return (x < 0 || x >= map->col || y < 0
        || y >= map->row || map->actual[y][x] == '#'
        || map->actual[y][x] == 'X');
}

static bool is_box_cornered(map_t *map, int x, int y)
{
    bool blocked_horizontally = (is_wall_or_box(map, x - 1, y)
        && is_wall_or_box(map, x + 1, y));
    bool blocked_vertically = (is_wall_or_box(map, x, y - 1)
        && is_wall_or_box(map, x, y + 1));

    return blocked_horizontally || blocked_vertically;
}

static bool are_bboxes_blocked(map_t *map, int y)
{
    for (int x = 0; map->col > x; x++) {
        if (map->actual[y][x] == 'X' && is_box_cornered(map, x, y))
            return true;
    }
    return false;
}

static bool are_boxes_blocked(map_t *map)
{
    for (int y = 0; y < map->row; y++) {
        if (are_bboxes_blocked(map, y))
            return true;
    }
    return false;
}

static void check_lose_condition(map_t *map)
{
    if (is_player_blocked(map) || are_boxes_blocked(map)) {
        endwin();
        exit(0);
    }
}

void refresh_map(map_t *map)
{
    check_win_condition(map);
    check_lose_condition(map);
}
