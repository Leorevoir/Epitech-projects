/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** circle
*/

#include "circle.h"

static void start_drawing_circle(game_t *game, sfEvent event,
    circle_t **current)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i){event.mouseButton.x, event.mouseButton.y}, NULL);
    sfVector2f drawing_rect = sfRectangleShape_getPosition(game->drawing_rect);
    sfVector2f center;

    center.x = mouse_pos.x - drawing_rect.x;
    center.y = mouse_pos.y - drawing_rect.y;
    if (!*current)
        *current = (circle_t *)malloc(sizeof(circle_t));
    if (*current) {
        (*current)->center = center;
        (*current)->radius = 0;
    }
}

static void update_drawing_circle(game_t *game, circle_t *current,
    sfEvent event)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i){
            event.mouseMove.x, event.mouseMove.y}, NULL);
    sfVector2f drawing_rect = sfRectangleShape_getPosition(
        game->drawing_rect);

    current->radius = sqrt(pow(mouse_pos.x - (
        current->center.x + drawing_rect.x), 2) +
            pow(mouse_pos.y - (current->center.y + drawing_rect.y), 2));
}

static void stop_drawing_circle(game_t *game, bool *is_drawing,
    circle_t **current)
{
    if (*is_drawing && *current) {
        draw_circle_in_buffer(game, *current);
        free(*current);
        *current = NULL;
        *is_drawing = false;
    }
}

void handle_circle_events(game_t *game, sfEvent event)
{
    static bool is_drawing = false;
    static circle_t *current_circle = NULL;

    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft &&
        game->selected_tool == CIRCLE && !is_drawing) {
        start_drawing_circle(game, event, &current_circle);
        is_drawing = true;
    }
    if (event.type == sfEvtMouseMoved
        && is_drawing && current_circle)
        update_drawing_circle(game, current_circle, event);
    if (event.type == sfEvtMouseButtonReleased
        && is_drawing && current_circle)
        stop_drawing_circle(game, &is_drawing, &current_circle);
}
