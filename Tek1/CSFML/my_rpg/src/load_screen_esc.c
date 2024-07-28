/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** load_screen_esc
*/

#include "my_rpg.h"

void load_progress_esc(sfRectangleShape *loading_bar,
    sfRectangleShape *background, rpg_t *rpg, hud_t *hud)
{
    float loading_progress = 0.0;

    for (int i = 0; i < 100; i += 15) {
        loading_progress = i;
        sfRectangleShape_setSize(loading_bar,
            (sfVector2f){4 * loading_progress, 50});
        sfRenderWindow_clear(rpg->window, sfBlack);
        sfRenderWindow_drawSprite(rpg->window, hud->menu->back_sprite, NULL);
        sfRenderWindow_drawSprite(rpg->window, hud->menu->name_sprite, NULL);
        sfRenderWindow_drawRectangleShape(rpg->window, background, NULL);
        sfRenderWindow_drawRectangleShape(rpg->window, loading_bar, NULL);
        sfRenderWindow_display(rpg->window);
        sfSleep(sfMilliseconds(100));
    }
}

int loading_screen_esc(rpg_t *rpg, hud_t *hud)
{
    sfRectangleShape *background;
    sfRectangleShape *loading_bar;

    background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(background,
        sfColor_fromRGBA(50, 50, 50, 200));
    sfRectangleShape_setSize(background, (sfVector2f){400, 50});
    sfRectangleShape_setPosition(background, (sfVector2f){760, 540});
    loading_bar = sfRectangleShape_create();
    sfRectangleShape_setFillColor(loading_bar,
        sfColor_fromRGBA(100, 200, 50, 255));
    sfRectangleShape_setSize(loading_bar, (sfVector2f){0, 50});
    sfRectangleShape_setPosition(loading_bar, (sfVector2f){760, 540});
    load_progress_esc(loading_bar, background, rpg, hud);
    sfRectangleShape_destroy(background);
    sfRectangleShape_destroy(loading_bar);
    return 0;
}
