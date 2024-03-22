/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** init_window
*/

#include "init.h"

void init_window(sfRenderWindow **window)
{
    sfVideoMode video_mode = {HEIGHT, WIDTH, 32};

    *window = sfRenderWindow_create(video_mode, "my_paint",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(*window, 60);
}
