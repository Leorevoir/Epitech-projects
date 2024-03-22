/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** create_file
*/

#include "game.h"

void create_new_file(game_t *game)
{
    if (game->drawing_zone.texture)
        sfTexture_destroy(game->drawing_zone.texture);
    game->drawing_zone.texture = sfTexture_create(RECT_WIDTH, RECT_HEIGHT);
    if (!game->pencil.pixels)
        game->pencil.pixels = malloc(RECT_WIDTH * RECT_HEIGHT * 4);
    for (int i = 0; i < RECT_WIDTH * RECT_HEIGHT * 4; i += 4) {
        game->pencil.pixels[i] = 255;
        game->pencil.pixels[i + 1] = 255;
        game->pencil.pixels[i + 2] = 255;
        game->pencil.pixels[i + 3] = 255;
    }
    sfTexture_updateFromPixels(game->drawing_zone.texture,
        game->pencil.pixels, RECT_WIDTH, RECT_HEIGHT, 0, 0);
    sfSprite_setTexture(game->drawing_zone.sprite,
        game->drawing_zone.texture, sfTrue);
}
