/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** update_settings_hud.c
*/

#include "update.h"

static void update_language(settings_t *sett, rpg_t *rpg)
{
    if (rpg->lang == FRENCH) {
        sfText_setString(sett->language, "Langue");
        sfText_setPosition(sett->language, (sfVector2f) {910, 150});
        if (strcmp(sfText_getString(sett->res_choosed), "Fullscreen") == 0)
            sfText_setString(sett->res_choosed, "Plein ecran");
        if (strcmp(sfText_getString(sett->resfull), "Fullscreen") == 0)
            sfText_setString(sett->resfull, "Plein ecran");
        if (strcmp(sfText_getString(sett->res1920), "Fullscreen") == 0)
            sfText_setString(sett->res1920, "Plein ecran");
    }
    if (rpg->lang == ENGLISH) {
        sfText_setString(sett->language, "Language");
        sfText_setPosition(sett->language, (sfVector2f) {890, 150});
        if (strcmp(sfText_getString(sett->res_choosed), "Plein ecran") == 0)
            sfText_setString(sett->res_choosed, "Fullscreen");
        if (strcmp(sfText_getString(sett->resfull), "Plein ecran") == 0)
            sfText_setString(sett->resfull, "Fullscreen");
        if (strcmp(sfText_getString(sett->res1920), "Plein ecran") == 0)
            sfText_setString(sett->res1920, "Fullscreen");
    }
}

void update_eng(settings_t *sett, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        sfSprite_setTexture(sett->english_sprite, sett->henglish, 0);
    else
        sfSprite_setTexture(sett->english_sprite, sett->ienglish, 0);
    if (rpg->lang == ENGLISH || (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)) {
        sfSprite_setTexture(sett->english_sprite, sett->penglish, 0);
        rpg->lang = ENGLISH;
        update_language(sett, rpg);
    }
}

void update_fr(settings_t *sett, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(sett->french_rect);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        sfSprite_setTexture(sett->french_sprite, sett->hfrench, 0);
    else
        sfSprite_setTexture(sett->french_sprite, sett->ifrench, 0);
    if (rpg->lang == FRENCH || (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)) {
        sfSprite_setTexture(sett->french_sprite, sett->pfrench, 0);
        rpg->lang = FRENCH;
        update_language(sett, rpg);
    }
}

static void set_volume_musics(rpg_t *rpg)
{
    float ratio = (rpg->volume / 100);

    sfMusic_setVolume(rpg->music.menu, rpg->music.volume_menu * ratio);
    sfMusic_setVolume(rpg->music.village, rpg->music.volume_village * ratio);
    sfMusic_setVolume(rpg->music.road, rpg->music.volume_road * ratio);
    sfMusic_setVolume(rpg->music.boss, rpg->music.volume_boss * ratio);
    sfMusic_setVolume(rpg->music.swing_sound, rpg->music.volume_swing * ratio);
    sfMusic_setVolume(rpg->music.heal_sound, rpg->music.volume_heal * ratio);
}

static void adjst_vol(rpg_t *rpg, settings_t *sett)
{
    sfVector2f rect = sfRectangleShape_getPosition(sett->vol_bar);
    sfVector2f point = sfCircleShape_getPosition(sett->vol_point);

    rect.x -= 300;
    point.x -= rect.x;
    rpg->volume = (float) point.x / 6;
    if (rpg->volume <= 3)
        rpg->volume = 0;
    if (rpg->volume >= 97)
        rpg->volume = 100;
    set_volume_musics(rpg);
}

static void update_volume(settings_t *sett, sfVector2i m, rpg_t *rpg)
{
    sfFloatRect bar_bounds = sfRectangleShape_getGlobalBounds(sett->vol_bar);
    sfFloatRect pot_bounds = sfCircleShape_getGlobalBounds(sett->vol_point);
    sfVector2f new_pos;

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pot_bounds, m.x, m.y)) {
            new_pos = (sfVector2f) {m.x,
                sfCircleShape_getPosition(sett->vol_point).y};
            if (new_pos.x < bar_bounds.left) {
                new_pos.x = bar_bounds.left;
            }
            if (new_pos.x > bar_bounds.left + bar_bounds.width) {
                new_pos.x = bar_bounds.left + bar_bounds.width;
            }
            sfCircleShape_setPosition(sett->vol_point, new_pos);
            adjst_vol(rpg, sett);
    }
}

void update_resolution(settings_t *sett, rpg_t *rpg)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect pos = sfRectangleShape_getGlobalBounds(sett->english_rect);

    pos = sfSprite_getGlobalBounds(sett->res_sprite[0]);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        if (sett->display_res == false) {
            sett->display_res = true;
            return;
        } else {
            sett->display_res = false;
            return;
        }
    }
}

static void update_res(settings_t *sett, sfVector2i m, sfFloatRect pos)
{
    const char *choosed = NULL;

    pos = sfSprite_getGlobalBounds(sett->res_sprite[1]);
    if (sett->display_res == true && sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        sett->display_res = false;
        choosed = sfText_getString(sett->res_choosed);
        sfText_setString(sett->res_choosed, sfText_getString(sett->resfull));
        sfText_setString(sett->resfull, choosed);
    }
    pos = sfSprite_getGlobalBounds(sett->res_sprite[2]);
    if (sett->display_res == true && sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        sett->display_res = false;
        choosed = sfText_getString(sett->res_choosed);
        sfText_setString(sett->res_choosed, sfText_getString(sett->res1920));
        sfText_setString(sett->res1920, choosed);
    }
}

void update_settings_hud(hud_t *hud, rpg_t *rpg)
{
    settings_t *sett = hud->sett;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect pos = sfRectangleShape_getGlobalBounds(sett->english_rect);

    update_eng(sett, mouse, pos, rpg);
    update_fr(sett, mouse, pos, rpg);
    update_volume(sett, mouse, rpg);
    update_res(sett, mouse, pos);
    update_window(rpg, sett);
}
