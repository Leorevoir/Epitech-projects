/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_object
*/

#include "my_rpg.h"

object_t init_object(const char *path_texture, sfVector2f position)
{
    object_t object;

    object.texture = sfTexture_createFromFile(path_texture, NULL);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    object.position = position;
    sfSprite_setPosition(object.sprite, object.position);
    return object;
}
