/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** matrice
*/

#include "maze.h"
#include "my_string.h"
#include "my_stdlib.h"

int extract_room_id(const char *link, int index)
{
    int room_id = 0;
    const char *ptr = link;
    int dash_count = 0;

    while (*ptr && dash_count < index) {
        if (*ptr == '-')
            dash_count++;
        ptr++;
    }
    while (*ptr && *ptr == '-')
        ptr++;
    while (*ptr && *ptr >= '0' && *ptr <= '9') {
        room_id = room_id * 10 + (*ptr - '0');
        ptr++;
    }
    return room_id;
}

int **create_zero_filled_matrix(int num_rooms)
{
    int **matrix = (int **)malloc(num_rooms * sizeof(int *));
    int *data = (int *)malloc(num_rooms * num_rooms * sizeof(int));

    for (int i = 0; i < num_rooms; ++i) {
        matrix[i] = &data[i * num_rooms];
        for (int j = 0; j < num_rooms; ++j)
            matrix[i][j] = 0;
    }
    return matrix;
}

void fill_adjacency_matrix(int **matrix, char **links, int num_rooms)
{
    int room1 = 0;
    int room2 = 0;

    for (int i = 0; links[i] != NULL; ++i) {
        room1 = extract_room_id(links[i], 0);
        room2 = extract_room_id(links[i], 1);
        if (room1 < num_rooms && room2 < num_rooms) {
            matrix[room1][room2] = 1;
            matrix[room2][room1] = 1;
        }
    }
}

int **adjacent_matrix(char **links, int num_rooms)
{
    int **matrix = create_zero_filled_matrix(num_rooms);

    fill_adjacency_matrix(matrix, links, num_rooms);
    return matrix;
}
