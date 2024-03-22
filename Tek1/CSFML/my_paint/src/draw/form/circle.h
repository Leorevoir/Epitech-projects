/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** circle
*/

#include "game.h"

#ifndef CIRCLE_H_
    #define CIRCLE_H_

typedef struct index_s {
    int x;
    int y;
    int i;
    int j;
} index_t;

void draw_pixel_in_buffer(game_t *game, int x, int y);
void draw_circle_in_buffer(game_t *game, circle_t *circle);

#endif /* !CIRCLE_H_ */
