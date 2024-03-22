/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** tools
*/

#include "game.h"
#include "my_string.h"

void what_color_did_user_picked(game_t *game)
{
    if (game->pencil.is_second) {
        game->pencil.current = game->pencil.secondary_color;
    } else {
        game->pencil.current = game->pencil.color;
    }
}

void pencil(game_t *game)
{
    button_t *btn = game->buttons;

    game->selected_tool = PENCIL;
    what_color_did_user_picked(game);
    while (btn != NULL) {
        if (my_strcmp(btn->name, "pencil") == 0) {
            btn->is_selected = true;
            btn->state = BUTTON_ACTIVE;
        } else
            btn->is_selected = false;
        btn = btn->next;
    }
}

void eraser(game_t *game)
{
    button_t *btn = game->buttons;
    sfColor transparent = {0, 0, 0, 0};

    game->selected_tool = ERASER;
    if (game->pencil.current.r != transparent.r ||
        game->pencil.current.g != transparent.g ||
        game->pencil.current.b != transparent.b ||
        game->pencil.current.a != transparent.a) {
        game->pencil.current = transparent;
    }
    while (btn != NULL) {
        if (my_strcmp(btn->name, "eraser") == 0)
            btn->is_selected = true;
        else
            btn->is_selected = false;
        btn = btn->next;
    }
}

void pipette(game_t *game)
{
    for (button_t *btn = game->buttons; btn != NULL; btn = btn->next) {
        btn->is_selected = (my_strcmp(btn->name, "pipette") == 0);
        btn->state = btn->is_selected ? BUTTON_ACTIVE : BUTTON_INACTIVE;
    }
    game->selected_tool = PIPETTE;
}

void select_peinture(game_t *game)
{
    for (button_t *btn = game->buttons; btn != NULL; btn = btn->next) {
        if (my_strcmp(btn->name, "peinture") == 0) {
            btn->is_selected = true;
            btn->state = BUTTON_ACTIVE;
        } else {
            btn->is_selected = false;
            btn->state = BUTTON_INACTIVE;
        }
    }
    what_color_did_user_picked(game);
    game->selected_tool = PEINTURE;
}
