/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update
*/

#include "tools.h"

#ifndef UPDATE_H_
    #define UPDATE_H_

void update_view(rpg_t *rpg);
void animate_smoke(boss_t *boss);
void update_cinema(rpg_t *rpg);
void update_last_cinema(rpg_t *rpg);
void save_progression(rpg_t *rpg);
void handle_save_escape_menu(hud_t *hud, rpg_t *rpg, sfVector2i mouse);
void update_angry_boss_attacks(boss_t *boss, rpg_t *rpg);
void angry_boss_animations(boss_t *boss, sfClock *clock, rpg_t *rpg);
void handle_mouse_input(rpg_t *rpg, sfTimeSpan time_span);
void update_ui(ui_t *ui, rpg_t *rpg);
void change_npc_map(npc_t *n, int map, sfVector2f v2, int d);
void handle_keyboard_input(rpg_t *rpg);
void update_menu(hud_t *hud, rpg_t *rpg);
void update_rpg(rpg_t *rpg, sfEvent *event, sfTimeSpan time_span);
void hit_cooldown(sfClock *clock, npc_t *npc);
void handle_sklt_respons(npc_t *s, rpg_t *rpg);
void switch_weapon_pos(npc_t *s, direction_t d);
void update_rocket_animation(boss_t *boss);
void update_angry_boss_frame(
    boss_t *boss, sfClock *clock, int max, bool is_hit);
void update_last_quest(npc_t *n, rpg_t *rpg, sfEvent *event);
void boss_is_angry(boss_t *boss, sfClock *clock, rpg_t *rpg);
void update_settings_hud(hud_t *hud, rpg_t *rpg);
void update_player_choose(hud_t *hud, rpg_t *rpg);
void update_boss_life(boss_t *boss, rpg_t *rpg);
void update_smoke(boss_t *boss, sfClock *clock);
void move_npc_hunter(npc_t *hunter, rpg_t *rpg);
void handle_sklt_attack(npc_t *sklt, rpg_t *rpg);
void check_quest_status(rpg_t *rpg, sfEvent *event);
void check_npc_proximity(rpg_t *rpg, sfEvent *event);
void update_boss(boss_t *boss, sfClock *clock, rpg_t *rpg);
void update_text_box(tmp_txt_t *tmp, rpg_t *rpg, npc_t *npc);
void sensei_quests(npc_t *sensei, rpg_t *rpg, sfEvent *event);
void hunter_quests(npc_t *hunter, rpg_t *rpg, sfEvent *event);
void move_npc_sensei(npc_t *sensei, rpg_t *rpg, sfEvent *event);
void tuto_quest(
    npc_t *sensei, rpg_t *rpg, sfEvent *event, const char *str);
void update_attack(inventory_t *inv, boss_t *boss, int num);
void move_npc(npc_t *npc, sfVector2f t, float speed, rpg_t *rpg);
void what_quest_do_you_have(npc_t *current, rpg_t *rpg, sfEvent *event);
void display_my_quest(npc_t *npc, rpg_t *rpg, sfEvent *e, dialogue_t *c);
sfVector2i convert_mouse_vertex(
    sfRenderWindow *window, rpg_t *rpg, const sfView *view);
void update_boss_frame(boss_t *boss, sfClock *clock, int num, bool is_hit);
sfVector2i convert_mouse_position(sfRenderWindow *window, sfVector2i m);
void update_inventory(rpg_t *rpg);
void update_status_lvl2(rpg_t *rpg);
void update_status_lvl3(rpg_t *rpg);
void handle_attack_down_sword(rpg_t *rpg, sfVector2f pos);
void handle_attack_up_sword(rpg_t *rpg, sfVector2f pos);
void handle_attack_left_sword(rpg_t *rpg, sfVector2f pos);
void handle_attack_right_sword(rpg_t *rpg, sfVector2f pos);
void handle_attack_down_spear(rpg_t *rpg, sfVector2f pos);
void handle_attack_up_spear(rpg_t *rpg, sfVector2f pos);
void handle_attack_left_spear(rpg_t *rpg, sfVector2f pos);
void handle_attack_right_spear(rpg_t *rpg, sfVector2f pos);
void hover_new(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg);
void hov_seting(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg);
void hover_exit(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg);
void hover_load(menu_t *menu, sfVector2i m, sfFloatRect pos, rpg_t *rpg);
void update_escape_menu(hud_t *hud, rpg_t *rpg);
void update_music(rpg_t *rpg, hud_t *hud);
void checkup_music(rpg_t *rpg, hud_t *hud);
void update_window(rpg_t *rpg, settings_t *sett);

#endif /* !UPDATE_H_ */
