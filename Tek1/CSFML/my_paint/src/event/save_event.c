/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** save_event
*/

#include "event.h"
#include "my_string.h"

void handle_text_input(char *filename, sfUint32 unicode,
    size_t max_length)
{
    size_t len = my_strlen(filename);

    if (unicode >= 32 && unicode < 128 && len < max_length - 1) {
        filename[len] = (char)unicode;
        filename[len + 1] = '\0';
    } else if (unicode == 8 && len > 0) {
        filename[len - 1] = '\0';
    }
}

static void handle_escape(sfEvent event, game_t *game)
{
    if (event.key.code == sfKeyEscape) {
        game->user_file.is_saving = false;
        game->user_file.save_filename[0] = '\0';
        my_error("Save cancelled.\n");
    }
}

static void handle_save_confirmation(sfEvent event, game_t *game)
{
    if (event.key.code == sfKeyReturn) {
        ensure_default_extension(game->user_file.save_filename);
        save_drawing(game, game->user_file.save_filename);
        game->user_file.is_saving = false;
        game->user_file.save_filename[0] = '\0';
    }
}

void handle_saving_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtTextEntered) {
        handle_text_input(game->user_file.save_filename, event.text.unicode,
            82);
    } else if (event.type == sfEvtKeyPressed) {
        handle_save_confirmation(event, game);
        handle_escape(event, game);
    }
}

void handle_ctrl_s(game_t *game)
{
    game->mouse_pressed = false;
    game->user_file.is_saving = true;
    game->user_file.save_filename[0] = '\0';
}
