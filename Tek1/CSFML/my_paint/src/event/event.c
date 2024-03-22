/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** event
*/

#include "event.h"
#include "my_string.h"

void handle_close_event(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
}

void check_return(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        if (game->user_file.is_saving) {
            game->user_file.is_saving = false;
            game->user_file.save_filename[0] = '\0';
        }
        if (game->user_file.is_opening) {
            game->user_file.is_opening = false;
            game->user_file.open_filename[0] = '\0';
        }
    }
}

void handle_save_open(game_t *game, sfEvent event)
{
    if (game->user_file.is_saving) {
        handle_saving_events(game, event);
        handle_close_event(game, event);
    } else if (game->user_file.is_opening) {
        handle_opening_events(game, event);
        handle_close_event(game, event);
    }
}

void handle_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        check_return(game, event);
        handle_save_open(game, event);
        if (!game->user_file.is_saving && !game->user_file.is_opening) {
            handle_mouse_button_event(game, event);
            handle_close_event(game, event);
            handle_key_press_event(game, event);
            handle_form_event(game, event);
        }
    }
}
