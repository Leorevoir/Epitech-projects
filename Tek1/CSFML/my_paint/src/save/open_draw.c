/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** open_draw
*/

#include "game.h"
#include "my_string.h"
#include "my_stdlib.h"
#include <sys/stat.h>
#include <sys/types.h>

void update_drawing_texture(game_t *game, sfImage *image)
{
    sfVector2u img_size = sfImage_getSize(image);
    const sfUint8 *loaded_pixels = sfImage_getPixelsPtr(image);

    if (game->drawing_zone.texture)
        sfTexture_destroy(game->drawing_zone.texture);
    if (img_size.x != RECT_WIDTH || img_size.y != RECT_HEIGHT) {
        my_error("Image size does not match drawing area.\n");
        return;
    }
    if (!game->pencil.pixels)
        game->pencil.pixels = malloc(RECT_WIDTH * RECT_HEIGHT * 4);
    for (unsigned int i = 0; i < img_size.x * img_size.y * 4; ++i)
        game->pencil.pixels[i] = loaded_pixels[i];
    game->drawing_zone.texture = sfTexture_create(RECT_WIDTH, RECT_HEIGHT);
    sfTexture_updateFromPixels(game->drawing_zone.texture,
        game->pencil.pixels, RECT_WIDTH, RECT_HEIGHT, 0, 0);
    sfSprite_setTexture(game->drawing_zone.sprite,
        game->drawing_zone.texture, sfTrue);
}

sfBool image_exists(const char *filename)
{
    struct stat st;

    if (stat(filename, &st) != -1)
        return sfTrue;
    return sfFalse;
}

sfImage *load_image(const char *filename)
{
    char jpg_filename[90] = {0};
    char png_filename[90] = {0};
    sfImage *image = NULL;

    my_strncpy(jpg_filename, filename, sizeof(jpg_filename));
    my_strcat(jpg_filename, ".jpg");
    my_strncpy(png_filename, filename, sizeof(png_filename));
    my_strcat(png_filename, ".png");
    if (image_exists(filename))
        image = sfImage_createFromFile(filename);
    if (image_exists(jpg_filename))
        image = sfImage_createFromFile(jpg_filename);
    if (image_exists(png_filename))
        image = sfImage_createFromFile(png_filename);
    return image;
}

void open_drawing(game_t *game, const char *filename)
{
    sfImage* loaded_image = load_image(filename);

    if (!loaded_image) {
        my_error("Failed to load image\n");
        return;
    }
    update_drawing_texture(game, loaded_image);
    sfImage_destroy(loaded_image);
}
