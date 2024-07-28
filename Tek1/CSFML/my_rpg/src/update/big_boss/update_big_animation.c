/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_big_animation
*/

#include "update.h"

void update_angry_boss_frame(
    boss_t *boss, sfClock *clock, int max, bool is_hit)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float elapsed = sfTime_asSeconds(time);

    if (elapsed >= 0.2f) {
        boss->frame = (boss->frame + 1) % max;
        boss->rect.left = boss->frame * 50;
        boss->rect.top = 0;
        boss->rect.width = 50;
        boss->rect.height = 50;
        sfClock_restart(clock);
        if (is_hit && boss->frame == 0) {
            boss->hit = false;
            sfSprite_setTexture(
                boss->object.sprite, boss->textures[2], sfTrue);
        }
    }
}

void update_boss_frame(boss_t *boss, sfClock *clock, int num, bool is_hit)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float elapsed = sfTime_asSeconds(time);

    if (elapsed >= 0.2f) {
        boss->frame = (boss->frame + 1) % num;
        boss->rect.left = boss->frame * 50;
        boss->rect.top = 0;
        boss->rect.width = 50;
        boss->rect.height = 50;
        sfClock_restart(clock);
        if (is_hit && boss->frame == 0) {
            boss->hit = false;
            sfSprite_setTexture(
                boss->object.sprite, boss->textures[0], sfTrue);
        }
    }
}

void update_rocket_animation(boss_t *boss)
{
    sfTime time = sfClock_getElapsedTime(boss->fx.clock);
    float elapsed = sfTime_asSeconds(time);

    if (elapsed >= 0.1f) {
        boss->fx.frame = (boss->fx.frame + 1) % 25;
        boss->fx.rect.left = (boss->fx.frame % 5) * 150;
        boss->fx.rect.top = (boss->fx.frame / 5) * 150;
        boss->fx.rect.width = 150;
        boss->fx.rect.height = 150;
        sfClock_restart(boss->fx.clock);
        if (boss->fx.frame == 24) {
            boss->fx.display_rocket = false;
            sfClock_restart(boss->flame_clock);
        }
    }
}

static void switch_boss_to_angry(boss_t *boss, rpg_t *rpg)
{
    rpg->boss->fx.rect = (sfIntRect){0, 0, 150, 150};
    rpg->player.quest++;
    boss->angry = true;
    boss->hit = false;
    boss->alive = true;
    boss->fx.display_smoke = false;
    boss->life = 100;
    rpg->weather->night = true;
    sfSprite_setTexture(boss->object.sprite, boss->textures[2], false);
    rpg->boss->fx.display_rocket = true;
    boss->fx.display_red = true;
}

void update_boss_life(boss_t *boss, rpg_t *rpg)
{
    if (boss->life <= 0 && !boss->angry) {
        switch_boss_to_angry(boss, rpg);
    }
    if (boss->life <= 0 && boss->angry && boss->alive) {
        rpg->player.quest++;
        boss->alive = false;
        rpg->weather->night = false;
    }
}
