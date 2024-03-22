/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** saving_prompt
*/

#include "game.h"
#include "my_string.h"

void display_prompt(game_t *game, const char *message,
    const char *input, sfVector2f position)
{
    sfText* text = sfText_create();
    sfFont* font = sfFont_createFromFile("data/sans.ttf");
    char displayString[270];

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 42);
    my_strcpy(displayString, message);
    my_strcat(displayString, input);
    sfText_setString(text, displayString);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}
