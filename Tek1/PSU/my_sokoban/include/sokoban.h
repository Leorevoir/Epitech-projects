/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** sokoban
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_
    #define UP 1
    #define DOWN 2
    #define LEFT 3
    #define RIGHT 4

typedef struct map_s {
    char **original;
    char **actual;
    char *buffer;
    int fd;
    char x;
    char y;
    char o;
    int col;
    int row;
    int player;
    int original_x;
    int original_y;
    int o_count;
} map_t;

void usage(void);
void init_position(map_t *map);
int init_map(map_t *map, char *path);
void init_character(map_t *map);
void refresh_map(map_t *map);
void destroy_game(map_t *map);
void ncurses_loop(map_t *map);
int my_strlen(const char *str);
void my_putstr(const char *str);
void move_player(map_t *map, int direction);
int my_strcmp(const char *s1, const char *s2);
int parse_arguments(int argc, char **argv, map_t *map);


#endif /* !SOKOBAN_H_ */
