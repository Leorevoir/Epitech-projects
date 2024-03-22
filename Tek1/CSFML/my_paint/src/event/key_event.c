/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** key_event
*/

#include "event.h"

void handle_key_press_event(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        handle_ctrl_o(game, event);
        if (event.key.control && event.key.code == sfKeyS)
            handle_ctrl_s(game);
        if (event.key.control && event.key.code == sfKeyN)
            create_new_file(game);
    }
}
