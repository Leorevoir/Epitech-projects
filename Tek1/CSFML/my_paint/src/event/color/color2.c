/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** color2
*/

#include "game.h"

void red(game_t *game)
{
    sfColor custom = sfColor_fromRGB(236, 29, 37);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void black(game_t *game)
{
    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, sfBlack);
    }
}

void green(game_t *game)
{
    sfColor custom = sfColor_fromRGB(31, 177, 76);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void yellow(game_t *game)
{
    sfColor custom = sfColor_fromRGB(255, 242, 0);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void d_red(game_t *game)
{
    sfColor custom = sfColor_fromRGB(136, 0, 21);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}
