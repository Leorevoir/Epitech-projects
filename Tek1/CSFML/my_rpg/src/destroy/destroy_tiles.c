/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_tiles
*/

#include "my_rpg.h"

void destroy_tiles(tile_t *head)
{
    for (tile_t *current = head; current != NULL; current = current->next) {
        if (current->sprite)
            sfSprite_destroy(current->sprite);
        if (current->texture != NULL)
            sfTexture_destroy(current->texture);
    }
}
