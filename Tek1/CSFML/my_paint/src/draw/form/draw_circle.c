/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** draw_circle
*/

#include "circle.h"

static void draw_circle_with_color(game_t *game, circle_t *circle, index_t id)
{
    draw_pixel_in_buffer(game, circle->center.x + id.x + id.i,
        circle->center.y - id.y + id.j);
    draw_pixel_in_buffer(game, circle->center.x + id.x + id.i,
        circle->center.y + id.y + id.j);
    draw_pixel_in_buffer(game, circle->center.x - id.x + id.i,
        circle->center.y - id.y + id.j);
    draw_pixel_in_buffer(game, circle->center.x - id.x + id.i,
        circle->center.y + id.y + id.j);
    draw_pixel_in_buffer(game, circle->center.x + id.y + id.i,
        circle->center.y - id.x + id.j);
    draw_pixel_in_buffer(game, circle->center.x + id.y + id.i,
        circle->center.y + id.x + id.j);
    draw_pixel_in_buffer(game, circle->center.x - id.y + id.i,
        circle->center.y - id.x + id.j);
    draw_pixel_in_buffer(game, circle->center.x - id.y + id.i,
        circle->center.y + id.x + id.j);
}

static void draw_circle_pixel(game_t *game, circle_t *circle, int x, int y)
{
    index_t id = {0};
    int size = game->pencil.size;

    id.x = x;
    id.y = y;
    for (id.i = -size / 2; id.i <= size / 2; id.i++) {
        for (id.j = -size / 2; id.j <= size / 2; id.j++)
        draw_circle_with_color(game, circle, id);
    }
}

static void calculate_circle_points(game_t *game, circle_t *circle)
{
    const int diameter = circle->radius * 2;
    int x = circle->radius - 1;
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = tx - diameter;

    while (x >= y) {
        draw_circle_pixel(game, circle, x, y);
        if (error <= 0) {
            y++;
            error += ty;
            ty += 2;
        }
        if (error > 0) {
            x--;
            tx += 2;
            error += tx - diameter;
        }
    }
}

void draw_circle_in_buffer(game_t *game, circle_t *circle)
{
    calculate_circle_points(game, circle);
    sfTexture_updateFromPixels(game->drawing_zone.texture,
        game->pencil.pixels, RECT_WIDTH, RECT_HEIGHT, 0, 0);
}
