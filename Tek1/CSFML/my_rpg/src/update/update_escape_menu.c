/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** update_menu.c
*/

#include "update.h"

static void hover_escape_res(menu_t *menu, sfVector2i m,
    sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(menu->r_rect);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->resume_sprite, menu->hresume_eng, 0);
        else
            sfSprite_setTexture(menu->resume_sprite, menu->hresume_fr, 0);
    else
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->resume_sprite, menu->iresume_eng, 0);
        else
            sfSprite_setTexture(menu->resume_sprite, menu->iresume_fr, 0);
}

static void h_e_load(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(menu->lgame_rect);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->lgame_sprite, menu->hlgame_eng, 0);
        else
            sfSprite_setTexture(menu->lgame_sprite, menu->hlgame_fr, 0);
    else
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->lgame_sprite, menu->ilgame_eng, 0);
        else
            sfSprite_setTexture(menu->lgame_sprite, menu->ilgame_fr, 0);
}

static void h_e_seting(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(menu->setting_rect);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->settings_sprite, menu->hsetting_eng, 0);
        else
            sfSprite_setTexture(menu->settings_sprite, menu->hsetting_fr, 0);
    else
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->settings_sprite, menu->isetting_eng, 0);
        else
            sfSprite_setTexture(menu->settings_sprite, menu->isetting_fr, 0);
}

static void h_e_exit(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(menu->exit_rect);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->exit_sprite, menu->hexit_eng, 0);
        else
            sfSprite_setTexture(menu->exit_sprite, menu->hexit_fr, 0);
    else
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(menu->exit_sprite, menu->iexit_eng, 0);
        else
            sfSprite_setTexture(menu->exit_sprite, menu->iexit_fr, 0);
}

void click_escape_res(hud_t *hud, sfVector2i m, sfFloatRect pos)
{
    pos = sfRectangleShape_getGlobalBounds(hud->menu->r_rect);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
            hud->display = false;
            hud->menu->escape = false;
        }
}

void click_escape_load(hud_t *hud, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(hud->menu->lgame_rect);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(hud->menu->lgame_sprite,
                hud->menu->plgame_eng, 0);
        else
            sfSprite_setTexture(hud->menu->lgame_sprite,
                hud->menu->plgame_fr, 0);
        load_progression(rpg);
        hud->display = false;
    }
}

void c_e_settings(hud_t *hud, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(hud->menu->setting_rect);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(hud->menu->settings_sprite,
                hud->menu->psetting_eng, 0);
        else
            sfSprite_setTexture(hud->menu->settings_sprite,
                hud->menu->psetting_fr, 0);
        hud->sett->display = true;
    }
}

void click_escape_exit(hud_t *hud, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(hud->menu->exit_rect);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(hud->menu->exit_sprite,
                hud->menu->pexit_eng, 0);
        else
            sfSprite_setTexture(hud->menu->exit_sprite,
                hud->menu->pexit_fr, 0);
        hud->display = true;
        hud->menu->display = true;
        hud->menu->escape = false;
        sfMusic_stop(rpg->music.village);
        sfMusic_stop(rpg->music.lose);
        sfMusic_stop(rpg->music.win);
        sfMusic_stop(rpg->music.boss);
        sfMusic_stop(rpg->music.road);
        loading_screen_esc(rpg, hud);
        }
}

static void update_escape_back(hud_t *hud, sfVector2i m,
    sfFloatRect pos, rpg_t *rpg)
{
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(hud->back_sprite, hud->hback_eng, 0);
        else
            sfSprite_setTexture(hud->back_sprite, hud->hback_fr, 0);
    else
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(hud->back_sprite, hud->iback_eng, 0);
        else
            sfSprite_setTexture(hud->back_sprite, hud->iback_fr, 0);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(hud->back_sprite, hud->pback_eng, 0);
        else
            sfSprite_setTexture(hud->back_sprite, hud->pback_fr, 0);
        hud->sett->display = false;
        hud->chars->display = false;
    }
}

void update_escape_menu(hud_t *hud, rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect pos = sfRectangleShape_getGlobalBounds(hud->back_rect);
    sfVector2i mouse = convert_mouse_position(rpg->window, mp);

    update_escape_back(hud, mouse, pos, rpg);
    if (hud->sett->display == true) {
        update_settings_hud(hud, rpg);
        checkup_music(rpg, hud);
        return;
    }
    handle_save_escape_menu(hud, rpg, mouse);
    hover_escape_res(hud->menu, mouse, pos, rpg);
    h_e_load(hud->menu, mouse, pos, rpg);
    h_e_seting(hud->menu, mouse, pos, rpg);
    h_e_exit(hud->menu, mouse, pos, rpg);
    click_escape_res(hud, mouse, pos);
    click_escape_load(hud, mouse, pos, rpg);
    c_e_settings(hud, mouse, pos, rpg);
    click_escape_exit(hud, mouse, pos, rpg);
}
