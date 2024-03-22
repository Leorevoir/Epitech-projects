/*
** EPITECH PROJECT, 2023
** event.c
** File description:
** Event handling functions
*/

#include "../include/game.h"

int is_click_inside_sprite(sfSprite *sprite, sfVector2i click)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    return sfFloatRect_contains(&bounds, (float)click.x, (float)click.y);
}

int is_left_mouse_click(sfEvent event)
{
    return (event.type == MOUSE && event.mouseButton.button == sfMouseLeft);
}

void process_left_click(game_window_s *window, bird_s *bird, sfVector2i pos)
{
    if (is_click_inside_sprite(bird->sprite, pos)) {
        bird->position.x = -SPRITE_WIDTH;
        if (window->score < MAX_SCORE) {
            window->score++;
            my_itoa(window->score, window->score_text);
        }
    }
}

void handle_events(game_window_s *window, bird_s *bird)
{
    sfEvent event;
    sfVector2i pos;

    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (is_left_mouse_click(event)) {
            pos = sfMouse_getPositionRenderWindow(window->window);
            process_left_click(window, bird, pos);
        }
    }
}
