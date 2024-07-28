/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** display
*/

#include "maze.h"
#include "my_stdio.h"
#include "my_string.h"
#include "my_stdlib.h"

static void update_i_if(maze_t *maze, char **array, const char *str, int a)
{
    if (a == 0) {
        if (my_strcmp(array[maze->i + 1], str) != 0)
            maze->i++;
    }
    if (a == 1) {
        if (my_strchr(array[maze->i + 1], *str) == NULL)
            maze->i++;
    }
}

static void display_tunnels(char **array, maze_t *maze)
{
    bool tunnel = false;

    for (; maze->i < maze->lines; maze->i++) {
        if (my_strchr(array[maze->i], '-') != NULL && !tunnel) {
            my_printf("##tunnels\n");
            tunnel = true;
        }
        my_printf("%s", array[maze->i]);
        str_to_array(&maze->links, array[maze->i]);
    }
}

static void display_end(char **array, maze_t *maze)
{
    bool end = false;
    char *compare = NULL;

    for (; my_strchr(array[maze->i], '-') == NULL; maze->i++) {
        if (my_strcmp(array[maze->i], "##end\n") == 0 && !end) {
            my_printf("##end\n");
            maze->i++;
            my_printf("%s", array[maze->i]);
            maze->end = create_room(array[maze->i]);
            compare = my_strdup(array[maze->i]);
            update_i_if(maze, array, "-", 1);
            maze->num_rooms++;
            end = true;
        }
        if (my_strcmp(array[maze->i], compare) != 0)
            str_to_array(&maze->tmp, array[maze->i]);
    }
}

static void display_start(char **array, maze_t *maze)
{
    bool start = false;
    char *compare = NULL;

    for (; my_strcmp(array[maze->i], "##end\n") != 0; maze->i++) {
        if (my_strcmp(array[maze->i], "##start\n") == 0 && !start) {
            my_printf("##start\n");
            maze->i++;
            my_printf("%s", array[maze->i]);
            maze->start = create_room(array[maze->i]);
            compare = my_strdup(array[maze->i]);
            update_i_if(maze, array, "##end\n", 0);
            maze->num_rooms++;
            start = true;
        }
        if (my_strcmp(array[maze->i], compare) != 0)
            str_to_array(&maze->tmp, array[maze->i]);
    }
}

static void display_rooms(maze_t *maze)
{
    for (size_t i = 0; maze->tmp[i]; i++)
        my_printf("%s", maze->tmp[i]);
}

static void display_moves(maze_t *maze)
{
    path_t path = init_pathfinding(maze);

    algo_pathfinding(maze, &path);
    my_printf("#moves\n");
    move_robots(maze, &path);
    free(path.distance);
    free(path.end_room);
}

static int count_rooms(maze_t *maze)
{
    int i = 0;

    for (; maze->tmp[i]; i++);
    return i;
}

void display_file(maze_t *maze, char **array)
{
    my_printf("#numer_of_robots\n%d\n", maze->robots);
    my_printf("#rooms\n");
    display_start(array, maze);
    display_end(array, maze);
    display_rooms(maze);
    display_tunnels(array, maze);
    maze->num_rooms += count_rooms(maze);
    maze->matrice = adjacent_matrix(maze->links, maze->num_rooms);
    display_moves(maze);
    free_tmp_array(maze->tmp);
    free_tmp_array(maze->links);
    free_matrice(maze->matrice);
    free(maze);
}
