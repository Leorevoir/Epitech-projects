/*
** EPITECH PROJECT, 2023
** window c
** File description:
** Game functions
*/

#include "../include/game.h"

game_window_s initialize_game_window(void)
{
    game_window_s my_window;
    sfVideoMode mode = {1280, 720, 32};
    sfTexture *backgrnd = sfTexture_createFromFile("data/game/1.png", NULL);

    my_window.window = WINDOW_(mode, "MY HUNTER", sfResize | sfClose, NULL);
    my_window.background = sfSprite_create();
    sfRenderWindow_setFramerateLimit(my_window.window, 60);
    my_window.font = sfFont_createFromFile(FONT_PATH);
    sfSprite_setTexture(my_window.background, backgrnd, sfTrue);
    sfRenderWindow_drawSprite(my_window.window, my_window.background, NULL);
    sfRenderWindow_display(my_window.window);
    my_window.score = 0;
    my_strcpy(my_window.score_text, "Score: 0");
    return my_window;
}

void cleanup(game_window_s *my_window, bird_s *bird)
{
    sfSprite_destroy(bird->sprite);
    sfSprite_destroy(my_window->background);
    sfRenderWindow_destroy(my_window->window);
    sfClock_destroy(bird->clock);
    free(bird);
    free(my_window);
}

void render(game_window_s *window, bird_s *bird)
{
    sfText* score_text = sfText_create();

    sfRenderWindow_drawSprite(window->window, window->background, NULL);
    sfSprite_setPosition(bird->sprite, bird->position);
    sfSprite_setTextureRect(bird->sprite, convert(bird->frame));
    sfRenderWindow_drawSprite(window->window, bird->sprite, NULL);
    sfText_setFont(score_text, window->font);
    sfText_setCharacterSize(score_text, 42);
    sfText_setFillColor(score_text, sfWhite);
    sfText_setString(score_text, window->score_text);
    sfText_setPosition(score_text, (sfVector2f){10, 10});
    sfRenderWindow_drawText(window->window, score_text, NULL);
    sfRenderWindow_display(window->window);
}
