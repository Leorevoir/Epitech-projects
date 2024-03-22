/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** algo
*/

#include "game.h"

#ifndef ALGO_H_
    #define ALGO_H_

typedef struct drawing_info_s {
    game_t *game;
    coordinates_t coords;
    sfColor color;
    float gradient;
    bool steep;
} drawing_info_t;

typedef struct wo_xi_huan_s {
    int x;
    int y;
    int dy;
    int dx;
} wo_xi_huan_t;

typedef struct {
    int x;
    int y;
} point_t;

float fpart(float x);
float rfpart(float x);
void my_swap(int *a, int *b);
void apply_anti_aliased_color(sfUint8 *pixel, sfColor color,
    float brightness);
void xiaolin_wu_plot(drawing_info_t *info, int x, int y,
    float brightness);
void apply_color_to_pixel(sfUint8 *pixels, int offset, sfColor color);
sfVector2f get_adjusted_position(const sfRenderWindow *window,
    sfVector2i pixel_pos);
bool is_position_inside_drawing_area(sfVector2f pos);
sfVector2f get_drawing_position(sfVector2f adjusted_pos,
    sfVector2f zone_pos);

#endif /* !ALGO_H_ */
