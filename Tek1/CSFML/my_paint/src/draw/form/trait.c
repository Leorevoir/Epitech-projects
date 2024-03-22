/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** trait
*/

#include "trait.h"

static void draw_pixel_trait_in_buffer(game_t *game, line_t l, sfColor color)
{
    int index = 0;

    if (l.x + l.dx >= 0 && l.x + l.dx < RECT_WIDTH
        && l.y + l.dy >= 0
        && l.y + l.dy < RECT_HEIGHT) {
        index = ((l.x + l.dx) + (l.y + l.dy) * RECT_WIDTH) * 4;
        game->pencil.pixels[index] = color.r;
        game->pencil.pixels[index + 1] = color.g;
        game->pencil.pixels[index + 2] = color.b;
        game->pencil.pixels[index + 3] = 255;
    }
}

static void draw_with_pencil_size_and_color(game_t *game, line_t l,
    sfColor color)
{
    int size = game->pencil.size;

    for (l.dy = -size / 2; l.dy <= size / 2; l.dy++) {
        for (l.dx = -size / 2; l.dx <= size / 2; l.dx++)
            draw_pixel_trait_in_buffer(game, l, color);
    }
}

static void adjust_point_to_drawing_rect(game_t *game, sfVector2f *point)
{
    sfVector2f drawing_rect_position = sfRectangleShape_getPosition(
        game->drawing_rect);

    point->x -= drawing_rect_position.x;
    point->y -= drawing_rect_position.y;
}

static void start_drawing_trait(game_t *game, sfVector2f mouse_pos,
    trait_t **current_trait, bool *is_drawing)
{
    adjust_point_to_drawing_rect(game, &mouse_pos);
    *current_trait = malloc(sizeof(trait_t));
    if (*current_trait) {
        (*current_trait)->point_a = mouse_pos;
        (*current_trait)->point_b = mouse_pos;
        (*current_trait)->color = game->pencil.current;
        (*current_trait)->next = NULL;
        *is_drawing = true;
    }
}

static void update_drawing_trait(game_t *game, sfVector2f mouse_pos,
    trait_t *current_trait)
{
    adjust_point_to_drawing_rect(game, &mouse_pos);
    current_trait->point_b = mouse_pos;
}

void draw_trait_in_buffer(game_t *game, sfVector2f start, sfVector2f end,
    sfColor color)
{
    line_t l = {0};
    float delta_x = end.x - start.x;
    float delta_y = end.y - start.y;
    float steps = fmax(fabs(delta_x), fabs(delta_y));

    for (float i = 0; i <= steps; i++) {
        l.x = round(start.x + (delta_x * i / steps));
        l.y = round(start.y + (delta_y * i / steps));
        draw_with_pencil_size_and_color(game, l, color);
    }
}

static void finalize_drawing_trait(game_t *game, trait_t *current_trait,
    bool *is_drawing)
{
    draw_trait_in_buffer(game, current_trait->point_a, current_trait->point_b,
        current_trait->color);
    sfTexture_updateFromPixels(game->drawing_zone.texture,
        game->pencil.pixels, RECT_WIDTH, RECT_HEIGHT, 0, 0);
    current_trait->next = game->trait;
    game->trait = current_trait;
    *is_drawing = false;
}

void handle_trait_events(game_t *game, sfEvent event)
{
    static bool is_drawing = false;
    static trait_t *current_trait = NULL;
    sfVector2f mouse_pos;

    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft &&
        game->selected_tool == TRAIT && !is_drawing) {
        mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
            (sfVector2i){event.mouseButton.x, event.mouseButton.y}, NULL);
        start_drawing_trait(game, mouse_pos, &current_trait, &is_drawing);
    }
    if (event.type == sfEvtMouseMoved && is_drawing && current_trait) {
        mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
            (sfVector2i){event.mouseMove.x, event.mouseMove.y}, NULL);
        update_drawing_trait(game, mouse_pos, current_trait);
    }
    if (event.type == sfEvtMouseButtonReleased && is_drawing && current_trait)
        finalize_drawing_trait(game, current_trait, &is_drawing);
}
