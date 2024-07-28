/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_object
*/

#include "my_rpg.h"

void destroy_object(object_t *obj)
{
    if (obj != NULL) {
        if (obj->sprite != NULL)
            sfSprite_destroy(obj->sprite);
        if (obj->texture != NULL)
            sfTexture_destroy(obj->texture);
    }
}
