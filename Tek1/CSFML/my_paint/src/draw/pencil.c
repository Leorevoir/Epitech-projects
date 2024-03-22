/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** pencil
*/

#include "algo.h"

coordinates_t init_coords(int x0, int y0, int x1, int y1)
{
    coordinates_t coords;

    coords.x0 = x0;
    coords.y0 = y0;
    coords.x1 = x1;
    coords.y1 = y1;
    return coords;
}

static float calculate_distance(point_t start, point_t end)
{
    int dx = end.x - start.x;
    int dy = end.y - start.y;

    return sqrtf(dx * dx + dy * dy);
}

static point_t interpolate_point(point_t start, point_t end, double ratio)
{
    point_t result;

    result.x = start.x + (end.x - start.x) * ratio;
    result.y = start.y + (end.y - start.y) * ratio;
    return result;
}

static void draw_line_with_interpolation(game_t *game, point_t start,
    point_t end)
{
    point_t interpolated_point;
    coordinates_t coords;
    int steps = fmax(calculate_distance(start, end), 1);
    double ratio;

    for (int i = 0; i <= steps; i++) {
        ratio = (double)i / steps;
        interpolated_point = interpolate_point(start, end, ratio);
        coords = init_coords(interpolated_point.x, interpolated_point.y,
            interpolated_point.x, interpolated_point.y);
        interpolate_and_apply_color(game, coords);
    }
}

void update_coords(game_t *game, int x, int y)
{
    point_t new_point = {x, y};
    point_t last_point;

    if (game->last_coords.last_x < 0 || game->last_coords.last_y < 0) {
        game->last_coords.last_x = x;
        game->last_coords.last_y = y;
    } else {
        last_point.x = game->last_coords.last_x;
        last_point.y = game->last_coords.last_y;
        draw_line_with_interpolation(game, last_point, new_point);
        game->last_coords.last_x = x;
        game->last_coords.last_y = y;
    }
    sfTexture_updateFromPixels(game->drawing_zone.texture,
        game->pencil.pixels, RECT_WIDTH, RECT_HEIGHT, 0, 0);
}

void pencil_draw(game_t *game)
{
    sfVector2i pixel_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f adjusted_pos = get_adjusted_position(game->window, pixel_pos);
    sfVector2f zone_pos = sfRectangleShape_getPosition(game->drawing_rect);
    sfVector2f draw_pos = get_drawing_position(adjusted_pos, zone_pos);

    if (is_position_inside_drawing_area(draw_pos)) {
        if (game->mouse_pressed && !game->size_png.is_visible) {
            update_coords(game, (int)draw_pos.x, (int)draw_pos.y);
        } else {
            game->last_coords.last_x = -1;
            game->last_coords.last_y = -1;
        }
    }
}
