/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_tiles
*/

#include "my_rpg.h"

sfVector2u get_tile_size(tile_t *tile)
{
    sfTexture* texture = sfTexture_createFromFile(tile->path, NULL);
    sfVector2u size = sfTexture_getSize(texture);

    sfTexture_destroy(texture);
    return size;
}

tile_t *create_tile(tmp_t *tmp)
{
    tile_t *new_tile = malloc(sizeof(tile_t));

    if (!new_tile)
        return NULL;
    strcpy(new_tile->name, tmp->name);
    strcpy(new_tile->path, tmp->path);
    new_tile->map = tmp->map;
    new_tile->posx = tmp->posx;
    new_tile->posy = tmp->posy;
    new_tile->traversable = tmp->traversable;
    new_tile->texture = sfTexture_createFromFile(new_tile->path, NULL);
    new_tile->sprite = sfSprite_create();
    sfSprite_setTexture(new_tile->sprite, new_tile->texture, sfTrue);
    new_tile->next = NULL;
    new_tile->display_mode = tmp->display_mode;
    new_tile->size = get_tile_size(new_tile);
    return new_tile;
}

void add_tile(tile_t **head, tile_t *new_tile)
{
    if (!head || !new_tile)
        return;
    new_tile->next = *head;
    *head = new_tile;
}
