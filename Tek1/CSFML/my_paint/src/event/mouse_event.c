/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** mouse_event
*/

#include "event.h"

void button_released(game_t *game, sfEvent event, button_t *btn)
{
    if (event.mouseButton.button == sfMouseLeft) {
        game->mouse_pressed = sfFalse;
        game->last_coords.last_x = -1;
        game->last_coords.last_y = -1;
    }
    btn = game->buttons;
    while (btn) {
        if (btn->state == BUTTON_CLICKED)
            btn->state = BUTTON_ACTIVE;
        btn = btn->next;
    }
}

void check_button_hovered(game_t *game, sfMouseMoveEvent move)
{
    button_t *current_button = game->buttons;
    sfFloatRect global_bound;

    while (current_button != NULL) {
        global_bound = sfRectangleShape_getGlobalBounds(current_button->rect);
        if (sfFloatRect_contains(&global_bound, move.x, move.y) &&
            current_button->state != BUTTON_CLICKED &&
            current_button->state != BUTTON_ACTIVE) {
            current_button->state = BUTTON_HOVERED;
            return;
            }
        if (current_button->state != BUTTON_CLICKED &&
            current_button->state != BUTTON_ACTIVE)
            current_button->state = BUTTON_INACTIVE;
        current_button = current_button->next;
    }
    return;
}

void handle_peinture(game_t *game)
{
    if (game->selected_tool == PEINTURE) {
        peinture(game);
    }
}

void handle_menu(game_t *game)
{
    if (is_click_outside_menu(game->window, game->file_png)) {
        game->file_png.is_visible = false;
    }
    if (is_click_outside_menu(game->window, game->edit_png)) {
        game->edit_png.is_visible = false;
    }
    if (is_click_outside_menu(game->window, game->help_png)) {
        game->help_png.is_visible = false;
    }
    if (is_click_outside_menu(game->window, game->size_png)) {
        game->help_png.is_visible = false;
    }
}

void handle_mouse_button_event(game_t *game, sfEvent event)
{
    sfVector2f click = { (float)event.mouseButton.x,
        (float)event.mouseButton.y };
    sfMouseMoveEvent move = event.mouseMove;

    update_mouse_position(game);
    check_button_hovered(game, move);
    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft) {
        handle_menu(game);
        handle_color_selection(game, event.mouseButton);
        handle_peinture(game);
        check_button_click(game, click);
        handle_tool_actions(game);
        handle_color(game, click);
    } else if (event.type == sfEvtMouseButtonReleased) {
        handle_color(game, click);
        button_released(game, event, game->buttons);
    }
}
