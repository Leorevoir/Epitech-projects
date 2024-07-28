/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_boss
*/

#include "my_rpg.h"

static void init_boss_basics(rpg_t *rpg)
{
    rpg->boss->fx.rect2 = (sfIntRect){0, 0, 20, 28};
    rpg->boss->fx.frame2 = 0;
    rpg->boss->frame = 0;
    rpg->boss->life = 70;
    rpg->boss->rect = (sfIntRect){0, 0, 16, 16};
    rpg->boss->clock = sfClock_create();
    rpg->boss->hit_clock = sfClock_create();
    rpg->boss->alive = false;
    rpg->boss->hit = false;
    rpg->boss->angry = false;
    rpg->boss->fx.red1_clock = sfClock_create();
    rpg->boss->fx.red2_clock = sfClock_create();
    rpg->boss->flame_clock = sfClock_create();
    rpg->boss->fx.thunder = init_object(THUNDER, (sfVector2f){247, 80});
    rpg->boss->fx.rect2 = (sfIntRect){0, 0, 16, 16};
    rpg->boss->fx.display_thunder = false;
}

static void init_boss_fx(rpg_t *rpg)
{
    rpg->boss->fx.rocket = init_object(ROCKET, (sfVector2f){187, 64});
    rpg->boss->fx.smoke1 = init_object(SMOKE, (sfVector2f){150, 116});
    rpg->boss->fx.smoke2 = init_object(SMOKE, (sfVector2f){150, 215});
    rpg->boss->fx.smoke3 = init_object(SMOKE, (sfVector2f){320, 116});
    rpg->boss->fx.smoke4 = init_object(SMOKE, (sfVector2f){320, 215});
    rpg->boss->fx.red1 = init_object(RED_SMALL1, (sfVector2f){222, 117});
    rpg->boss->fx.red2 = init_object(RED_SMALL1, (sfVector2f){273, 117});
    rpg->boss->fx.display_smoke = false;
    rpg->boss->fx.rect = (sfIntRect){0, 0, 16, 16};
    rpg->boss->fx.rect1 = (sfIntRect){0, 0, 16, 16};
    rpg->boss->fx.frame = 0;
    rpg->boss->fx.clock = sfClock_create();
    rpg->boss->fx.move1 = sfClock_create();
    rpg->boss->fx.move2 = sfClock_create();
    rpg->boss->fx.move3 = sfClock_create();
    rpg->boss->fx.move4 = sfClock_create();
    rpg->boss->fx.display_rocket = false;
    rpg->boss->fx.display_red = false;
}

void init_boss(rpg_t *rpg)
{
    sfVector2f pos = {231, 91};

    rpg->boss = NULL;
    rpg->boss = (boss_t *)malloc(sizeof(boss_t));
    rpg->boss->textures[0] = sfTexture_createFromFile(WHITE_THING_FIRE, NULL);
    rpg->boss->textures[1] = sfTexture_createFromFile(
        WHITE_THING_FIRE_HIT, NULL);
    rpg->boss->textures[2] = sfTexture_createFromFile(RED_THING_FIRE, NULL);
    rpg->boss->textures[3] = sfTexture_createFromFile(
        RED_THING_FIRE_HIT, NULL);
    rpg->boss->object = init_object(WHITE_THING_FIRE, pos);
    rpg->boss->fx.clock1 = sfClock_create();
    init_boss_basics(rpg);
    init_boss_fx(rpg);
}
