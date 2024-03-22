/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** color
*/

#include "event.h"

void select_color_from_palette(game_t *game, sfVector2i pos)
{
    sfImage *png = sfTexture_copyToImage(game->
        color_png.menu_sprite.texture);
    sfColor pixel_color = sfImage_getPixel(png, pos.x, pos.y);

    if (pixel_color.a != 0) {
        set_primary_or_secondary_color(game, pixel_color);
    }
    sfImage_destroy(png);
}

void handle_color_selection(game_t *game, sfMouseButtonEvent event)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        game->color_png.menu_sprite.sprite);
    sfVector2i relative_pos;

    if (event.x >= bounds.left
        && event.x <= bounds.left + bounds.width
        && event.y >= bounds.top
        && event.y <= bounds.top + bounds.height
        && game->color_png.is_visible) {
        relative_pos = (sfVector2i){
            event.x - (int)bounds.left,
            event.y - (int)bounds.top
        };
        select_color_from_palette(game, relative_pos);
    }
}

void handle_pipette(game_t *game, sfVector2f click)
{
    sfFloatRect bounds;
    sfImage *image;
    sfColor picked_color;

    if (game->selected_tool != PIPETTE)
        return;
    bounds = sfRectangleShape_getGlobalBounds(game->drawing_rect);
    if (sfFloatRect_contains(&bounds, click.x, click.y)) {
        image = sfTexture_copyToImage(game->drawing_zone.texture);
        picked_color = sfImage_getPixel(image,
            click.x - bounds.left, click.y - bounds.top);
        sfImage_destroy(image);
        set_primary_or_secondary_color(game, picked_color);
        button_inactive(game, "pipette");
        pencil(game);
    }
}

void handle_color(game_t *game, sfVector2f click)
{
    handle_pipette(game, click);
}
