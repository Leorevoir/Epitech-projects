/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** square
*/

#include "game.h"

#ifndef SQUARE_H_
    #define SQUARE_H_

void finalize_drawing(game_t *game, square_t *current);
void draw_line_in_buffer(game_t *game, sfVector2f start,
    sfVector2f end);

#endif /* !SQUARE_H_ */
