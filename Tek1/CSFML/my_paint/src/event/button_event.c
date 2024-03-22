/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** button_event
*/

#include "my_string.h"
#include "event.h"

void button_inactive(game_t *game, const char *str)
{
    for (button_t *btn = game->buttons; btn != NULL; btn = btn->next) {
        if (my_strcmp(btn->name, str) == 0) {
            btn->state = BUTTON_INACTIVE;
            break;
        }
    }
}

static bool should_click_default(button_t *clicked_button, game_t *game)
{
    return (NAME != '&' && NAME != '@'
        && NAME != '+' && NAME != '-'
        && !EDIT_V && !SIZE_V && !HELP_V && !FILE_V);
}

static bool not_a_fake(button_t *clicked_button, game_t *game)
{
    if (NAME == '&' && SIZE_V)
        return true;
    if (NAME == '@' && EDIT_V)
        return true;
    if (NAME == '+' && HELP_V)
        return true;
    if (NAME == '-' && FILE_V)
        return true;
    if (should_click_default(clicked_button, game))
        return true;
    return false;
}

button_t *find_clicked_button(button_t *buttons, sfVector2f click,
    game_t *game)
{
    button_t *current_button = buttons;
    sfFloatRect bounds;

    while (current_button != NULL) {
        bounds = sfRectangleShape_getGlobalBounds(current_button->rect);
        if (sfFloatRect_contains(&bounds, click.x, click.y)
        && current_button->action != NULL && not_a_fake(current_button, game))
            return current_button;
        current_button = current_button->next;
    }
    return NULL;
}

void update_button_states(game_t *game, button_t *clicked_button)
{
    button_t *current_button = game->buttons;

    while (current_button != NULL) {
        current_button->state = (current_button == clicked_button)
            ? BUTTON_CLICKED : BUTTON_INACTIVE;
        current_button = current_button->next;
    }
}

static void action_button(game_t *game, button_t *clicked_button)
{
    clicked_button->action(game);
    update_button_states(game, clicked_button);
}

void check_button_click(game_t *game, sfVector2f click)
{
    button_t *clicked_button = find_clicked_button(game->buttons, click, game);

    if (clicked_button != NULL) {
        if (NAME == '&' && SIZE_V)
            action_button(game, clicked_button);
        if (NAME == '@' && EDIT_V)
            action_button(game, clicked_button);
        if (NAME == '+' && HELP_V)
            action_button(game, clicked_button);
        if (NAME == '-' && FILE_V)
            action_button(game, clicked_button);
        if (should_click_default(clicked_button, game))
            action_button(game, clicked_button);
    }
}

void handle_tool_actions(game_t *game)
{
    if ((game->selected_tool == PENCIL || game->selected_tool == ERASER)
    && !game->user_file.is_saving && !game->user_file.is_opening) {
        game->mouse_pressed = true;
    }
}
