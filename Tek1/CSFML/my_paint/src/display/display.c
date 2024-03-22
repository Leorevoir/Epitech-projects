/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** display
*/

#include "game.h"
#include "my_string.h"

static void display_basic_elements(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->background.sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->drawing_rect, NULL);
    sfRenderWindow_drawSprite(game->window, game->drawing_zone.sprite, NULL);
}

static void draw_squares(sfRenderWindow *window, square_t *head)
{
    square_t *square = head;

    while (square != NULL) {
        if (square->shape != NULL) {
            sfRenderWindow_drawRectangleShape(window, square->shape, NULL);
        }
        square = square->next;
    }
}

static void draw_circles(sfRenderWindow *window, circle_t *head)
{
    circle_t *circle = head;

    while (circle != NULL) {
        if (circle->shape != NULL) {
            sfRenderWindow_drawCircleShape(window, circle->shape, NULL);
        }
        circle = circle->next;
    }
}

static void display_traits(game_t *game)
{
    for (trait_t *current = game->trait; current;
        current = current->next)
        draw_trait_in_buffer(game, current->point_a,
            current->point_b, current->color);
}

void display_opening_prompt(game_t *game)
{
    if (game->user_file.is_opening) {
        display_prompt(game, "Enter file path: ",
            game->user_file.open_filename, (sfVector2f){WIDTH / 2.75, 15});
    }
}

void display_saving_prompt(game_t *game)
{
    if (game->user_file.is_saving) {
        display_prompt(game, "Enter filename: ",
            game->user_file.save_filename, (sfVector2f){WIDTH / 2.75, 15});
    }
}

void display_menu(game_t *game)
{
    if (game->file_png.is_visible)
        sfRenderWindow_drawSprite(
            game->window, game->file_png.menu_sprite.sprite, NULL);
    if (game->edit_png.is_visible)
        sfRenderWindow_drawSprite(
            game->window, game->edit_png.menu_sprite.sprite, NULL);
    if (game->help_png.is_visible)
        sfRenderWindow_drawSprite(
            game->window, game->help_png.menu_sprite.sprite, NULL);
    if (game->color_png.is_visible)
        sfRenderWindow_drawSprite(
            game->window, game->color_png.menu_sprite.sprite, NULL);
    if (game->size_png.is_visible)
        sfRenderWindow_drawSprite(
            game->window, game->size_png.menu_sprite.sprite, NULL);
}

void display_paint(game_t *game)
{
    display_basic_elements(game);
    if (game->user_file.is_saving)
        display_saving_prompt(game);
    if (game->user_file.is_opening)
        display_opening_prompt(game);
    sfRenderWindow_drawSprite(game->window, game->drawing_zone.sprite, NULL);
    sfCircleShape_setFillColor(game->color_circle, game->pencil.color);
    sfRenderWindow_drawCircleShape(game->window, game->color_circle, NULL);
    sfCircleShape_setFillColor(game->second_circle,
        game->pencil.secondary_color);
    sfRenderWindow_drawCircleShape(game->window, game->second_circle, NULL);
    display_menu(game);
    display_traits(game);
    draw_circles(game->window, game->circles);
    draw_squares(game->window, game->squares);
    display_buttons(game);
    sfRenderWindow_display(game->window);
}
