/*
** EPITECH PROJECT, 2024
** RPG_TEST
** File description:
** free_tiles
*/

#include "tiles.h"
#include <stdlib.h>

void free_tiles(tile_t **head)
{
    tile_t *current;
    tile_t *next;

    for (current = *head; current != NULL; current = next) {
        next = current->next;
        free(current);
    }
    *head = NULL;
}
