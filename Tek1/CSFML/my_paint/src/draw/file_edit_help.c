/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** file_edit_view
*/

#include "game.h"
#include "my_string.h"

bool is_click_outside_menu(sfRenderWindow *window, menu_t menu)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(window);
    sfFloatRect menu_bounds = sfSprite_getGlobalBounds(
        menu.menu_sprite.sprite);

    if (!menu.is_visible) {
        return false;
    }
    if (!sfFloatRect_contains(&menu_bounds,
        mouse_position.x, mouse_position.y)) {
        return true;
    }
    return false;
}

void toggle_menu(menu_t *menu)
{
    menu->is_visible = !menu->is_visible;
}

void select_file(game_t *game)
{
    toggle_menu(&game->file_png);
}

void edit(game_t *game)
{
    toggle_menu(&game->edit_png);
}

void help(game_t *game)
{
    toggle_menu(&game->help_png);
}
