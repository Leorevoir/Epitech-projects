/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** print_moves
*/

#include "my_stdlib.h"
#include "my_string.h"
#include "my_stdio.h"
#include "maze.h"

static int next_node(maze_t *maze, path_t *path, int pos)
{
    for (int j = 0; j < maze->num_rooms; j++) {
        if (maze->matrice[pos][j] > 0
            && path->distance[pos] == path->distance[j] + 1) {
            return j;
        }
    }
    return pos;
}

static void init_robots(int num_robots, int start_id, int *current_pos)
{
    for (int i = 0; i < num_robots; i++) {
        current_pos[i] = start_id;
    }
}

static bool move_robot_if_possible(maze_t *maze, path_t *path,
    lap_t *lap, int i)
{
    int next_pos = next_node(maze, path, lap->current_pos[i]);

    if (next_pos != lap->current_pos[i] && !lap->occupied[next_pos]) {
        my_printf("P%d-%d ", i + 1, next_pos);
        lap->occupied[lap->current_pos[i]] = false;
        lap->current_pos[i] = next_pos;
        lap->occupied[next_pos] = true;
        lap->moved_this_turn[i] = true;
        return (next_pos == maze->end.id);
    }
    return false;
}

static void move_if_possible(maze_t *maze, path_t *path, lap_t *lap,
    bool *all_finished)
{
    bool finished = false;

    if (lap->current_pos[lap->i] != maze->end.id
        && !lap->moved_this_turn[lap->i]) {
        finished = move_robot_if_possible(maze, path, lap, lap->i);
        if (!finished) {
            *all_finished = false;
        }
    }
}

static bool update_positions(maze_t *maze, path_t *path, lap_t *lap)
{
    bool all_finished = true;

    for (int i = 0; i < maze->robots; i++) {
        lap->i = i;
        move_if_possible(maze, path, lap, &all_finished);
    }
    return all_finished;
}

static lap_t *init_lap(maze_t *maze)
{
    lap_t *lap = (lap_t *)malloc(sizeof(lap_t));

    lap->occupied = (bool *)my_calloc(maze->num_rooms, sizeof(bool));
    lap->moved_this_turn = (bool *)my_calloc(maze->robots, sizeof(bool));
    lap->current_pos = (int *)my_calloc(maze->robots, sizeof(int));
    lap->i = 0;
    return lap;
}

static void destroy_lap(lap_t *lap)
{
    free(lap->occupied);
    free(lap->moved_this_turn);
    free(lap->current_pos);
    free(lap);
}

void move_robots(maze_t *maze, path_t *path)
{
    bool all_finished = false;
    lap_t *lap = init_lap(maze);

    init_robots(maze->robots, maze->start.id, lap->current_pos);
    while (!all_finished) {
        my_memset(lap->moved_this_turn, 0, maze->robots * sizeof(bool));
        lap->occupied[maze->start.id] = false;
        lap->occupied[maze->end.id] = false;
        all_finished = update_positions(maze, path, lap);
        my_printf("\n");
    }
    destroy_lap(lap);
}
