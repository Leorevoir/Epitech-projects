/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** color6
*/

#include "game.h"

void main_color(game_t *game)
{
    game->pencil.is_second = false;
    game->pencil.current = game->pencil.color;
}

void secnd(game_t *game)
{
    game->pencil.is_second = true;
    game->pencil.current = game->pencil.secondary_color;
}

void set_primary_or_secondary_color(game_t *game, sfColor color)
{
    if (game->pencil.is_second)
        game->pencil.secondary_color = color;
    else
        game->pencil.color = color;
    game->pencil.current = color;
}

void color_png(game_t *game)
{
    if (!game->color_png.is_visible)
        game->color_png.is_visible = true;
    else
        game->color_png.is_visible = false;
}

void dblue(game_t *game)
{
    sfColor custom = sfColor_fromRGB(63, 72, 204);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}
