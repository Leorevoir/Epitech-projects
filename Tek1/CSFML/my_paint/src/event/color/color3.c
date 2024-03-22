/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** color3
*/

#include "game.h"

void gray(game_t *game)
{
    sfColor custom = sfColor_fromRGB(127, 127, 127);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void orange(game_t *game)
{
    sfColor custom = sfColor_fromRGB(255, 127, 40);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void magnta(game_t *game)
{
    sfColor custom = sfColor_fromRGB(163, 73, 164);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void white(game_t *game)
{
    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, sfWhite);
    }
}
