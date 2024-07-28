/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** angry_boss_animations
*/

#include "update.h"

static void update_red_animation(boss_t *boss)
{
    sfTime time = sfClock_getElapsedTime(boss->fx.clock1);
    float elapsed = sfTime_asSeconds(time);

    if (elapsed >= 0.15f) {
        boss->fx.frame1 = (boss->fx.frame1 + 1) % 4;
        boss->fx.rect1.top = boss->fx.frame1 * 16;
        sfClock_restart(boss->fx.clock1);
    }
}

void update_red_position(
    object_t *red, float *dir_x, float *dir_y, sfClock *clock)
{
    sfTime dt = sfClock_getElapsedTime(clock);
    float elapsed = sfTime_asSeconds(dt);
    float speed = 3.0f;

    if (elapsed >= 0.1f) {
        red->position.x += *dir_x * speed;
        red->position.y += *dir_y * speed;
        if (red->position.x < 192.60 || red->position.x > 308.80)
            *dir_x *= -1;
        if (red->position.y < 87.706 || red->position.y > 144.50)
            *dir_y *= -1;
        sfClock_restart(clock);
    }
    sfSprite_setPosition(red->sprite, red->position);
}

void move_small_red(fx_t *fx)
{
    static float dir_x1 = 1.0f;
    static float dir_y1 = 1.0f;
    static float dir_x2 = 1.0f;
    static float dir_y2 = 1.0f;

    update_red_position(&(fx->red1), &dir_x1, &dir_y1, fx->red1_clock);
    update_red_position(&(fx->red2), &dir_x2, &dir_y2, fx->red2_clock);
}

static void start_reactivating_clock(sfClock *flame_clock, fx_t *fx)
{
    sfTime time = sfClock_getElapsedTime(flame_clock);
    float elapsed = sfTime_asSeconds(time);

    if (elapsed >= 4.0f) {
        fx->display_rocket = true;
        fx->frame = 0;
        fx->rect = (sfIntRect){0, 0, 150, 150};
        sfClock_restart(flame_clock);
    }
}

static void update_small_spirits_attacks(fx_t *fx, rpg_t *rpg)
{
    sfFloatRect f1 = sfSprite_getGlobalBounds(fx->red1.sprite);
    sfFloatRect f2 = sfSprite_getGlobalBounds(fx->red2.sprite);
    sfFloatRect target = sfSprite_getGlobalBounds(rpg->player.object.sprite);
    sfTime hit_time = sfClock_getElapsedTime(rpg->player.hit_clock);
    float elapsed_hit_time = sfTime_asSeconds(hit_time);

    if (sfFloatRect_intersects(&f1, &target, NULL)
    && elapsed_hit_time > 0.4f) {
        rpg->player.hp -= 10 - atoi(GET_STRING(CMD_INV.constitution->text));
        sfClock_restart(rpg->player.hit_clock);
    }
    if (sfFloatRect_intersects(&f2, &target, NULL)
    && elapsed_hit_time > 0.4f) {
        rpg->player.hp -= 10 - atoi(GET_STRING(CMD_INV.constitution->text));
        sfClock_restart(rpg->player.hit_clock);
    }
}

void angry_boss_animations(boss_t *boss, sfClock *clock, rpg_t *rpg)
{
    if (boss->hit) {
        update_angry_boss_frame(boss, clock, 3, true);
    } else
        update_angry_boss_frame(boss, clock, 5, false);
    if (boss->fx.display_rocket) {
        update_rocket_animation(boss);
        update_angry_boss_attacks(boss, rpg);
    } else
        start_reactivating_clock(boss->flame_clock, &(boss->fx));
    if (boss->fx.display_red) {
        update_red_animation(boss);
        move_small_red(&(boss->fx));
        update_small_spirits_attacks(&(boss->fx), rpg);
    }
}
