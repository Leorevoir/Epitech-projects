/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** trait
*/

#include "game.h"

#ifndef TRAIT_H_
    #define TRAIT_H_

typedef struct {
    int dx;
    int dy;
    int x;
    int y;
} line_t;

void draw_pixel_in_buffer(game_t *game, int x, int y);

#endif /* !TRAIT_H_ */
