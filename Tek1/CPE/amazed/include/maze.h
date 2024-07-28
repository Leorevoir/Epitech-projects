/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** maze
*/

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#ifndef MAZE_H_
    #define MAZE_H_
    #define ERROR 84
    #define SUCCESS 0

typedef struct lap_s {
    bool *occupied;
    bool *moved_this_turn;
    int *current_pos;
    int i;
} lap_t;

typedef struct path_s {
    int *end_room;
    int *distance;
    int *robot;
    int id;
} path_t;

typedef struct room_s {
    int id;
    int x;
    int y;
} room_t;

typedef struct maze_s {
    int robots;
    int lines;
    int i;
    int num_rooms;
    room_t start;
    room_t end;
    char **tmp;
    char **links;
    int **matrice;
} maze_t;

////////////////////////////////////////////////////////////////
int read_labyrinth(void);
int parse_file(char **array, int lines);

////////////////////////////////////////////////////////////////
void display_file(maze_t *maze, char **array);

////////////////////////////////////////////////////////////////
room_t create_room(const char *str);
path_t init_pathfinding(maze_t *maze);
int **adjacent_matrix(char **links, int num_rooms);

////////////////////////////////////////////////////////////////
void move_robots(maze_t *maze, path_t *path);
void algo_pathfinding(maze_t *maze, path_t *path);

////////////////////////////////////////////////////////////////
void free_tmp_array(char **tmp);
void free_matrice(int **matrix);
void free_word_array(char **array, int size);

#endif /* !MAZE_H_ */
