/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** update_player_choose.c
*/

#include "my_rpg.h"
#include "update.h"

static void hover_boy(characters_t *chars, sfVector2i m, sfFloatRect pos)
{
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue || chars->who == BOY)
        sfSprite_setTexture(chars->cadre_boy, chars->choosed, 0);
    else
        sfSprite_setTexture(chars->cadre_boy, chars->cadre, 0);
}

static void hover_frog(characters_t *chars, sfVector2i m, sfFloatRect pos)
{
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue || chars->who == FROG)
        sfSprite_setTexture(chars->cadre_frog, chars->choosed, 0);
    else
        sfSprite_setTexture(chars->cadre_frog, chars->cadre, 0);
}

static void hover_girl(characters_t *chars, sfVector2i m, sfFloatRect pos)
{
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue || chars->who == GIRL)
        sfSprite_setTexture(chars->cadre_girl, chars->choosed, 0);
    else
        sfSprite_setTexture(chars->cadre_girl, chars->cadre, 0);
}

static void click_boy(hud_t *hud, sfVector2i m, sfFloatRect pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        sfSprite_setTexture(hud->chars->cadre_boy, hud->chars->choosed, 0);
        sfSprite_setTexture(hud->chars->cadre_frog, hud->chars->cadre, 0);
        sfSprite_setTexture(hud->chars->cadre_girl, hud->chars->cadre, 0);
        hud->chars->who = BOY;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        SET_TEXTURE(IPL->my_boy.sprite, IPL->boy[DIR_LEFT], sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        SET_TEXTURE(IPL->my_boy.sprite, IPL->boy[DIR_RIGHT], sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        SET_TEXTURE(IPL->my_boy.sprite, IPL->boy[DIR_UP], sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        SET_TEXTURE(IPL->my_boy.sprite, IPL->boy[DIR_DOWN], sfFalse);
}

static void click_frog(hud_t *hud, sfVector2i m, sfFloatRect pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        sfSprite_setTexture(hud->chars->cadre_boy, hud->chars->cadre, 0);
        sfSprite_setTexture(hud->chars->cadre_frog, hud->chars->choosed, 0);
        sfSprite_setTexture(hud->chars->cadre_girl, hud->chars->cadre, 0);
        hud->chars->who = FROG;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        sfSprite_setTexture(IPL->my_frog.sprite, IPL->frog[DIR_LEFT], sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        sfSprite_setTexture(IPL->my_frog.sprite, IPL->frog[DIR_RIGHT],
            sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        sfSprite_setTexture(IPL->my_frog.sprite, IPL->frog[DIR_UP], sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        sfSprite_setTexture(IPL->my_frog.sprite, IPL->frog[DIR_DOWN], sfFalse);
}

void click_girl(hud_t *hud, sfVector2i m, sfFloatRect pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        sfSprite_setTexture(hud->chars->cadre_boy, hud->chars->cadre, 0);
        sfSprite_setTexture(hud->chars->cadre_frog, hud->chars->cadre, 0);
        sfSprite_setTexture(hud->chars->cadre_girl, hud->chars->choosed, 0);
        hud->chars->who = GIRL;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        sfSprite_setTexture(IPL->my_girl.sprite, IPL->girl[DIR_LEFT], sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        sfSprite_setTexture(IPL->my_girl.sprite, IPL->girl[DIR_RIGHT],
            sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        sfSprite_setTexture(IPL->my_girl.sprite, IPL->girl[DIR_UP], sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        sfSprite_setTexture(IPL->my_girl.sprite, IPL->girl[DIR_DOWN], sfFalse);
}

void continue_button(hud_t *hud, sfVector2i m, sfFloatRect pos, rpg_t *rpg)
{
    characters_t *chars = hud->chars;

    pos = sfRectangleShape_getGlobalBounds(chars->continue_rect);
    if (sfFloatRect_contains(&pos, m.x, m.y) == sfTrue)
        sfSprite_setTexture(chars->continue_sprite, chars->hcontinue, 0);
    else
        sfSprite_setTexture(chars->continue_sprite, chars->icontinue, 0);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&pos, m.x, m.y) == sfTrue) {
        rpg->tool.who = hud->chars->who;
        init_player(rpg);
        sfSprite_setTexture(chars->continue_sprite, chars->pcontinue, 0);
        hud->display = false;
        hud->chars->display = false;
    }
}

void update_player_choose(hud_t *hud, rpg_t *rpg)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->window);
    sfFloatRect pos = sfRectangleShape_getGlobalBounds(hud->chars->boy_rect);
    sfVector2i mp = convert_mouse_position(rpg->window, mouse);

    hover_boy(hud->chars, mp, pos);
    click_boy(hud, mp, pos);
    pos = sfRectangleShape_getGlobalBounds(hud->chars->frog_rect);
    hover_frog(hud->chars, mp, pos);
    click_frog(hud, mp, pos);
    pos = sfRectangleShape_getGlobalBounds(hud->chars->girl_rect);
    hover_girl(hud->chars, mp, pos);
    click_girl(hud, mp, pos);
    continue_button(hud, mp, pos, rpg);
}
