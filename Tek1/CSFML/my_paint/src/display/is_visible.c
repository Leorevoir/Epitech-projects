/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** is_visible
*/

#include "game.h"
#include "my_string.h"

static sfBool is_file_button(button_t *button)
{
    return (my_strcmp(button->name, "-new") == 0 ||
        my_strcmp(button->name, "-open") == 0 ||
        my_strcmp(button->name, "-save") == 0);
}

static sfBool is_help_button(button_t *button)
{
    return (my_strcmp(button->name, "+about") == 0 ||
        my_strcmp(button->name, "+help") == 0);
}

static sfBool is_size_button(button_t *button)
{
    return (my_strcmp(button->name, "&px1") == 0 ||
        my_strcmp(button->name, "&px3") == 0 ||
        my_strcmp(button->name, "&px5") == 0 ||
        my_strcmp(button->name, "&px8") == 0);
}

static sfBool is_edit_button(button_t *button)
{
    return (my_strcmp(button->name, "@pencil") == 0 ||
        my_strcmp(button->name, "@eraser") == 0);
}

sfBool button_drawable(button_t *button, game_t *game)
{
    if (is_file_button(button))
        return game->file_png.is_visible;
    if (is_help_button(button))
        return game->help_png.is_visible;
    if (is_size_button(button))
        return game->size_png.is_visible;
    if (is_edit_button(button))
        return game->edit_png.is_visible;
    return sfFalse;
}
