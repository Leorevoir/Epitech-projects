/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** event
*/

#include "game.h"

#ifndef EVENT_H_
    #define EVENT_H_

/* mouse event */
void handle_tool_actions(game_t *game);
void button_inactive(game_t *game, const char *str);
void check_button_click(game_t *game, sfVector2f click);
void handle_mouse_button_event(game_t *game, sfEvent event);
void update_mouse_position(game_t *game);
void button_released(game_t *game, sfEvent event, button_t *btn);

/* menu */
bool is_click_outside_menu(sfRenderWindow *window, menu_t menu);
void handle_color_selection(game_t *game, sfMouseButtonEvent event);

/* color events */
void peinture(game_t *game);
void handle_color(game_t *game, sfVector2f click);

/* key event */
void handle_key_press_event(game_t *game, sfEvent event);

/* form event */
void handle_form_event(game_t *game, sfEvent event);
void handle_trait_events(game_t *game, sfEvent event);
void handle_square_events(game_t *game, sfEvent event);
void handle_circle_events(game_t *game, sfEvent event);
void handle_help_events(game_t *game, sfEvent event);
void handle_about_events(game_t *game, sfEvent event);

/* save event */
void handle_ctrl_s(game_t *game);
void check_return(game_t *game, sfEvent event);
void handle_ctrl_o(game_t *game, sfEvent event);
void handle_saving_events(game_t *game, sfEvent event);
void handle_opening_events(game_t *game, sfEvent event);
void handle_text_input(char *filename, sfUint32 unicode, size_t max_length);

#endif /* !EVENT_H_ */
