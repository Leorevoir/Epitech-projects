/*
** EPITECH PROJECT, 2023
** game h
** File description:
** game header
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>

#ifndef GAME_H_
    #define GAME_H_
    #define SPRITE_WIDTH 110
    #define SPRITE_HEIGHT 330
    #define FRAME_COUNT 3
    #define FONT_PATH "data/font.ttf"
    #define MAX_SCORE 20
    #define MOUSE sfEvtMouseButtonPressed
    #define WINDOW_ sfRenderWindow_create
    #define MY int
    #define MENU in_menu
    #define CHECK =
    #define GAME 1

typedef struct {
    sfSprite *sprite;
    sfText *play_txt;
    sfText *quit_txt;
    int is_play_hovered;
    int is_quit_hovered;
} menu_s;

typedef struct {
    int left;
    int top;
    int width;
    int height;
} my_rect_s;

typedef struct {
    sfRenderWindow *window;
    sfSprite *background;
    sfFont *font;
    int score;
    char score_text[10];
} game_window_s;

typedef struct {
    sfSprite *sprite;
    my_rect_s frame;
    sfClock *clock;
    sfVector2f position;
} bird_s;

extern int in_menu;
menu_s initialize_menu(void);
bird_s *initialize_bird(void);
void update_bird(bird_s *bird);
sfSprite *initialize_sprite(void);
char *my_itoa(int num, char *str);
sfIntRect convert(my_rect_s rectgl);
int is_left_mouse_click(sfEvent event);
game_window_s initialize_game_window(void);
char *my_strcpy(char *dest, char const *src);
void render(game_window_s *window, bird_s *bird);
int is_mouse_on_play(sfVector2i pos, menu_s *menu);
int is_mouse_on_quit(sfVector2i pos, menu_s *menu);
void render_menu(game_window_s *window, menu_s *menu);
void cleanup(game_window_s *game_window, bird_s *bird);
void handle_events(game_window_s *window, bird_s *bird);
int is_click_inside_text(sfText *text, sfVector2i click);
void handle_menu_events(game_window_s *window, menu_s *menu);
int process_menu_clicks(game_window_s *window, menu_s *menu, sfVector2i pos);
void process_left_click(game_window_s *window, bird_s *bird, sfVector2i pos);

#endif /* !GAME_H_ */
