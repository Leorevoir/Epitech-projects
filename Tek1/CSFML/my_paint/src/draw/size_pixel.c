/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** size_pixel
*/

#include "deroulant.h"

void sizepx(game_t *game)
{
    toggle_menu(&game->size_png);
}

void px1(game_t *game)
{
    game->size_png.is_visible = false;
    game->pencil.size = 1;
}

void px3(game_t *game)
{
    game->size_png.is_visible = false;
    game->pencil.size = 3;
}

void px5(game_t *game)
{
    game->size_png.is_visible = false;
    game->pencil.size = 5;
}

void px8(game_t *game)
{
    game->size_png.is_visible = false;
    game->pencil.size = 8;
}
