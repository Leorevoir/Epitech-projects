/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** object
*/

#ifndef OBJECT_H_
    #define OBJECT_H_

////////// STRUCT OBJECT //////////////
typedef struct object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
} object_t;

#endif /* !OBJECT_H_ */
