/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** color4
*/

#include "game.h"

void lgray(game_t *game)
{
    sfColor custom = sfColor_fromRGB(195, 195, 195);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void lrng(game_t *game)
{
    sfColor custom = sfColor_fromRGB(185, 122, 87);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void pink(game_t *game)
{
    sfColor custom = sfColor_fromRGB(255, 174, 201);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void yllw(game_t *game)
{
    sfColor custom = sfColor_fromRGB(255, 201, 12);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void beig(game_t *game)
{
    sfColor custom = sfColor_fromRGB(239, 228, 176);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}
