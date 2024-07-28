/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** tools
*/

#include "update.h"

void hit_cooldown(sfClock *clock, npc_t *npc)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds >= 0.1) {
        sfClock_restart(clock);
        npc->can_hit = !npc->can_hit;
    }
}

static void update_npc_frame(npc_t *npc, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float elapsed = sfTime_asSeconds(time);

    if (elapsed >= 0.2f) {
        npc->frame = (npc->frame + 1) % 4;
        npc->rect.top = npc->frame * 16;
        sfClock_restart(clock);
    }
}

static void everything_back_to_normal(
    npc_t *npc, rpg_t *rpg, sfVector2f t, int i)
{
    npc->object.position = t;
    npc->rect = (sfIntRect){0, 0, 16, 16};
    npc->frame = 0;
    sfSprite_setTexture(npc->object.sprite, npc->texture[i], 0);
    sfSprite_setTextureRect(npc->object.sprite, npc->rect);
    rpg->player.quest++;
    npc->was_detected = false;
}

static void set_new_frame(npc_t *npc)
{
    if (npc->animation) {
        update_npc_frame(npc, npc->move_clock);
    } else {
        npc->rect = (sfIntRect){0, 0, 16, 16};
        npc->frame = 0;
    }
    sfSprite_setTextureRect(npc->object.sprite, npc->rect);
    sfSprite_setPosition(npc->object.sprite, npc->object.position);
}

static void update_npc_texture(npc_t *npc, sfVector2f t, float r)
{
    direction_t direction;

    update_position(npc, t, r);
    direction = get_direction(npc->object.position, t);
    set_npc_texture(npc, direction);
    npc->last_direction = (last_direction_t)direction;
}

void move_npc(npc_t *npc, sfVector2f t, float speed, rpg_t *rpg)
{
    float distance = DISTANCE(npc->object.position.x,
        npc->object.position.y, t.x, t.y);
    float r = 0.0f;
    direction_t idle_direction;

    npc->show_weapon = false;
    if (distance > speed) {
        npc->animation = true;
        r = CALCULATE_RATIO(speed, distance);
        update_npc_texture(npc, t, r);
    } else {
        npc->animation = false;
        idle_direction = IDLE_DIRECTION(npc->last_direction);
        everything_back_to_normal(npc, rpg, t, idle_direction);
        return;
    }
    set_new_frame(npc);
}
