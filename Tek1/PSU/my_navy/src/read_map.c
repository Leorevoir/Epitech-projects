/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** create_map
*/

#include "../include/my_navy.h"

int extract_ship_length(const char *line, int *i)
{
    int length = 0;

    while (line[*i] != ':') {
        if (line[*i] < '2' || line[*i] > '5')
            return 84;
        length = (length * 10) + (line[*i] - '0');
        *i += 1;
    }
    *i += 1;
    return length;
}

int extract_coordinates(const char *line, char *coord, int *i)
{
    int j = 0;

    while (line[*i] != ':' && line[*i] != '\n' && line[*i] != '\0') {
        if ((line[*i] < 'A' || line[*i] > 'H')
        && (line[*i] < '1' || line[*i] > '8'))
            return 84;
        coord[j] = line[*i];
        *i += 1;
        j += 1;
    }
    coord[j] = '\0';
    *i += 1;
    return 0;
}

int parse_ship_data(const char *line, int *ship_length, char *start, char *end)
{
    int i = 0;

    *ship_length = extract_ship_length(line, &i);
    if (*ship_length == 84)
        return 84;
    if (extract_coordinates(line, start, &i) == 84)
        return 84;
    if (extract_coordinates(line, end, &i) == 84)
        return 84;
    return 0;
}

int make_map(FILE *file, char *line, map_t *map)
{
    int ship_length;
    size_t len = 0;
    ssize_t read;
    char start[3] = {0}, end[3] = {0};

    read = getline(&line, &len, file);
    while (read != -1) {
        ship_length = 0;
        if (parse_ship_data(line, &ship_length, start, end) == 0)
            fill_grid(map, start, end, ship_length);
        else {
            free_all(file, line);
            return 84;
        }
        read = getline(&line, &len, file);
    }
    free_all(file, line);
    return 0;
}

int read_map(const char *filename, map_t *map)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;

    if (!file)
        return 84;
    if (make_map(file, line, map) == 84)
        return 84;
    return 0;
}
