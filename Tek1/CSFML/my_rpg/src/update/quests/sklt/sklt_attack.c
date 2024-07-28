/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** move_sklt
*/

#include "update.h"

static bool check_if_weapon_hit_player(npc_t *s, rpg_t *rpg)
{
    sfFloatRect weapon = sfSprite_getGlobalBounds(s->weapon.sprite);
    sfFloatRect target = sfSprite_getGlobalBounds(rpg->player.object.sprite);

    if (sfFloatRect_intersects(&weapon, &target, NULL) && s->show_weapon)
        return true;
    return false;
}

void start_attack_cooldown(npc_t *npc)
{
    npc->can_hit = false;
    sfClock_restart(npc->hit_clock);
}

void handle_sklt_respons(npc_t *s, rpg_t *rpg)
{
    float distance_to_player = DISTANCE(s->object.position.x,
        s->object.position.y, rpg->player.object.position.x,
        rpg->player.object.position.y);
    direction_t attack_direction;

    hit_cooldown(rpg->boss->hit_clock, s);
    if (distance_to_player <= MIN_DISTANCE && s->can_hit) {
        s->animation = false;
        attack_direction = (direction_t)((s->last_direction % 4) + 8);
        s->rect = (sfIntRect){0, 0, 16, 16};
        s->frame = 0;
        sfSprite_setTexture(s->object.sprite, s->texture[attack_direction], 0);
        sfSprite_setTextureRect(s->object.sprite, s->rect);
        switch_weapon_pos(s, attack_direction);
        if (check_if_weapon_hit_player(s, rpg)) {
            rpg->player.hp -= 2;
            hit_cooldown(rpg->boss->hit_clock, s);
            start_attack_cooldown(s);
        }
    }
}

static void clock_hit_time(npc_t *sklt)
{
    sfTime elapsed = {0};

    if (sklt->hit) {
        elapsed = sfClock_getElapsedTime(sklt->hit_clock);
        if (sfTime_asSeconds(elapsed) >= sfTime_asSeconds(
            sklt->hit_time_limit)) {
            sklt->hit = false;
            sfSprite_setColor(sklt->object.sprite, sfWhite);
            sfClock_restart(sklt->hit_clock);
        }
    }
}

void handle_sklt_attack(npc_t *sklt, rpg_t *rpg)
{
    sfFloatRect sword = sfSprite_getGlobalBounds(
        rpg->inventory.sword.object.sprite);
    sfFloatRect spear = sfSprite_getGlobalBounds(
        rpg->inventory.spear.object.sprite);
    sfFloatRect enemy = sfSprite_getGlobalBounds(sklt->object.sprite);
    sfColor red = sfColor_fromRGBA(255, 0, 0, 255);

    if ((sfFloatRect_intersects(&sword, &enemy, NULL) && !sklt->hit
    && rpg->inventory.sword.show) || (rpg->inventory.spear.show
    && sfFloatRect_intersects(&spear, &enemy, NULL) && !sklt->hit)) {
        sklt->hit = true;
        sklt->frame = 0;
        sklt->rect.left = 0;
        sfSprite_setColor(sklt->object.sprite, red);
        sfSprite_setTextureRect(sklt->object.sprite, sklt->rect);
        sklt->hp -= atoi(sfText_getString(CMD_INV.strength->text));
        sfClock_restart(sklt->hit_clock);
    }
    clock_hit_time(sklt);
}
