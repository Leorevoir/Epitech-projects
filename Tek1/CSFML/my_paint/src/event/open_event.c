/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** open_event
*/

#include "event.h"

void open_ctrl(game_t *game)
{
    game->user_file.is_opening = true;
    game->user_file.open_filename[0] = '\0';
}

void handle_ctrl_o(game_t *game, sfEvent event)
{
    if (event.key.control && event.key.code == sfKeyO) {
        open_ctrl(game);
    }
}

static void handle_opening_escape(sfEvent event, game_t *game)
{
    if (event.key.code == sfKeyEscape) {
        game->user_file.is_opening = false;
        game->user_file.open_filename[0] = '\0';
        my_error("Open cancelled.\n");
    }
}

static void handle_opening_return(sfEvent event, game_t *game)
{
    if (event.key.code == sfKeyReturn) {
        open_drawing(game, game->user_file.open_filename);
        game->user_file.is_opening = false;
        game->user_file.open_filename[0] = '\0';
    }
}

void handle_opening_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtTextEntered) {
        handle_text_input(game->user_file.open_filename,
            event.text.unicode, 82);
    } else if (event.type == sfEvtKeyPressed) {
        handle_opening_return(event, game);
        handle_opening_escape(event, game);
    }
}
