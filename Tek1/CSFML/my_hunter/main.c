/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** Main file for MY HUNTER
*/

#include "include/game.h"

MY MENU CHECK GAME;

int main(void)
{
    game_window_s *game_window = malloc(sizeof(game_window_s));
    bird_s *bird = initialize_bird();
    menu_s menu = initialize_menu();
    sfClock *clock = sfClock_create();

    *game_window = initialize_game_window();
    while (sfRenderWindow_isOpen(game_window->window)) {
        if (in_menu) {
            handle_menu_events(game_window, &menu);
            render_menu(game_window, &menu);
        } else {
            handle_events(game_window, bird);
            update_bird(bird);
            render(game_window, bird);
        }
    }
    cleanup(game_window, bird);
    return 0;
}
