/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** create_text
*/

#include "../../include/radar.h"

void radar_create_text(radar_t *radar)
{
    radar->timer = 0;
    radar->timer_value = sfText_create();
    radar->timer_text = sfText_create();
    radar->timer_font = sfFont_createFromFile("data/font.ttf");
    sfText_setFont(radar->timer_value, radar->timer_font);
    sfText_setCharacterSize(radar->timer_value, 50);
    sfText_setPosition(radar->timer_value, (sfVector2f){1800, 50});
    sfText_setFont(radar->timer_text, radar->timer_font);
    sfText_setCharacterSize(radar->timer_text, 50);
    sfText_setPosition(radar->timer_text, (sfVector2f){1650, 50});
    sfText_setColor(radar->timer_value, sfWhite);
    sfText_setColor(radar->timer_text, sfWhite);
}

void radar_landed_text(radar_t *radar)
{
    radar->stats_landed = sfText_create();
    sfText_setFont(radar->stats_landed, radar->timer_font);
    sfText_setCharacterSize(radar->stats_landed, 50);
    sfText_setColor(radar->stats_landed, sfWhite);
    sfText_setPosition(radar->stats_landed, (sfVector2f){250, 50});
    radar->landed_text = sfText_create();
    sfText_setFont(radar->landed_text, radar->timer_font);
    sfText_setCharacterSize(radar->landed_text, 50);
    sfText_setColor(radar->landed_text, sfWhite);
    sfText_setPosition(radar->landed_text, (sfVector2f){10, 50});
}

void radar_exploded_text(radar_t *radar)
{
    radar->stats_exploded = sfText_create();
    sfText_setFont(radar->stats_exploded, radar->timer_font);
    sfText_setCharacterSize(radar->stats_exploded, 50);
    sfText_setColor(radar->stats_exploded, sfWhite);
    sfText_setPosition(radar->stats_exploded, (sfVector2f){250, 120});
    radar->exploded_text = sfText_create();
    sfText_setFont(radar->exploded_text, radar->timer_font);
    sfText_setCharacterSize(radar->exploded_text, 50);
    sfText_setColor(radar->exploded_text, sfWhite);
    sfText_setPosition(radar->exploded_text, (sfVector2f){10, 120});
}

void radar_create_stats_text(radar_t *radar)
{
    radar_landed_text(radar);
    radar_exploded_text(radar);
}
