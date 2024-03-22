/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** radar
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#ifndef RADAR_H_
    #define RADAR_H_
    #define WAITING 0
    #define FLYING 1
    #define EXPLOSION 2
    #define LANDED 3
    #define BOOM 4
    #define LETSGO 0
    #define STATUS_HELP 1
    #define STATUS_ERROR 2
    #define PLANE_SIZE 20

typedef struct plane_s plane_t;
typedef struct tower_s tower_t;

struct plane_s {
    sfVector2f pos;
    sfVector2f velocity;
    float distance;
    float delay;
    int status;
    plane_t *next;
};

struct tower_s {
    sfVector2f pos;
    float radius;
    tower_t *next;
};

typedef struct {
    plane_t *planes;
    tower_t *towers;
    sfRenderWindow *window;
    sfTexture *world_texture;
    sfSprite *world_sprite;
    sfSprite *plane_sprite;
    sfTexture *plane_texture;
    sfRectangleShape *plane_hitbox;
    sfTexture *tower_texture;
    sfSprite *tower_sprite;
    sfCircleShape *tower_radius;
    int planes_landed;
    int planes_exploded;
    int value;
    int show_sprites;
    int show_hitboxes;
    float timer;
    sfText *timer_value;
    sfText *timer_text;
    sfText *stats_landed;
    sfText *landed_text;
    sfText *exploded_text;
    sfText *stats_exploded;
    sfFont *timer_font;
} radar_t;

void radar_help(void);
int my_strlen(char *str);
void my_putstr(char *str);
char *my_revstr(char *str);
char *number_to_string(int nb);
int is_number(char const *string);
char *add_char(char *str, char c);
unsigned int str_to_int(char const *string);
int my_strcmp(char const *s1, char const *s2);
int plane_collides(plane_t *plane, plane_t *other);
plane_t *plane_create(sfVector2f position, sfVector2f velocity,
    float distance, float delay);
void tower_prepend(tower_t **list, tower_t *tower);
char *my_strndup(char const *string, unsigned long n);
int parse_tower(radar_t *radar, char **words, unsigned long count);
void plane_prepend(plane_t **list, plane_t *plane);
int parse_plane(radar_t *radar, char **words, unsigned long count);
void draw_planes(radar_t *radar);
void draw_towers(radar_t *radar);
void radar_destroy(radar_t *radar);
void destroy_sprite(radar_t *radar);
void plane_destroy(plane_t *plane);
void tower_destroy(tower_t *tower);
void create_plane(radar_t *radar);
void radar_create(radar_t *radar);
void radar_create_stats_text(radar_t *radar);
void radar_create_text(radar_t *radar);
void create_tower(radar_t *radar);
tower_t *tower_create(sfVector2f position, float radius_percentage);
void update_planes(radar_t *radar, float delta);
void radar_update(radar_t *radar, float delta);
void update_collisions_and_status(radar_t *radar);
void update_planes_status(radar_t *radar);
int is_inside(tower_t *tower, sfVector2f position);
int tower_collides(tower_t *tower, plane_t *plane);
int is_safe(radar_t *radar, plane_t *plane);
sfTexture *load_texture(radar_t *radar, char *path);
void radar_load_resources(radar_t *radar);
void parse_event(radar_t *radar, sfEvent *event);
void radar_event(radar_t *radar, sfEvent *event);
void draw_timer(radar_t *radar);
void radar_draw(radar_t *radar);
void radar_loop(radar_t *radar);
void my_radar(radar_t *radar, int argc, char **argv);
void radar_run(radar_t *radar);
void radar_usage(void);
void handle_help_option(radar_t *radar);
void process_script_line(radar_t *radar, char *line);
void load_script(radar_t *radar, char *path);
void handle_invalid_args(radar_t *radar);
void radar_parse_arguments(radar_t *radar, int argc, char **argv);
int parse_line(radar_t *radar, char **words, unsigned long count);
void radar_initialize(radar_t *radar);
char **my_split(char const *string);
unsigned long my_split_length(char **array);
void my_free_split(char **array);
unsigned long get_count(char const *string);
char *get_next(char const **string);
void detect_collisions(radar_t *radar);
void detect_collision(radar_t *radar, plane_t *plane,
    plane_t *other);

#endif /* !RADAR_H_ */
