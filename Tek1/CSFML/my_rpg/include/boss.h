/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** boss
*/

#ifndef BOSS_H_
    #define BOSS_H_

    #include "object.h"
    #include "macro.h"

////////// STRUCT BOSS /////////////////
typedef struct fx_s {
    object_t thunder;
    object_t rocket;
    object_t smoke1;
    object_t smoke2;
    object_t smoke3;
    object_t smoke4;
    object_t red1;
    object_t red2;
    sfIntRect rect;
    sfIntRect rect1;
    sfIntRect rect2;
    int frame;
    int frame1;
    int frame2;
    bool display_smoke;
    bool display_rocket;
    bool display_red;
    bool display_thunder;
    sfClock *clock;
    sfClock *move1;
    sfClock *move2;
    sfClock *move3;
    sfClock *move4;
    sfClock *red1_clock;
    sfClock *red2_clock;
    sfClock *clock1;
} fx_t;

////////// STRUCT BOSS /////////////////
typedef struct boss_s {
    object_t object;
    fx_t fx;
    sfTexture *textures[4];
    sfIntRect rect;
    float life;
    int frame;
    sfClock *clock;
    sfClock *hit_clock;
    sfClock *flame_clock;
    bool alive;
    bool hit;
    bool angry;
} boss_t;

#endif /* !BOSS_H_ */
