/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** color5
*/

#include "game.h"

void lgrn(game_t *game)
{
    sfColor custom = sfColor_fromRGB(181, 229, 30);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void llbl(game_t *game)
{
    sfColor custom = sfColor_fromRGB(154, 216, 234);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void bgbl(game_t *game)
{
    sfColor custom = sfColor_fromRGB(112, 146, 190);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void bgpl(game_t *game)
{
    sfColor custom = sfColor_fromRGB(200, 191, 231);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}

void lblue(game_t *game)
{
    sfColor custom = sfColor_fromRGB(2, 161, 232);

    if (game->selected_tool == PENCIL || game->selected_tool == PEINTURE
        || game->selected_tool == SQUARE || game->selected_tool == CIRCLE
        || game->selected_tool == TRAIT) {
        set_primary_or_secondary_color(game, custom);
    }
}
