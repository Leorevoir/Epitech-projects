/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** init_character
*/

#include "../include/sokoban.h"

static bool is_valid_character(char c)
{
    char valid_characters[] = " \n#POX";

    for (int i = 0; valid_characters[i] != '\0'; i++) {
        if (c == valid_characters[i])
            return true;
    }
    return false;
}

void init_character(map_t *map)
{
    for (int i = 0; map->buffer[i]; i++) {
        if (!is_valid_character(map->buffer[i]))
            exit(84);
    }
}
