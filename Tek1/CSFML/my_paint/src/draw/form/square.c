/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** square
*/

#include "square.h"

static void start_drawing(game_t *game, sfEvent event, sfVector2f *start_point,
    square_t **current)
{
    *start_point = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i){event.mouseButton.x, event.mouseButton.y}, NULL);
    if (!*current) {
        *current = (square_t *) malloc(sizeof(square_t));
    }
    if (*current) {
        (*current)->start_point = *start_point;
        (*current)->end_point = *start_point;
    }
}

static void update_drawing(game_t *game, square_t *current, sfEvent event)
{
    current->end_point = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i){event.mouseMove.x, event.mouseMove.y}, NULL);
}

static void stop_drawing(game_t *game, bool *is_drawing, square_t **current)
{
    if (*is_drawing && *current) {
        finalize_drawing(game, *current);
        free(*current);
        *current = NULL;
        *is_drawing = false;
    }
}

void handle_square_events(game_t *game, sfEvent event)
{
    static bool is_drawing = false;
    static sfVector2f start_point;
    static square_t *current = NULL;

    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft
        && game->selected_tool == SQUARE && !is_drawing) {
        start_drawing(game, event, &start_point, &current);
        is_drawing = true;
    }
    if (event.type == sfEvtMouseMoved && is_drawing && current) {
        update_drawing(game, current, event);
    }
    if (event.type == sfEvtMouseButtonReleased && is_drawing && current) {
        stop_drawing(game, &is_drawing, &current);
    }
}

void square(game_t *game)
{
    game->selected_tool = SQUARE;
}
