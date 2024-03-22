/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** draw_in_buffer
*/

#include "square.h"

void draw_pixel_in_buffer(game_t *game, int x, int y)
{
    int index = (x + y * RECT_WIDTH) * 4;

    if (x >= 0 && x < RECT_WIDTH && y >= 0 && y < RECT_HEIGHT) {
        game->pencil.pixels[index] = game->pencil.current.r;
        game->pencil.pixels[index + 1] = game->pencil.current.g;
        game->pencil.pixels[index + 2] = game->pencil.current.b;
        game->pencil.pixels[index + 3] = 255;
    }
}

static void draw_with_pencil_size(game_t *game, int x, int y)
{
    for (int dx = -game->pencil.size / 2; dx <= game->pencil.size / 2; dx++)
        for (int dy = -game->pencil.size / 2;
            dy <= game->pencil.size / 2; dy++)
            draw_pixel_in_buffer(game, x + dx, y + dy);
}

void draw_line_in_buffer(game_t *game, sfVector2f start, sfVector2f end)
{
    float delta_x = end.x - start.x;
    float delta_y = end.y - start.y;
    float steps = fmax(fabs(delta_x), fabs(delta_y));
    int x = 0;
    int y = 0;

    for (float i = 0; i <= steps; i++) {
        x = round(start.x + (delta_x * i / steps));
        y = round(start.y + (delta_y * i / steps));
        draw_with_pencil_size(game, x, y);
    }
}

void draw_square_in_buffer(game_t *game, sfVector2f start, sfVector2f end)
{
    draw_line_in_buffer(game, start, (
        sfVector2f){start.x, end.y});
    draw_line_in_buffer(game, start, (
        sfVector2f){end.x, start.y});
    draw_line_in_buffer(game, (
        sfVector2f){end.x, start.y}, end);
    draw_line_in_buffer(game, (
        sfVector2f){start.x, end.y}, end);
    sfTexture_updateFromPixels(game->drawing_zone.texture,
        game->pencil.pixels, RECT_WIDTH, RECT_HEIGHT, 0, 0);
}

void finalize_drawing(game_t *game, square_t *current)
{
    sfVector2f start = {
        fmin(current->start_point.x, current->end_point.x)
            - sfRectangleShape_getPosition(game->drawing_rect).x,
        fmin(current->start_point.y, current->end_point.y)
            - sfRectangleShape_getPosition(game->drawing_rect).y
    };
    sfVector2f end = {
        start.x + fabs(
            current->end_point.x - current->start_point.x),
        start.y + fabs(
            current->end_point.y - current->start_point.y)
    };

    draw_square_in_buffer(game, start, end);
}
