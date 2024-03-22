/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** my_sokoban
*/

#include "../include/sokoban.h"

int parse_arguments(int argc, char **argv, map_t *map)
{
    if (argc != 2) {
        write(2, "Usage: ./my_sokoban -h\n", 24);
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        usage();
        return 0;
    }
    if (map == NULL) {
        write(2, "Error: memory allocation failed", 32);
        return 84;
    }
    if (init_map(map, argv[1]) == 84) {
        destroy_game(map);
        return 84;
    }
    destroy_game(map);
    return 0;
}
