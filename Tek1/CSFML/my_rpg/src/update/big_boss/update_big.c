/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_big
*/

#include "update.h"

        // printf("+---------------+\n");
        // printf("| boss was hit !\n");
        // printf("| hit:\t%.2f\n", hit);
        // printf("| boss hp:\t%.2f\n", boss->life);
        // printf("+---------------+\n");

void update_attack(inventory_t *inv, boss_t *boss, int num)
{
    sfFloatRect sword = sfSprite_getGlobalBounds(inv->sword.object.sprite);
    sfFloatRect spear = sfSprite_getGlobalBounds(inv->spear.object.sprite);
    sfFloatRect enemy = sfSprite_getGlobalBounds(boss->object.sprite);
    float hit = 5;

    if ((sfFloatRect_intersects(&sword, &enemy, NULL) && boss->hit == false
    && inv->sword.show)
    || (sfFloatRect_intersects(&spear, &enemy, NULL) && boss->hit == false
    && inv->spear.show)) {
        boss->hit = true;
        boss->frame = 0;
        boss->rect.left = 0;
        sfSprite_setTexture(boss->object.sprite, boss->textures[num], sfTrue);
        sfSprite_setTextureRect(boss->object.sprite, boss->rect);
        boss->life -= hit;
    }
}

static void update_smoke_hit2(rpg_t *rpg, boss_t *boss, sfFloatRect hitbox_p,
    bool *is_hit)
{
    sfFloatRect hitbox_s3 = sfSprite_getGlobalBounds(boss->fx.smoke3.sprite);
    sfFloatRect hitbox_s4 = sfSprite_getGlobalBounds(boss->fx.smoke4.sprite);

    if (sfFloatRect_intersects(&hitbox_p, &hitbox_s3, NULL)
        && !*is_hit) {
        rpg->player.hp -= 10 - atoi(GET_STRING(CMD_INV.constitution->text));
        *is_hit = true;
    }
    if (sfFloatRect_intersects(&hitbox_p, &hitbox_s4, NULL)
        && !*is_hit) {
        rpg->player.hp -= 10 - atoi(GET_STRING(CMD_INV.constitution->text));
        *is_hit = true;
    }
}

static void reset_hit_clock(rpg_t *rpg, bool *is_hit)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(
        rpg->player.hit_clock)) > 0.5) {
        *is_hit = false;
        sfClock_restart(rpg->player.hit_clock);
    }
}

void udpate_smoke_hit(rpg_t *rpg, boss_t *boss)
{
    sfFloatRect hitbox_p = sfSprite_getGlobalBounds(rpg->player.object.sprite);
    sfFloatRect hitbox_s1 = sfSprite_getGlobalBounds(boss->fx.smoke1.sprite);
    sfFloatRect hitbox_s2 = sfSprite_getGlobalBounds(boss->fx.smoke2.sprite);
    static bool is_hit = false;

    if (sfFloatRect_intersects(&hitbox_p, &hitbox_s1, NULL)
        && !is_hit) {
        rpg->player.hp -= 10 - atoi(GET_STRING(CMD_INV.constitution->text));
        is_hit = true;
    }
    if (sfFloatRect_intersects(&hitbox_p, &hitbox_s2, NULL)
        && !is_hit) {
        rpg->player.hp -= 10 - atoi(GET_STRING(CMD_INV.constitution->text));
        is_hit = true;
    }
    update_smoke_hit2(rpg, boss, hitbox_p, &is_hit);
    if (is_hit)
        reset_hit_clock(rpg, &is_hit);
}

static void boss_not_so_angry(boss_t *boss, sfClock *clock, rpg_t *rpg)
{
    if (boss->fx.display_smoke) {
        animate_smoke(boss);
        udpate_smoke_hit(rpg, rpg->boss);
    }
    update_attack(&(rpg->inventory), rpg->boss, 1);
    sfSprite_setTextureRect(boss->fx.smoke1.sprite, boss->fx.rect);
    sfSprite_setTextureRect(boss->fx.smoke2.sprite, boss->fx.rect);
    sfSprite_setTextureRect(boss->fx.smoke3.sprite, boss->fx.rect);
    sfSprite_setTextureRect(boss->fx.smoke4.sprite, boss->fx.rect);
    if (boss->hit) {
        update_boss_frame(boss, boss->hit_clock, 3, true);
    } else
        update_boss_frame(boss, clock, 5, false);
    sfSprite_setTextureRect(boss->object.sprite, boss->rect);
    update_boss_life(boss, rpg);
}

void update_boss(boss_t *boss, sfClock *clock, rpg_t *rpg)
{
    if (!boss->angry)
        boss_not_so_angry(boss, clock, rpg);
    else
        boss_is_angry(boss, clock, rpg);
}
