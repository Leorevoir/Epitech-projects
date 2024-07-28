/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** tiles
*/

#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Network.h>
#include <SFML/Graphics.h>

#ifndef TILES_H_
    #define TILES_H_
    #define TILES "assets/tiles.conf"

typedef struct tmp_s {
    char name[50];
    char path[100];
    int posx;
    int posy;
    int map;
    int traversable;
    int display_mode;
} tmp_t;

typedef struct tile_s {
    char name[50];
    char path[100];
    int posx;
    int posy;
    sfTexture *texture;
    sfSprite *sprite;
    int display_mode;
    bool traversable;
    int map;
    sfVector2u size;
    struct tile_s *next;
} tile_t;

void free_tiles(tile_t **head);
void add_tile(tile_t **head, tile_t *new_tile);
int load_tile(tile_t **head, const char *filename);
tile_t *create_tile(tmp_t *tmp);

#endif /* !TILES_H_ */
