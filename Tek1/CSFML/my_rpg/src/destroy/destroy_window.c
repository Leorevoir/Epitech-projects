/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_window
*/

#include "my_rpg.h"

void destroy_window(sfRenderWindow *window)
{
    if (window != NULL)
        sfRenderWindow_destroy(window);
}
