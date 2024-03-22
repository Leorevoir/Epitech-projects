/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** coordinates
*/

#ifndef COORDINATES_H_
    #define COORDINATES_H_

typedef struct {
    int x0;
    int y0;
    int x1;
    int y1;
} coordinates_t;

typedef struct last_coordinates_s {
    int last_x;
    int last_y;
} last_coordinates_t;

#endif /* !COORDINATES_H_ */
