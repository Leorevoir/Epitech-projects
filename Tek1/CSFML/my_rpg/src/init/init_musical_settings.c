/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** init_fps_settings.c
*/

#include "my_rpg.h"

void init_sound_settings(settings_t *sett, sfVector2f p)
{
    p.x -= 130;
    p.y += 110;
    init_text_res(&sett->sound, "Sounds", sett, (sfVector2f) {50, 5});
    init_position(NULL, p, (sfVector2f) {273, 85}, &sett->sound);
    p.x += 130;
    sett->square_sprite[1] = init_sprite(&sett->square,
        (sfVector2f) {0.7, 0.7}, SQUARE);
    init_position(&sett->square_sprite[1], p, (sfVector2f) {0, 0}, NULL);
    p.x += 7;
    sett->check_sprite[1] = init_sprite(&sett->square,
        (sfVector2f) {0.7, 0.7}, CHECK);
    init_position(&sett->check_sprite[1], p, (sfVector2f) {0, 0}, NULL);
}

void init_music_settings(settings_t *sett, sfVector2f p)
{
    sett->music_check = true;
    sett->sound_check = true;
    sett->square_sprite = malloc(sizeof(sfSprite *) * 2);
    sett->check_sprite = malloc(sizeof(sfSprite *) * 2);
    p.x = DFLT_HEIGHT / 2 + 130;
    init_text_res(&sett->music, "Musics", sett, (sfVector2f) {50, 5});
    p.y -= 110;
    init_position(NULL, p, (sfVector2f) {273, 85}, &sett->music);
    p.x += 130;
    sett->square_sprite[0] = init_sprite(&sett->square,
        (sfVector2f) {0.7, 0.7}, SQUARE);
    init_position(&sett->square_sprite[0], p, (sfVector2f) {0, 10}, NULL);
    p.x += 7;
    sett->check_sprite[0] = init_sprite(&sett->square,
        (sfVector2f) {0.7, 0.7}, CHECK);
    init_position(&sett->check_sprite[0], p, (sfVector2f) {0, 9}, NULL);
    p.x -= 7;
    init_sound_settings(sett, p);
}
