/*
** EPITECH PROJECT, 2024
** paint
** File description:
** destroy
*/

#include "game.h"

void destroy_game_object(game_object_t *obj)
{
    if (obj != NULL) {
        if (obj->sprite != NULL)
            sfSprite_destroy(obj->sprite);
        if (obj->texture != NULL)
            sfTexture_destroy(obj->texture);
    }
}

static void destroy_window(sfRenderWindow *window)
{
    if (window != NULL)
        sfRenderWindow_destroy(window);
}

static void destroy_buttons(button_t *buttons, char **buttons_data)
{
    button_t *next;

    while (buttons) {
        next = buttons->next;
        free(buttons->name);
        sfRectangleShape_destroy(buttons->rect);
        free(buttons);
        buttons = next;
    }
    for (int i = 0; buttons_data && buttons_data[i]; i++)
        free(buttons_data[i]);
    free(buttons_data);
}

static void destroy_square(square_t *squares)
{
    square_t *next;

    while (squares) {
        next = squares->next;
        if (squares->shape) {
            sfRectangleShape_destroy(squares->shape);
        }
        free(squares);
        squares = next;
    }
}

static void destroy_circles(circle_t *circles)
{
    circle_t *next;

    while (circles) {
        next = circles->next;
        free(circles);
        circles = next;
    }
}

static void destroy_traits(trait_t *traits)
{
    trait_t *current = traits;
    trait_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void destroy_paint(game_t *game)
{
    free(game->pencil.pixels);
    destroy_game_object(&game->drawing_zone);
    destroy_game_object(&game->background);
    destroy_game_object(&game->file_png.menu_sprite);
    destroy_game_object(&game->edit_png.menu_sprite);
    destroy_game_object(&game->help_png.menu_sprite);
    destroy_game_object(&game->color_png.menu_sprite);
    destroy_game_object(&game->size_png.menu_sprite);
    destroy_game_object(&game->about);
    destroy_game_object(&game->help);
    sfRectangleShape_destroy(game->drawing_rect);
    sfCircleShape_destroy(game->color_circle);
    sfCircleShape_destroy(game->second_circle);
    destroy_traits(game->trait);
    destroy_circles(game->circles);
    destroy_square(game->squares);
    destroy_buttons(game->buttons, NULL);
    destroy_window(game->window);
}
