/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** peinture
*/

#include "game.h"

#ifndef PEINTURE_H_
    #define PEINTURE_H_

typedef struct bucket_s {
    int *x;
    int *y;
    int front;
    int rear;
    int size;
} bucket_t;

typedef struct fill_s {
    int x;
    int y;
    sfColor target_color;
    sfColor fill_color;
} fill_t;

bucket_t *create_bucket(int size);
void free_bucket(bucket_t *bucket);
void enqueue_bucket(bucket_t *bucket, int x, int y);
void dequeue_bucket(bucket_t *bucket, int *x, int *y);
bool is_position_inside_drawing_area(sfVector2f pos);
sfVector2f get_drawing_position(sfVector2f adjusted_pos,
    sfVector2f zone_pos);

#endif /* !PEINTURE_H_ */
