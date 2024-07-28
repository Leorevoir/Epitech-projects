/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** pathfinding
*/

#include "maze.h"
#include "my_stdio.h"
#include "my_string.h"
#include "my_stdlib.h"

path_t init_pathfinding(maze_t *maze)
{
    path_t path = {0};

    path.distance = (int *)malloc(sizeof(int) * maze->num_rooms);
    path.end_room = (int *)malloc(sizeof(int) * maze->num_rooms);
    for (int i = 0; i < maze->num_rooms; i++) {
        path.distance[i] = INT_MAX;
        path.end_room[i] = 0;
    }
    path.distance[maze->end.id] = 0;
    path.robot = (int *)malloc(maze->robots * sizeof(int));
    for (int i = 0; i < maze->robots; i++)
        path.robot[i] = maze->start.id;
    return path;
}

static void get_new_short_way(path_t *path, int *new_distance, int i,
    int *new_i)
{
    if (path->end_room[i] == 0
        && path->distance[i] <= *new_distance) {
        *new_distance = path->distance[i];
        *new_i = i;
    }
}

static int find_new_way(maze_t *maze, path_t *path)
{
    int new_distance = INT_MAX;
    int new_i = 0;

    for (int i = 0; i < maze->num_rooms; i++)
        get_new_short_way(path, &new_distance, i, &new_i);
    path->end_room[new_i] = 1;
    return new_i;
}

static void new_distance_if_shorter(maze_t *maze, path_t *path, int i,
    int new_short)
{
    if (!path->end_room[i]
        && maze->matrice[new_short][i] > 0
        && path->distance[new_short] != INT_MAX
        && (path->distance[new_short] + maze->matrice[new_short][i])
            < path->distance[i]) {
        path->distance[i] = (
            path->distance[new_short] + maze->matrice[new_short][i]
        );
    }
}

static void resolve_path(maze_t *maze, path_t *path)
{
    int new_short = find_new_way(maze, path);

    for (int i = 0; i < maze->num_rooms; i++) {
        new_distance_if_shorter(maze, path, i, new_short);
    }
}

void algo_pathfinding(maze_t *maze, path_t *path)
{
    int num_loop = maze->num_rooms - 1;

    for (int i = 0; i < num_loop; i++)
        resolve_path(maze, path);
}
