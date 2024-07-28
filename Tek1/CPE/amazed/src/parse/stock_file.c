/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** stock_file
*/

#include "maze.h"
#include "my_string.h"
#include "my_stdlib.h"
#include "my_stdio.h"

static maze_t *init_maze(void)
{
    maze_t *maze = (maze_t *)malloc(sizeof(maze_t));

    maze->robots = 0;
    maze->i = 1;
    maze->lines = 0;
    maze->num_rooms = 0;
    maze->end.id = 0;
    maze->end.x = 0;
    maze->end.y = 0;
    maze->start.id = 0;
    maze->start.x = 0;
    maze->start.y = 0;
    maze->tmp = NULL;
    maze->links = NULL;
    maze->matrice = 0;
    return maze;
}

int parse_file(char **array, int lines)
{
    maze_t *maze = init_maze();

    maze->robots = my_atoi(array[0]);
    maze->lines = lines;
    display_file(maze, array);
    return 0;
}
