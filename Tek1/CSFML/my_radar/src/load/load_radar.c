/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** load
*/

#include "../../include/radar.h"

sfTexture *load_texture(radar_t *radar, char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    if (!texture)
        radar->value = 84;
    return texture;
}

void radar_load_resources(radar_t *radar)
{
    radar->world_texture = load_texture(radar, "data/world.png");
    radar->plane_texture = load_texture(radar, "data/plane.png");
    radar->tower_texture = load_texture(radar, "data/tower.png");
}

void center_window(sfRenderWindow *window, int width, int height)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2i position;

    position.x = (width - window_size.x) / 2;
    position.y = (height - window_size.y) / 2;
    sfRenderWindow_setPosition(window, position);
}

void radar_initialize(radar_t *radar)
{
    int width = 1920;
    int height = 1080;

    radar->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "MY RADAR", sfClose, NULL);
    center_window(radar->window, width, height);
    radar_load_resources(radar);
    radar_create(radar);
}
