/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** my_game
*/

#include "../include/sokoban.h"

static void reset_game(map_t *map)
{
    map->x = map->original_x;
    map->y = map->original_y;
    for (int i = 0; i < map->row; i++) {
        for (int j = 0; j < map->col; j++)
            map->actual[i][j] = map->original[i][j];
    }
}

static void handle_key_event(map_t *map, int key)
{
    switch (key) {
        case KEY_UP:
            move_player(map, UP);
            break;
        case KEY_DOWN:
            move_player(map, DOWN);
            break;
        case KEY_LEFT:
            move_player(map, LEFT);
            break;
        case KEY_RIGHT:
            move_player(map, RIGHT);
            break;
        case 32:
            reset_game(map);
            break;
    }
}

static void display_map(map_t *map)
{
    clear();
    for (int i = 0; i < map->row; i++)
        mvprintw(i, 0, "%s", map->actual[i]);
}

void ncurses_loop(map_t *map)
{
    int key;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
    for (;;) {
        display_map(map);
        key = getch();
        if (key == -1)
            exit(84);
        if (key == 27) {
            endwin();
            exit(0);
        }
        handle_key_event(map, key);
        refresh_map(map);
    }
    endwin();
}
