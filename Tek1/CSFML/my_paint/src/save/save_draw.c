/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** save_draw
*/

#include "game.h"
#include "my_string.h"

bool ends_with(const char *str, const char *suffix)
{
    size_t str_len = my_strlen(str);
    size_t suffix_len = my_strlen(suffix);

    if (suffix_len > str_len)
        return false;
    return my_strncmp(str + str_len - suffix_len,
        suffix, suffix_len) == 0;
}

void ensure_default_extension(char *filename)
{
    const char *jpg_extension = ".jpg";
    size_t filename_len = my_strlen(filename);
    size_t jpg_extension_len = my_strlen(jpg_extension);

    if (!ends_with(filename, ".png") && !ends_with(filename, ".jpg")
        && (filename_len + jpg_extension_len < 86)) {
        my_strcat(filename, jpg_extension);
    }
}

void save_drawing(const game_t *game, const char *filename)
{
    char full_filename[90];
    sfTexture *texture;
    sfImage *image;

    my_strcpy(full_filename, filename);
    ensure_default_extension(full_filename);
    texture = game->drawing_zone.texture;
    image = sfTexture_copyToImage(texture);
    if (image) {
        sfImage_saveToFile(image, full_filename);
        sfImage_destroy(image);
    }
}
