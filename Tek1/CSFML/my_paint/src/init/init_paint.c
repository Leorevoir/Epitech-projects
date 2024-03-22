/*
** EPITECH PROJECT, 2024
** paint
** File description:
** init
*/

#include "init.h"
#include "my_string.h"

void create_drawing_rect(game_t *game)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f rect_size = {RECT_WIDTH, RECT_HEIGHT};
    sfFloatRect bounds = sfSprite_getGlobalBounds(game->background.sprite);
    sfVector2f rect_position = {(bounds.width - rect_size.x) / 2,
        (bounds.height - rect_size.y) / 1.3563};

    sfRectangleShape_setSize(rectangle, rect_size);
    sfRectangleShape_setFillColor(rectangle, sfWhite);
    sfRectangleShape_setPosition(rectangle, rect_position);
    game->drawing_rect = rectangle;
}

void init_buttons(game_t *game)
{
    char **buttons_data = get_buttons_data();

    game->buttons = NULL;
    create_buttons(&game->buttons, buttons_data);
    free_word_array(buttons_data);
}

void init_paint(game_t *game)
{
    game->mouse_pressed = sfFalse;
    game->pop_about = sfFalse;
    game->pop_help = sfFalse;
    game->last_coords.last_x = -1;
    game->last_coords.last_y = -1;
    game->selected_tool = PENCIL;
    game->user_file.is_saving = sfFalse;
    game->user_file.is_opening = sfFalse;
    game->squares = NULL;
    game->circles = NULL;
    game->trait = NULL;
    init_window(&game->window);
    create_pencil(game);
    init_object(game);
    create_drawing_rect(game);
    init_buttons(game);
    pencil(game);
}
