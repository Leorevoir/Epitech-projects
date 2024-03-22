/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** update_mouse
*/

#include "algo.h"

sfVector2f get_adjusted_position(const sfRenderWindow *window,
    sfVector2i pixel_pos)
{
    const sfView* view = sfRenderWindow_getView(window);
    sfVector2f view_size = sfView_getSize(view);
    sfVector2f view_center = sfView_getCenter(view);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    float scaleX = view_size.x / window_size.x;
    float scaleY = view_size.y / window_size.y;

    return (sfVector2f){
        view_center.x - view_size.x / 2 + pixel_pos.x * scaleX,
        view_center.y - view_size.y / 2 + pixel_pos.y * scaleY
    };
}

sfVector2f get_drawing_position(sfVector2f adjusted_pos,
    sfVector2f zone_pos)
{
    return (sfVector2f){
        adjusted_pos.x - zone_pos.x,
        adjusted_pos.y - zone_pos.y
    };
}

bool is_position_inside_drawing_area(sfVector2f pos)
{
    return pos.x >= 0
        && pos.y >= 0
        && pos.x < RECT_WIDTH
        && pos.y < RECT_HEIGHT;
}

void update_mouse_position(game_t *game)
{
    sfVector2i pixel_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f adjusted_pos = get_adjusted_position(game->window, pixel_pos);
    sfVector2f zone_pos = sfRectangleShape_getPosition(game->drawing_rect);
    sfVector2f draw_pos = get_drawing_position(adjusted_pos, zone_pos);

    if (!is_position_inside_drawing_area(draw_pos)) {
        if (game->mouse_pressed) {
            game->last_coords.last_x = -1;
            game->last_coords.last_y = -1;
        }
    }
}
