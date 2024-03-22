/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** parse_lines
*/

#include "../../include/radar.h"

int parse_line(radar_t *radar, char **words, unsigned long count)
{
    if (count == 0) {
        return 84;
    }
    if (my_strcmp(words[0], "A") == 0)
        return parse_plane(radar, words, count);
    if (my_strcmp(words[0], "T") == 0)
        return parse_tower(radar, words, count);
    return 84;
}
