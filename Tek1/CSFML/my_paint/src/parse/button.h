/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** button
*/

#include "game.h"

#ifndef BUTTON_H_
    #define BUTTON_H_

typedef struct button_action_mapping_s {
    char *name;
    void (*action)(game_t *);
} button_action_mapping_t;

extern const button_action_mapping_t button_actions[];

void red(game_t *game);
void edit(game_t *game);
void gray(game_t *game);
void help(game_t *game);
void hhelp(game_t *game);
void about(game_t *game);
void black(game_t *game);
void lblue(game_t *game);
void sizepx(game_t *game);
void dblue(game_t *game);
void green(game_t *game);
void px1(game_t *game);
void px3(game_t *game);
void px5(game_t *game);
void px8(game_t *game);
void d_red(game_t *game);
void yellow(game_t *game);
void orange(game_t *game);
void eraser(game_t *game);
void pink(game_t *game);
void yllw(game_t *game);
void beig(game_t *game);
void lgrn(game_t *game);
void llbl(game_t *game);
void bgbl(game_t *game);
void bgpl(game_t *game);
void magnta(game_t *game);
void white(game_t *game);
void lgray(game_t *game);
void lrng(game_t *game);
void color_png(game_t *game);
void open_ctrl(game_t *game);
void handle_ctrl_s(game_t *game);
void pipette(game_t *game);
void select_file(game_t *game);
void pencil(game_t *game);
void main_color(game_t *game);
void secnd(game_t *game);
void square(game_t *game);
void select_peinture(game_t *game);
void trait(game_t *game);
void circle(game_t *game);

#endif /* !BUTTON_H_ */
