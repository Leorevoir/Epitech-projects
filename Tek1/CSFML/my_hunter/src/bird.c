/*
** EPITECH PROJECT, 2023
** bird.c
** File description:
** Bird functions
*/

#include "../include/game.h"

sfSprite *initialize_sprite(void)
{
    sfTexture *texture = sfTexture_createFromFile("data/game/piaf.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

bird_s *initialize_bird(void)
{
    bird_s *bird = malloc(sizeof(bird_s));

    bird->sprite = initialize_sprite();
    bird->frame = (my_rect_s){0, 0, SPRITE_WIDTH, SPRITE_HEIGHT};
    bird->clock = sfClock_create();
    bird->position = (sfVector2f){0, 100};
    return bird;
}

void update_bird(bird_s *bird)
{
    int random_direction = rand() % 2 - 1;

    if (sfTime_asSeconds(sfClock_getElapsedTime(bird->clock)) > 0.2) {
        bird->frame.left += SPRITE_WIDTH;
        if (bird->frame.left >= SPRITE_WIDTH * FRAME_COUNT)
            bird->frame.left = 0;
        sfClock_restart(bird->clock);
    }
    bird->position.y += random_direction * 0.75;
    if (bird->position.y < 50)
        bird->position.y = 50;
    if (bird->position.y > 600)
        bird->position.y = 600;
    bird->position.x += 5;
    if (bird->position.x > 1280)
        bird->position.x = -SPRITE_WIDTH;
}

sfIntRect convert(my_rect_s rectgl)
{
    sfIntRect sfRect = {rectgl.left, rectgl.top, rectgl.width, rectgl.height};

    return sfRect;
}
