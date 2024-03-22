/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** form_event
*/

#include "event.h"
#include "my_string.h"

void my_put(const char *str)
{
    write(1, str, my_strlen(str));
}

void circle(game_t *game)
{
    game->selected_tool = CIRCLE;
}

void trait(game_t *game)
{
    game->selected_tool = TRAIT;
}

void handle_form_event(game_t *game, sfEvent event)
{
    if (game->selected_tool == SQUARE)
        handle_square_events(game, event);
    if (game->selected_tool == CIRCLE)
        handle_circle_events(game, event);
    if (game->selected_tool == TRAIT)
        handle_trait_events(game, event);
    if (game->selected_tool == ABOUT)
        handle_about_events(game, event);
    if (game->selected_tool == HELP)
        handle_help_events(game, event);
}
