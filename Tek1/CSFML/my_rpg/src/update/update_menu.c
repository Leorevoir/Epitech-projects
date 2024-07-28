/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** update_menu.c
*/

#include "update.h"

void click_new(hud_t *hud, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    pos = sfRectangleShape_getGlobalBounds(hud->menu->ngame_rect);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(hud->menu->ngame_sprite,
                hud->menu->pngame_eng, 0);
        else
            sfSprite_setTexture(hud->menu->ngame_sprite,
                hud->menu->pngame_fr, 0);
        hud->chars->display = true;
    }
}

void click_load(hud_t *hud, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    struct stat st;

    pos = sfRectangleShape_getGlobalBounds(hud->menu->lgame_rect);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        if (rpg->lang == ENGLISH)
            sfSprite_setTexture(hud->menu->lgame_sprite,
                hud->menu->plgame_eng, 0);
        else
            sfSprite_setTexture(hud->menu->lgame_sprite,
                hud->menu->plgame_fr, 0);
        if (stat(".save", &st) != 0)
            return;
        load_progression(rpg);
        hud->display = false;
    }
}

static void click_settings(
    hud_t *hud, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
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

static void click_exit(hud_t *hud, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
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
        sfRenderWindow_close(rpg->window);
        }
}

static void update_back(hud_t *hud, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
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

sfVector2i convert_mouse_position(sfRenderWindow *window, sfVector2i mouse_pos)
{
    sfVector2u w = sfRenderWindow_getSize(window);
    const sfView *v = sfRenderWindow_getView(window);
    sfVector2f v_size = sfView_getSize(v);
    sfVector2f v_center = sfView_getCenter(v);
    sfFloatRect resize_v = {
        v_center.x - (v_size.x / 2),
        v_center.y - (v_size.y / 2),
        v_size.x,
        v_size.y
    };
    sfVector2i adjusted_mouse_pos = {
        (int)((float)mouse_pos.x / w.x * resize_v.width + resize_v.left),
        (int)((float)mouse_pos.y / w.y * resize_v.height + resize_v.top)
    };

    return adjusted_mouse_pos;
}

static void handle_button_events(
    hud_t *hud, rpg_t *rpg, sfVector2i real_mouse, sfFloatRect pos)
{
    hover_new(hud->menu, real_mouse, pos, rpg);
    hover_load(hud->menu, real_mouse, pos, rpg);
    hov_seting(hud->menu, real_mouse, pos, rpg);
    hover_exit(hud->menu, real_mouse, pos, rpg);
    click_new(hud, real_mouse, pos, rpg);
    click_load(hud, real_mouse, pos, rpg);
    click_settings(hud, real_mouse, pos, rpg);
    click_exit(hud, real_mouse, pos, rpg);
}

void update_menu(hud_t *hud, rpg_t *rpg)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2i real_mouse = convert_mouse_position(rpg->window, mouse);
    sfFloatRect pos = sfRectangleShape_getGlobalBounds(hud->back_rect);

    update_back(hud, real_mouse, pos, rpg);
    if (hud->chars->display == true) {
        update_player_choose(hud, rpg);
        return;
    }
    if (hud->sett->display == true) {
        update_settings_hud(hud, rpg);
        return;
    }
    handle_button_events(hud, rpg, real_mouse, pos);
}
