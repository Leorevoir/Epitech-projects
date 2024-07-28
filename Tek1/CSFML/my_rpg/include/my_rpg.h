/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** my_rpg
*/

//------------ libc library ------------//
    #include <time.h>
    #include <math.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <sys/types.h>
//------------ SFML library ------------//
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Network.h>
    #include <SFML/Graphics.h>
//------------my library------------//
    #include "text.h"
    #include "menu.h"
    #include "boss.h"
    #include "enum.h"
    #include "stats.h"
    #include "tiles.h"
    #include "macro.h"
    #include "macro_menu.h"
    #include "object.h"
    #include "weather.h"

#ifndef MY_RPG_H_
    #define MY_RPG_H_

//_________STRUCTURES________________//

////////// STRUCT MAPS ////////////////
typedef struct maps_s {
    object_t map_road;
    object_t map_village;
    object_t map_boss;
    sfImage *current;
    sfImage *map_road_collision;
    sfImage *map_village_collision;
    sfImage *map_boss_collision;
    char *name_curr;
} maps_t;

////////// STRUCT WEAPONS /////////////
typedef struct weapon_s {
    object_t object;
    sfIntRect rect;
    bool equippied;
    bool show;
} weapon_t;

////////// STRUCT INVENTORY ///////////
typedef struct inventory_s {
    object_t inventory;
    object_t quests;
    object_t inventaire;
    object_t quetes;
    object_t curr_weapon;
    sfVertexArray *button;
    sfTransform transform_btn;
    sfRenderStates states_btn;
    weapon_t sword;
    weapon_t spear;
    object_t sword_obj;
    object_t spear_obj;
    object_t pp;
    text_t *name;
    text_t *level;
    text_t *strength;
    text_t *agility;
    text_t *constitution;
    text_t *intelligence;
    bool show_quest;
    bool show;
    bool has_sword;
    bool has_spear;
} inventory_t;

////////// STRUCT PLAYER //////////////
typedef struct character_s {
    object_t object;
    sfTexture *textures[COUNT];
    sfVector2f speed;
    sfIntRect rect;
    int frame;
    direction_t direction;
    last_direction_t last_direction;
    state_t state;
    bool has_moved;
    bool is_button_pressed;
    float xp;
    float hp;
    int lvl;
    int quest;
    sfClock *hit_clock;
} character_t;

////////// STRUCT TEMP NPC //////////////
typedef struct tmp_npc_s {
    object_t object;
    sfVector2f pos;
    int map;
} tmp_npc_t;

////////// LIST NPC //////////////
typedef struct npc_s {
    char *name;
    sfTexture **texture;
    object_t object;
    object_t picture;
    object_t weapon;
    bool show_weapon;
    bool is_alive;
    bool hit;
    bool can_hit;
    bool was_detected;
    bool animation;
    int map;
    sfClock *move_clock;
    sfClock *hit_clock;
    sfTime hit_time_limit;
    sfIntRect rect;
    int frame;
    float hp;
    last_direction_t last_direction;
    struct npc_s *next;
} npc_t;

////////// STRUCT UI //////////////////
typedef struct ui_s {
    object_t text_box;
    object_t arrow;
    object_t hp;
    sfClock *clock;
    bool display;
} ui_t;

typedef struct tool_s {
    int who;
    bool menu;
} tool_t;

////////// STRUCT RPG /////////////////
typedef struct music_s {
    sfMusic *menu;
    sfMusic *village;
    sfMusic *road;
    sfMusic *boss;
    sfMusic *win;
    sfMusic *lose;
    sfMusic *swing_sound;
    sfMusic *heal_sound;
    float volume_menu;
    float volume_village;
    float volume_road;
    float volume_boss;
    float volume_win;
    float volume_lose;
    float volume_swing;
    float volume_heal;
    float c_volume_menu;
    float c_volume_village;
    float c_volume_road;
    float c_volume_boss;
    float c_volume_swing;
    float c_volume_heal;
    float c_volume_win;
    float c_volume_lose;
    bool music;
    bool sound;
} music_t;

////////// STRUCT DEATH ///////////////
typedef struct death_s {
    sfText *youre_dead;
    sfText *try_again;
} death_t;

////////// STRUCT RPG /////////////////
typedef struct rpg_s {
    sfRenderWindow *window;
    int resolution;
    object_t *background;
    maps_t maps;
    character_t player;
    inventory_t inventory;
    sfView *view;
    sfClock *clock;
    npc_t *npc;
    dialogue_t *dialogue;
    dialogue_t *dialogue_eng;
    text_t *text;
    sfText *lvl_up;
    boss_t *boss;
    ui_t *ui;
    weather_t *weather;
    tool_t tool;
    music_t music;
    death_t death;
    bool disp_lvl_up;
    bool lang;
    bool rebuilt;
    bool cinema;
    bool last_cinema;
    bool game_finished;
    float volume;
} rpg_t;

//_________FUNCTIONS_________________//

////////// FUNCTIONS INIT /////////////
void init_ui(rpg_t *rpg);
void init_maps(rpg_t *rpg);
void init_npc(rpg_t *rpg);
void init_boss(rpg_t *rpg);
void init_text(rpg_t *rpg);
void init_player(rpg_t *rpg);
void init_window(rpg_t *rpg);
void init_weapon(rpg_t *rpg);
void init_inventory(rpg_t *rpg, stats_t **stats);
void init_players(hud_t *hud);
void init_menu(hud_t **hud, rpg_t *rpg);
int init_chat_box(dialogue_t *head, rpg_t *rpg, char *conf);
int init_chat_box_eng(dialogue_t *head, rpg_t *rpg, char *conf);
void init_character_choose(hud_t **hud, rpg_t *rpg);
int init_rpg(rpg_t *rpg, tile_t **head, hud_t **hud, stats_t **stats);
object_t init_object(const char *path_texture, sfVector2f position);
void init_settings_hud(hud_t **hud, rpg_t *rpg);
void init_all_res(settings_t **sett, sfVector2f pos);
sfSprite *init_sprite(sfTexture **t, sfVector2f scale, char *path);
void init_position(sfSprite **s, sfVector2f pos, sfVector2f orig, sfText **t);
void init_text_res(sfText **t, char *str, settings_t *sett, sfVector2f origin);
void init_music_settings(settings_t *sett, sfVector2f pos);
int my_rpg(rpg_t *rpg, tile_t *head, hud_t *hud, stats_t *stats);
void init_escape_menu(hud_t **hud, rpg_t *rpg);
void init_music(rpg_t *rpg);

////////// FUNCTIONS DESTROY //////////
void destroy_menu(hud_t *hud);
void destroy_all_npcs(npc_t **head);
void destroy_object(object_t *obj);
void destroy_window(sfRenderWindow *window);
void destroy_rpg(rpg_t *rpg, tile_t *tiles, hud_t *hud, stats_t *stats);
void destroy_player(character_t player);
void destroy_maps(maps_t maps);
void destroy_ui(ui_t *ui);
void destroy_all_boss(boss_t *boss);
void destroy_text(text_t *text);
void destroy_all_dialogues(dialogue_t *head);
void destroy_tiles(tile_t *head);
void destroy_inventory(inventory_t inventory, rpg_t *rpg);
void destroy_player_choose(characters_t *chars);
void destroy_settings_hud(settings_t *sett);
void destroy_music(rpg_t *rpg);

////////// FUNCTIONS EVENT ////////////
void load_progression(rpg_t *rpg);
void handle_save(rpg_t *rpg, sfEvent *event);
bool check_collision(rpg_t *rpg, char diredction);
void key_pressed_event(rpg_t *rpg, sfEvent *event, hud_t *hud);
void handle_events(rpg_t *rpg, sfEvent *event, hud_t *hud);
void update_resolution(settings_t *sett, rpg_t *rpg);
void tuto_quest_eng(
    npc_t *sensei, rpg_t *rpg, sfEvent *event, const char *str);
void update_musical(settings_t *sett, rpg_t *rpg);
void update_music(rpg_t *rpg, hud_t *hud);
int loading_screen_esc(rpg_t *rpg, hud_t *hud);

////////// FUNCTIONS VERTEX ///////////
sfFloatRect get_vertex_bounds(sfVertexArray *vertex_array);
void set_vertex_color(sfVertexArray* vertexArray, sfColor color);
sfVertexArray* create_vertex(float width, float height, float radius);
sfBool is_in_vertex(rpg_t *rpg);

//---------- ne pas enlever cette fonctions svp ----------//
static inline void show_xy(character_t *character)
{
    static int first = 1;
    static sfClock *clock;
    sfTime elapsed;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 0.2) {
        printf("x: %.2f y: %.2f\r", character->object.position.x,
            character->object.position.y);
        fflush(stdout);
        sfClock_restart(clock);
    }
}

#endif /* !MY_RPG_H_ */
