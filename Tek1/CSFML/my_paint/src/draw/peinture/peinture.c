/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** peinture
*/

#include "peinture.h"
#include "my_stdlib.h"

static int is_empty(bucket_t *bucket)
{
    return bucket->front == bucket->rear;
}

static int is_valid_position(int x, int y, int width, int height)
{
    return x >= 0
        && x < width
        && y >= 0
        && y < height;
}

static int is_target_color(sfColor pixel_color, sfColor target_color)
{
    return pixel_color.r == target_color.r
        && pixel_color.g == target_color.g
        && pixel_color.b == target_color.b
        && pixel_color.a == target_color.a;
}

static fill_t init_fill(int x, int y, sfColor target_color, sfColor fill_color)
{
    fill_t fill;

    fill.x = x;
    fill.y = y;
    fill.target_color = target_color;
    fill.fill_color = fill_color;
    return fill;
}

void process_pixel(sfImage *image, bucket_t *bucket, fill_t fill)
{
    sfColor pixel_color = sfImage_getPixel(image, fill.x, fill.y);

    if (is_target_color(pixel_color, fill.target_color)) {
        sfImage_setPixel(image, fill.x, fill.y, fill.fill_color);
        enqueue_bucket(bucket, fill.x + 1, fill.y);
        enqueue_bucket(bucket, fill.x - 1, fill.y);
        enqueue_bucket(bucket, fill.x, fill.y + 1);
        enqueue_bucket(bucket, fill.x, fill.y - 1);
    }
}

void flood_fill(game_t *game, fill_t fill)
{
    int width = sfTexture_getSize(game->drawing_zone.texture).x;
    int height = sfTexture_getSize(game->drawing_zone.texture).y;
    bucket_t *bucket = create_bucket(width * height);
    sfImage *image = sfTexture_copyToImage(game->drawing_zone.texture);
    const sfUint8 *magic_update;

    enqueue_bucket(bucket, fill.x, fill.y);
    while (!is_empty(bucket)) {
        dequeue_bucket(bucket, &fill.x, &fill.y);
        if (!is_valid_position(fill.x, fill.y, width, height))
            continue;
        process_pixel(image, bucket, fill);
    }
    sfTexture_updateFromImage(game->drawing_zone.texture, image, 0, 0);
    magic_update = sfImage_getPixelsPtr(image);
    my_memcpy(game->pencil.pixels, magic_update, width * height * 4);
    sfImage_destroy(image);
    free_bucket(bucket);
}

void peinture(game_t *game)
{
    sfVector2i pixel_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(game->window,
        pixel_pos, NULL);
    sfVector2f drawing_pos = get_drawing_position(world_pos,
        sfRectangleShape_getPosition(game->drawing_rect));
    sfColor target_color;
    fill_t fill;

    if (is_position_inside_drawing_area(drawing_pos)) {
        target_color = sfImage_getPixel(sfTexture_copyToImage(
            game->drawing_zone.texture), drawing_pos.x, drawing_pos.y);
        fill = init_fill(drawing_pos.x, drawing_pos.y,
            target_color, game->pencil.current);
        flood_fill(game, fill);
    }
}
