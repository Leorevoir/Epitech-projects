/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_tiles
*/

#include "my_rpg.h"

void parse_tile_from_conf(tile_t **head, char *line)
{
    tile_t *new_tile;
    tmp_t tmp;

    if (sscanf(line, "%s %s %d %d %d %d %d", tmp.name, tmp.path,
        &tmp.posx, &tmp.posy, &tmp.traversable,
        &tmp.display_mode, &tmp.map) == 7) {
        new_tile = create_tile(&tmp);
        if (new_tile)
            add_tile(head, new_tile);
    }
}

void load_my_tile(tile_t **head, const char *filename)
{
    FILE *file = fopen(filename, "r");
    char line[256];

    if (file == NULL)
        return;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '#')
            continue;
        parse_tile_from_conf(head, line);
    }
    fclose(file);
}

int load_tile(tile_t **head, const char *filename)
{
    struct stat st;

    if (stat(filename, &st) != 0) {
        fprintf(stderr, "ERROR: cannot find %s\n", TILES);
        return 84;
    }
    chmod(filename, 777);
    load_my_tile(head, filename);
    chmod(filename, 000);
    return SUCCESS;
}
