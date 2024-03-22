/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** display_buttons
*/

#include "game.h"
#include "my_string.h"

static void special_case(button_t *buttons)
{
    switch (buttons->state) {
    case BUTTON_INACTIVE:
        sfRectangleShape_setFillColor(buttons->rect,
            (sfColor){128, 128, 128, 0});
        break;
    case BUTTON_ACTIVE:
        sfRectangleShape_setFillColor(buttons->rect,
            (sfColor){128, 128, 128, 0});
        break;
    case BUTTON_CLICKED:
        sfRectangleShape_setFillColor(buttons->rect,
            (sfColor){96, 96, 96, 100});
        break;
    case BUTTON_HOVERED:
        sfRectangleShape_setFillColor(buttons->rect,
            (sfColor){220, 220, 220, 100});
        break;
    }
}

static void classic_case(button_t *buttons)
{
    switch (buttons->state) {
    case BUTTON_INACTIVE:
        sfRectangleShape_setFillColor(buttons->rect,
            (sfColor){128, 128, 128, 0});
        break;
    case BUTTON_ACTIVE:
        sfRectangleShape_setFillColor(buttons->rect,
            (sfColor){142, 142, 142, 100});
        break;
    case BUTTON_CLICKED:
        sfRectangleShape_setFillColor(buttons->rect,
            (sfColor){96, 96, 96, 100});
        break;
    case BUTTON_HOVERED:
        sfRectangleShape_setFillColor(buttons->rect,
            (sfColor){220, 220, 220, 100});
        break;
    }
}

static void change_color(button_t *buttons)
{
    if (buttons->name[0] == '$' || buttons->name[0] == '&'
        || buttons->name[0] == '@' || buttons->name[0] == '+')
        special_case(buttons);
    else
        classic_case(buttons);
}

void display_buttons(game_t *game)
{
    sfRenderWindow *window = game->window;
    button_t *current = game->buttons;

    while (current != NULL) {
        change_color(current);
        if (NAME0 != '&' && NAME0 != '@' && NAME0 != '+' && NAME0 != '-')
            sfRenderWindow_drawRectangleShape(window, current->rect, NULL);
        if ((NAME0 == '&' || NAME0 == '@' || NAME0 == '+' || NAME0 == '-')
            && button_drawable(current, game))
            sfRenderWindow_drawRectangleShape(window, current->rect, NULL);
        current = current->next;
    }
}
