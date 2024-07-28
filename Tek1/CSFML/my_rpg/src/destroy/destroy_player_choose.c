/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** destroy_player_choose.c
*/

#include "../../include/my_rpg.h"

static void destroy_boy(characters_t *chars)
{
    sfTexture_destroy(chars->boy);
    sfRectangleShape_destroy(chars->boy_rect);
    sfSprite_destroy(chars->boy_sprite);
    sfSprite_destroy(chars->cadre_boy);
}

static void destroy_frog(characters_t *chars)
{
    sfTexture_destroy(chars->frog);
    sfRectangleShape_destroy(chars->frog_rect);
    sfSprite_destroy(chars->frog_sprite);
    sfSprite_destroy(chars->cadre_frog);
}

static void destroy_girl(characters_t *chars)
{
    sfTexture_destroy(chars->girl);
    sfRectangleShape_destroy(chars->girl_rect);
    sfSprite_destroy(chars->girl_sprite);
    sfSprite_destroy(chars->cadre_girl);
}

static void destroy_continue(characters_t *chars)
{
    sfTexture_destroy(chars->icontinue);
    sfTexture_destroy(chars->hcontinue);
    sfTexture_destroy(chars->pcontinue);
    sfSprite_destroy(chars->continue_sprite);
    sfRectangleShape_destroy(chars->continue_rect);
}

static void destroy_log(characters_t *chars)
{
    sfTexture_destroy(chars->log);
    sfSprite_destroy(chars->log_sprite);
}

void destroy_player_choose(characters_t *chars)
{
    sfTexture_destroy(chars->cadre);
    sfTexture_destroy(chars->choosed);
    destroy_log(chars);
    destroy_boy(chars);
    destroy_frog(chars);
    destroy_girl(chars);
    destroy_continue(chars);
    if (chars)
        free(chars);
}
