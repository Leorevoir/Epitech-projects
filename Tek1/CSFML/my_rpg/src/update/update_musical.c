/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** update_fps.c
*/

#include "my_rpg.h"

void update_sound(settings_t *sett, rpg_t *rpg, sfVector2i m, sfFloatRect pos)
{
    pos = sfSprite_getGlobalBounds(sett->square_sprite[1]);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        if (sett->sound_check == false) {
            sett->sound_check = true;
            rpg->music.sound = true;
        } else {
            sett->sound_check = false;
            rpg->music.sound = false;
        }
    }
}

void update_musical(settings_t *sett, rpg_t *rpg)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect pos = sfSprite_getGlobalBounds(sett->square_sprite[0]);

    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        if (sett->music_check == false) {
            sett->music_check = true;
            rpg->music.music = true;
        } else {
            sett->music_check = false;
            rpg->music.music = false;
        }
    }
    update_sound(sett, rpg, m, pos);
}
