/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** init_map
*/

#include "../include/sokoban.h"

static int read_map(map_t *map, char *file_path)
{
    char *buffer_temp = malloc(sizeof(char) * 2);
    int buffer_size = 0;
    int fd = open(file_path, O_RDONLY);

    if (fd == -1 || buffer_temp == NULL)
        return 84;
    while (read(fd, buffer_temp, 1) == 1)
        buffer_size++;
    close(fd);
    map->fd = open(file_path, O_RDONLY);
    if (map->fd == -1)
        return 84;
    map->buffer = malloc(sizeof(char) * (buffer_size + 1));
    if (map->buffer == NULL)
        return 84;
    read(map->fd, map->buffer, buffer_size);
    map->buffer[buffer_size] = '\0';
    close(map->fd);
    free(buffer_temp);
    return 0;
}

static int maximmuum(int cols, int max_cols)
{
    if (cols > max_cols)
        return cols;
    return max_cols;
}

static void calculate_map(map_t *map)
{
    int rows = 1;
    int cols = 0;
    int max_cols = 0;

    map->o = 0;
    for (int i = 0; map->buffer[i] != '\0'; i++) {
        if (map->buffer[i] == 'O')
            map->o++;
        if (map->buffer[i] == '\n') {
            rows++;
            max_cols = maximmuum(cols, max_cols);
            cols = 0;
        } else
            cols++;
    }
    map->col = max_cols;
    map->row = rows;
}

static int get_column_length(const char *buffer, int *index)
{
    int column = 0;

    while (buffer[*index] != '\n' && buffer[*index] != '\0') {
        column++;
        (*index)++;
    }
    return column;
}

static void copy_buffer_to_map(map_t *map, int k, int j, int column)
{
    map->actual[k] = malloc(sizeof(char) * (column + 1));
    map->original[k] = malloc(sizeof(char) * (column + 1));
    if (!map->actual[k] || !map->original[k])
        exit(84);
    for (int i = 0; i < column; i++) {
        map->actual[k][i] = map->buffer[j - column + i];
        map->original[k][i] = map->buffer[j - column + i];
    }
    map->actual[k][column] = '\0';
    map->original[k][column] = '\0';
}

static void init_column_and_row(map_t *map)
{
    int j = 0;
    int column;

    for (int k = 0; k < map->row; k++) {
        column = get_column_length(map->buffer, &j);
        copy_buffer_to_map(map, k, j, column);
        if (map->buffer[j] == '\n')
            j++;
    }
}

static void init_sokoban(map_t *map)
{
    map->actual = malloc(sizeof(char *) * (map->row) + 1);
    map->original = malloc(sizeof(char *) * (map->row) + 1);
    if (!map->actual || !map->original) {
        write(2, "Error: memory allocation failed", 32);
        exit(84);
    }
    init_column_and_row(map);
    init_position(map);
    ncurses_loop(map);
}

int init_map(map_t *map, char *path)
{
    if (read_map(map, path) == 84)
        return 84;
    calculate_map(map);
    init_character(map);
    init_sokoban(map);
    return 0;
}
