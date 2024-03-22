/*
** EPITECH PROJECT, 2023
** menu event c
** File description:
** event for menu
*/

#include "../include/game.h"

void handle_menu_events(game_window_s *window, menu_s *menu)
{
    sfEvent event;
    sfVector2i pos;

    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (event.type == sfEvtMouseMoved) {
            pos = sfMouse_getPositionRenderWindow(window->window);
            menu->is_play_hovered = is_mouse_on_play(pos, menu);
            menu->is_quit_hovered = is_mouse_on_quit(pos, menu);
        }
        if (is_left_mouse_click(event)) {
            pos = sfMouse_getPositionRenderWindow(window->window);
            process_menu_clicks(window, menu, pos);
        }
    }
}

int process_menu_clicks(game_window_s *window, menu_s *menu, sfVector2i pos)
{
    if (is_click_inside_text(menu->play_txt, pos)) {
        in_menu = 0;
        return 1;
    }
    if (is_click_inside_text(menu->quit_txt, pos)) {
        sfRenderWindow_close(window->window);
        return 1;
    }
    return 0;
}

int is_click_inside_text(sfText *text, sfVector2i click)
{
    sfFloatRect bounds = sfText_getGlobalBounds(text);

    return sfFloatRect_contains(&bounds, (float)click.x, (float)click.y);
}

int is_mouse_on_play(sfVector2i pos, menu_s *menu)
{
    return is_click_inside_text(menu->play_txt, pos);
}

int is_mouse_on_quit(sfVector2i pos, menu_s *menu)
{
    return is_click_inside_text(menu->quit_txt, pos);
}
