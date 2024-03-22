/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** radar_start
*/

#include "../../include/radar.h"

void my_radar(radar_t *radar, int argc, char **argv)
{
    radar->value = 0;
    radar->planes_exploded = 0;
    radar->planes_landed = 0;
    radar->planes = NULL;
    radar->towers = NULL;
    radar->plane_sprite = NULL;
    radar->plane_texture = NULL;
    radar->world_sprite = NULL;
    radar->world_texture = NULL;
    radar->tower_sprite = NULL;
    radar->tower_texture = NULL;
    radar->tower_radius = NULL;
    radar->window = NULL;
    radar->show_sprites = 1;
    radar->plane_hitbox = NULL;
    radar->show_hitboxes = 0;
    radar_create_text(radar);
    radar_create_stats_text(radar);
    radar_parse_arguments(radar, argc, argv);
}

void radar_loop(radar_t *radar)
{
    sfClock *clock = sfClock_create();
    sfEvent event;

    while (sfRenderWindow_isOpen(radar->window)) {
        while (sfRenderWindow_pollEvent(radar->window, &event))
            radar_event(radar, &event);
        radar_update(radar, sfTime_asSeconds(sfClock_restart(clock)));
        sfRenderWindow_clear(radar->window, sfBlack);
        radar_draw(radar);
        sfRenderWindow_display(radar->window);
    }
    sfClock_destroy(clock);
}

void radar_run(radar_t *radar)
{
    if (radar->value == STATUS_ERROR || radar->value == STATUS_HELP)
        return;
    radar_loop(radar);
}
