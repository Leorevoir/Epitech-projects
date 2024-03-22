/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** init_pencil
*/

#include "init.h"
#include "game.h"

void create_pencil(game_t *game)
{
    sfUint8 *pixels = malloc(RECT_WIDTH * RECT_HEIGHT * 4 * sizeof(sfUint8));

    game->pencil.pixels = pixels;
    game->pencil.color = sfBlack;
    game->pencil.current = sfBlack;
    game->pencil.secondary_color = sfWhite;
    game->pencil.size = 5;
    game->pencil.is_second = false;
}
