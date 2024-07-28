/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** display_player_choose.c
*/

#include "display.h"

static void switch_display_menu(rpg_t *rpg, hud_t *hud, characters_t *chars)
{
    switch (chars->who) {
        case (0):
            DRAW_SPRITE(rpg->window, chars->continue_sprite, NULL);
            SCALE(hud->players->my_boy.sprite, (sfVector2f){13, 13});
            DRAW_SPRITE(rpg->window, hud->players->my_boy.sprite, NULL);
            break;
        case (1):
            DRAW_SPRITE(rpg->window, chars->continue_sprite, NULL);
            SCALE(hud->players->my_frog.sprite, (sfVector2f){13, 13});
            DRAW_SPRITE(rpg->window, hud->players->my_frog.sprite, NULL);
            break;
        case (2):
            DRAW_SPRITE(rpg->window, chars->continue_sprite, NULL);
            SCALE(hud->players->my_girl.sprite, (sfVector2f){13, 13});
            DRAW_SPRITE(rpg->window, hud->players->my_girl.sprite, NULL);
            break;
        default:
            break;
    }
}

void display_player_choose(rpg_t *rpg, hud_t *hud)
{
    characters_t *chars = hud->chars;

    sfRenderWindow_drawSprite(rpg->window, chars->log_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, chars->boy_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, chars->frog_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, chars->girl_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, chars->cadre_boy, NULL);
    sfRenderWindow_drawSprite(rpg->window, chars->cadre_frog, NULL);
    sfRenderWindow_drawSprite(rpg->window, chars->cadre_girl, NULL);
    switch_display_menu(rpg, hud, hud->chars);
    sfRenderWindow_display(rpg->window);
}
