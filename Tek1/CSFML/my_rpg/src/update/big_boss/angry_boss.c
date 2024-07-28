/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** angry_boss
*/

#include "update.h"

void update_angry_boss_attacks(boss_t *boss, rpg_t *rpg)
{
    sfTime dt = sfClock_getElapsedTime(rpg->player.hit_clock);
    float dt_s = sfTime_asSeconds(dt);
    sfVector2f p = rpg->player.object.position;

    if (p.y >= 125 && p.y <= 172 && p.x >= 243 && p.x <= 255
        && dt_s > 0.5 && boss->fx.display_rocket) {
        rpg->player.hp -= 10 - atoi(GET_STRING(CMD_INV.constitution->text));
        sfClock_restart(rpg->player.hit_clock);
    }
}

static void update_rect_and_positions(fx_t *fx, boss_t *boss)
{
    sfSprite_setPosition(fx->red1.sprite, fx->red1.position);
    sfSprite_setPosition(fx->red2.sprite, fx->red2.position);
    sfSprite_setTextureRect(fx->red1.sprite, fx->rect1);
    sfSprite_setTextureRect(fx->red2.sprite, fx->rect1);
    sfSprite_setTextureRect(fx->rocket.sprite, fx->rect);
    sfSprite_setTextureRect(boss->object.sprite, boss->rect);
}

static void update_angry_boss_life(
    boss_t *boss, __attribute__((unused))rpg_t *rpg)
{
    if (boss->life <= 0) {
        boss->alive = false;
    }
}

void boss_is_angry(boss_t *boss, sfClock *clock, rpg_t *rpg)
{
    update_attack(&(rpg->inventory), rpg->boss, 3);
    angry_boss_animations(boss, clock, rpg);
    update_rect_and_positions(&(boss->fx), boss);
    update_angry_boss_life(boss, rpg);
}
