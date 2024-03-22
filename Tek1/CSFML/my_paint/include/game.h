/*
** EPITECH PROJECT, 2024
** paint
** File description:
** game
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "coordinates.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#ifndef GAME_H_
    #define GAME_H_
    #define HEIGHT 1920
    #define WIDTH 1080
    #define RECT_WIDTH 1152
    #define RECT_HEIGHT 648
    #define MOUSE sfMouse_getPositionRenderWindow
    #define BOUNDS sfSprite_getGlobalBounds
    #define BACKGROUND "data/background.png"
    #define BUTTONS "data/buttons.png"
    #define EDIT_PNG "data/edit.png"
    #define FILE_PNG "data/file.png"
    #define HELP_PNG "data/help.png"
    #define COLOR_PNG "data/color.png"
    #define SIZE_PNG "data/size.png"
    #define ABOUT_PNG "data/about.png"
    #define HELP_SLIDES "data/HELP/0.png"
    #define HELP_V game->help_png.is_visible
    #define SIZE_V game->size_png.is_visible
    #define EDIT_V game->edit_png.is_visible
    #define FILE_V game->file_png.is_visible
    #define NAME clicked_button->name[0]
    #define NAME0 current->name[0]

/////////////////////////////////////////////////
typedef struct game_s game_t;
/////////////////////////////////////////////////

typedef struct game_object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
} game_object_t;

/////////////////////////////////////////////////

typedef struct pencil_s {
    sfColor color;
    sfColor current;
    sfColor secondary_color;
    bool is_second;
    sfUint8 *pixels;
    int size;
} pencil_t;

/////////////////////////////////////////////////

typedef enum {
    PENCIL,
    ERASER,
    PIPETTE,
    PEINTURE,
    SQUARE,
    TRAIT,
    CIRCLE,
    ABOUT,
    HELP
} tool_type;

typedef struct {
    tool_type type;
    void (*use)(game_t *game);
    void (*select)(game_t *game);
} tool_t;

/////////////////////////////////////////////////

typedef enum {
    BUTTON_INACTIVE,
    BUTTON_ACTIVE,
    BUTTON_CLICKED,
    BUTTON_HOVERED
} button_state;

typedef struct button_s {
    sfRectangleShape *rect;
    char *name;
    sfVector2f pos;
    sfVector2f size;
    bool is_selected;
    button_state state;
    void (*action)(game_t *);
    struct button_s *next;
} button_t;

/////////////////////////////////////////////////

typedef struct square_s {
    sfRectangleShape *shape;
    sfVector2f start_point;
    sfVector2f end_point;
    struct square_s *next;
} square_t;

typedef struct circle_s {
    sfCircleShape *shape;
    sfVector2f center;
    float radius;
    struct circle_s *next;
} circle_t;

typedef struct trait_s {
    sfVector2f point_a;
    sfVector2f point_b;
    sfColor color;
    struct trait_s *next;
} trait_t;

/////////////////////////////////////////////////

typedef struct menu_s {
    bool is_visible;
    game_object_t menu_sprite;
} menu_t;

/////////////////////////////////////////////////

typedef struct file_s {
    bool is_saving;
    char save_filename[86];
    bool is_opening;
    char open_filename[86];
} file_t;

/////////////////////////////////////////////////

typedef struct game_s {
    sfRenderWindow *window;
    sfRectangleShape *drawing_rect;
    game_object_t background;
    game_object_t drawing_zone;
    game_object_t load_file;
    game_object_t about;
    game_object_t help;
    sfCircleShape *color_circle;
    sfCircleShape *second_circle;
    menu_t edit_png;
    menu_t help_png;
    menu_t file_png;
    menu_t color_png;
    menu_t size_png;
    pencil_t pencil;
    sfBool mouse_pressed;
    int create_pop;
    int slide;
    sfBool pop_about;
    sfBool pop_help;
    last_coordinates_t last_coords;
    button_t *buttons;
    tool_type selected_tool;
    file_t user_file;
    square_t *squares;
    circle_t *circles;
    trait_t *trait;
} game_t;

/////////////////////////////////////////////////
/* buttons */
char **get_buttons_data(void);
void display_buttons(game_t *game);
void create_buttons(button_t **button, char **buttons_data);

/* init paint */
void pencil(game_t *game);
void init_paint(game_t *game);
void create_drawing_rect(game_t *game);
sfCircleShape *create_circle(float radius, sfVector2f pos);
game_object_t create_object(const char *path, sfVector2f position);

/* event paint */
void my_error(const char *error);
void handle_events(game_t *game);
sfBool button_drawable(button_t *current, game_t *game);

/* display paint */
void display_paint(game_t *game);
void display_prompt(game_t *game, const char *message,
    const char *input, sfVector2f position);
void draw_trait_in_buffer(game_t *game, sfVector2f start, sfVector2f end,
    sfColor color);

/* destroy paint */
void destroy_paint(game_t *game);
void destroy_game_object(game_object_t *obj);

/* pencil fct */
void pencil_draw(game_t *game);
void what_color_did_user_picked(game_t *game);
void set_primary_or_secondary_color(game_t *game, sfColor custom);
void interpolate_and_apply_color(game_t *game, coordinates_t coords);

/* save draw */
void create_new_file(game_t *game);
void ensure_default_extension(char *filename);
bool ends_with(const char *str, const char *ext);
void ensure_default_extension(char *filename);
void open_drawing(game_t *game, const char *filename);
void save_drawing(const game_t *game, const char *filename);

/* popups */
void help_pop_up(game_t *game, sfEvent event);
void about_pop_up(game_t *game, sfEvent event);

#endif /* !GAME_H_ */
