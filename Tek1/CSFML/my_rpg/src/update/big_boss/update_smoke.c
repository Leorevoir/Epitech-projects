/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_smoke
*/

#include "my_rpg.h"

void update_smoke(boss_t *boss, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float elapsed = sfTime_asSeconds(time);

    if (elapsed >= 0.15f) {
        boss->fx.frame = (boss->fx.frame + 1) % 6;
        boss->fx.rect.left = boss->fx.frame * 32;
        boss->fx.rect.top = 0;
        boss->fx.rect.width = 32;
        boss->fx.rect.height = 32;
        sfClock_restart(clock);
    }
}

static void update_smoke_move(object_t *object, sfClock *clock, int num,
    float n)
{
    int random_direction = 0;

    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.2) {
        random_direction = rand() % 2;
        object->position.y += random_direction * n;
        object->position.x += num;
    }
    sfSprite_setPosition(object->sprite, object->position);
}

static void first_smoke_pattern(boss_t *boss, bool *done)
{
    if (boss->fx.smoke1.position.x < 360
        && boss->fx.smoke3.position.x > 120) {
        update_smoke_move(&(boss->fx.smoke1), boss->fx.move1, +1, 0.75);
        update_smoke_move(&(boss->fx.smoke2), boss->fx.move2, +1, -0.75);
        update_smoke_move(&(boss->fx.smoke4), boss->fx.move3, -1, -0.75);
        update_smoke_move(&(boss->fx.smoke3), boss->fx.move4, -1, 0.75);
    } else
        *done = true;
}

void update_second_animation(object_t *object, sfClock *clock)
{
    static int random_direction = 0;
    static float speedx = 1.0;
    static float speedy = 0.75f;

    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.2) {
        if (object->position.y <= 65)
            speedy = -speedy;
        if (object->position.x >= 350)
            speedx = -speedx;
        if (object->position.x <= 125)
            speedx = -speedx;
        if (object->position.y >= 250)
            speedy = -speedy;
        random_direction = rand() % 2;
        object->position.x += speedx;
        object->position.y += random_direction * speedy;
        sfSprite_setPosition(object->sprite, object->position);
    }
}

void update_second_animation2(object_t *object, sfClock *clock)
{
    static int random_direction = 0;
    static float speedx = -1.0;
    static float speedy = -0.75f;

    srand(time(NULL));
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.2) {
        if (object->position.x >= 350)
            speedx = -speedx;
        if (object->position.x <= 125)
            speedx = -speedx;
        if (object->position.y >= 250)
            speedy = -speedy;
        if (object->position.y <= 65)
            speedy = -speedy;
        random_direction = rand() % 2;
        object->position.x += speedx;
        object->position.y += random_direction * speedy;
        sfSprite_setPosition(object->sprite, object->position);
    }
}

void update_second_animation3(object_t *object, sfClock *clock)
{
    static int random_direction = 0;
    static float speedx = -1.0;
    static float speedy = 0.75f;

    srand(time(NULL));
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.2) {
        if (object->position.x >= 350)
            speedx = -speedx;
        if (object->position.x <= 125)
            speedx = -speedx;
        if (object->position.y >= 250)
            speedy = -speedy;
        if (object->position.y <= 65)
            speedy = -speedy;
        random_direction = rand() % 2;
        object->position.x += speedx;
        object->position.y += random_direction * speedy;
        sfSprite_setPosition(object->sprite, object->position);
    }
}

static void update_second_animation4(object_t *object, sfClock *clock)
{
    static int random_direction = 0;
    static float speedx = 1.0;
    static float speedy = -0.75f;

    srand(time(NULL));
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.2) {
        if (object->position.x >= 350)
            speedx = -speedx;
        if (object->position.x <= 125)
            speedx = -speedx;
        if (object->position.y >= 250)
            speedy = -speedy;
        if (object->position.y <= 65)
            speedy = -speedy;
        random_direction = rand() % 2;
        object->position.x += speedx;
        object->position.y += random_direction * speedy;
        sfSprite_setPosition(object->sprite, object->position);
    }
}

static void second_smoke_pattern(boss_t *boss)
{
    static bool done = false;

    if (!done) {
        boss->fx.smoke1.position = (sfVector2f){194, 66};
        boss->fx.smoke2.position = (sfVector2f){294, 66};
        boss->fx.smoke3.position = (sfVector2f){194, 242};
        boss->fx.smoke4.position = (sfVector2f){294, 242};
        done = true;
    } else {
        update_second_animation(&boss->fx.smoke1, boss->fx.move1);
        update_second_animation3(&boss->fx.smoke2, boss->fx.move2);
        update_second_animation2(&boss->fx.smoke3, boss->fx.move3);
        update_second_animation4(&boss->fx.smoke4, boss->fx.move4);
    }
}

void animate_smoke(boss_t *boss)
{
    static bool done = false;

    update_smoke(boss, boss->fx.clock);
    if (!done)
        first_smoke_pattern(boss, &done);
    if (done)
        second_smoke_pattern(boss);
}
