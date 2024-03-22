/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** popup
*/

#include "game.h"

void create_pop_about(sfRenderWindow *window, sfEvent event,
    game_t *game)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed) {
            game->pop_about = sfFalse;
            game->create_pop = 0;
            sfRenderWindow_close(window);
        }
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, game->about.sprite, NULL);
    sfRenderWindow_display(window);
}

void about_pop_up(game_t *game, sfEvent event)
{
    static sfRenderWindow *window = NULL;
    sfVideoMode mode = {1080, 1080, 32};

    if (game->create_pop == 0) {
        window = sfRenderWindow_create(mode, "About", sfClose, NULL);
        sfRenderWindow_setPosition(window, (sfVector2i){420, 0});
        game->create_pop = 1;
    }
    if (window != NULL) {
        create_pop_about(window, event, game);
    }
}

static void quit(game_t *game, sfRenderWindow *window)
{
    game->pop_help = sfFalse;
    game->create_pop = 0;
    sfRenderWindow_close(window);
}

void change_image(game_t *game, sfRenderWindow *window)
{
    if (game->slide == 1)
        game->help.texture = sfTexture_createFromFile("data/HELP/1.png", NULL);
    if (game->slide == 2)
        game->help.texture = sfTexture_createFromFile("data/HELP/2.png", NULL);
    if (game->slide == 3)
        game->help.texture = sfTexture_createFromFile("data/HELP/3.png", NULL);
    if (game->slide == 4)
        game->help.texture = sfTexture_createFromFile("data/HELP/4.png", NULL);
    if (game->slide == 5)
        game->help.texture = sfTexture_createFromFile("data/HELP/5.png", NULL);
    if (game->slide == 6)
        game->help.texture = sfTexture_createFromFile("data/HELP/6.png", NULL);
    if (game->slide == 7) {
        game->slide = 0;
        game->help.texture = sfTexture_createFromFile("data/HELP/0.png", NULL);
        sfSprite_setTexture(game->help.sprite, game->help.texture, sfTrue);
        quit(game, window);
    }
    sfSprite_setTexture(game->help.sprite, game->help.texture, sfTrue);
}

void create_pop_help(sfRenderWindow *window, sfEvent event, game_t *game)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            game->pop_help = sfFalse;
            game->create_pop = 0;
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            game->slide++;
            change_image(game, window);
        }
    }
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, game->help.sprite, NULL);
    sfRenderWindow_display(window);
}

void help_pop_up(game_t *game, sfEvent event)
{
    static sfRenderWindow *window = NULL;
    sfVideoMode mode = {1920, 1080, 32};

    if (game->create_pop == 0) {
        window = sfRenderWindow_create(mode, "Help", sfClose, NULL);
        sfRenderWindow_setPosition(window, (sfVector2i){0, 0});
        game->create_pop = 1;
    }
    if (window != NULL) {
        create_pop_help(window, event, game);
    }
}
