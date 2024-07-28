/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_movement
*/

#include "update.h"

static float adjust_speed_for_diagonal(float speed, bool horizontal,
    bool vertical)
{
    if (horizontal && vertical)
        return speed / sqrtf(2);
    return speed;
}

static void player_z(rpg_t *rpg, float speed, bool double_dir)
{
    sfVector2f next_position = rpg->player.object.position;

    next_position.y -= speed + (atoi(GET_STRING(CMD_INV.agility->text)) / 10);
    if (!check_collision(rpg, 'u')) {
        rpg->player.object.position = next_position;
        rpg->player.has_moved = true;
        rpg->player.state = WALKING;
        rpg->player.last_direction = WAS_UP;
        sfSprite_setTexture(rpg->player.object.sprite,
            rpg->player.textures[WALK_UP], sfTrue);
    } else if (!double_dir) {
        sfSprite_setTexture(rpg->player.object.sprite,
            rpg->player.textures[IDLE_UP], sfTrue);
        rpg->player.state = IDLE;
    }
}

static void player_s(rpg_t *rpg, float speed,
    bool double_dir)
{
    sfVector2f next_position = rpg->player.object.position;

    next_position.y += speed + (atoi(GET_STRING(CMD_INV.agility->text)) / 10);
    if (!check_collision(rpg, 'd')) {
        rpg->player.object.position = next_position;
        rpg->player.has_moved = true;
        rpg->player.state = WALKING;
        rpg->player.last_direction = WAS_DOWN;
        sfSprite_setTexture(rpg->player.object.sprite,
            rpg->player.textures[WALK_DOWN], sfTrue);
    } else if (!double_dir) {
        sfSprite_setTexture(rpg->player.object.sprite,
            rpg->player.textures[IDLE_DOWN], sfTrue);
        rpg->player.state = IDLE;
    }
}

static void player_q(rpg_t *rpg, float speed,
    bool double_dir)
{
    sfVector2f next_position = rpg->player.object.position;

    next_position.x -= speed + (atoi(GET_STRING(CMD_INV.agility->text)) / 10);
    if (!check_collision(rpg, 'l')) {
        rpg->player.object.position = next_position;
        rpg->player.has_moved = true;
        rpg->player.state = WALKING;
        rpg->player.last_direction = WAS_LEFT;
        sfSprite_setTexture(rpg->player.object.sprite,
            rpg->player.textures[WALK_LEFT], sfTrue);
    } else if (!double_dir) {
        sfSprite_setTexture(rpg->player.object.sprite,
            rpg->player.textures[IDLE_LEFT], sfTrue);
        rpg->player.state = IDLE;
    }
}

static void player_d(rpg_t *rpg, float speed,
    bool double_dir)
{
    sfVector2f next_position = rpg->player.object.position;

    next_position.x += speed + (atoi(GET_STRING(CMD_INV.agility->text)) / 10);
    if (!check_collision(rpg, 'r')) {
        rpg->player.object.position = next_position;
        rpg->player.has_moved = true;
        rpg->player.state = WALKING;
        rpg->player.last_direction = WAS_RIGHT;
        sfSprite_setTexture(rpg->player.object.sprite,
            rpg->player.textures[WALK_RIGHT], sfTrue);
    } else if (!double_dir) {
        sfSprite_setTexture(rpg->player.object.sprite,
            rpg->player.textures[IDLE_RIGHT], sfTrue);
        rpg->player.state = IDLE;
    }
}

static void handle_idle2(rpg_t *rpg)
{
    switch (rpg->player.last_direction) {
        case WAS_LEFT:
            sfSprite_setTexture(rpg->player.object.sprite,
                rpg->player.textures[IDLE_LEFT], sfTrue);
            rpg->player.state = IDLE;
            break;
        case WAS_RIGHT:
            sfSprite_setTexture(rpg->player.object.sprite,
                rpg->player.textures[IDLE_RIGHT], sfTrue);
            rpg->player.state = IDLE;
            break;
        default:
            break;
    }
}

static void handle_idle(rpg_t *rpg, bool moved)
{
    if (!moved) {
        switch (rpg->player.last_direction) {
            case WAS_UP:
                sfSprite_setTexture(rpg->player.object.sprite,
                    rpg->player.textures[IDLE_UP], sfTrue);
                rpg->player.state = IDLE;
                break;
            case WAS_DOWN:
                sfSprite_setTexture(rpg->player.object.sprite,
                    rpg->player.textures[IDLE_DOWN], sfTrue);
                rpg->player.state = IDLE;
                break;
            default:
                handle_idle2(rpg);
        }
    }
}

static void move_player(rpg_t *rpg, bool move_h, bool move_v)
{
    float speed = adjust_speed_for_diagonal(rpg->player.speed.y,
        move_h, move_v);

    if (KEY_PRESSED(sfKeyZ) || KEY_PRESSED(sfKeyUp)) {
        player_z(rpg, speed, move_h);
    }
    if (KEY_PRESSED(sfKeyS) || KEY_PRESSED(sfKeyDown))
        player_s(rpg, speed, move_h);
    if (KEY_PRESSED(sfKeyQ) || KEY_PRESSED(sfKeyLeft))
        player_q(rpg, speed, move_v);
    if (KEY_PRESSED(sfKeyD) || KEY_PRESSED(sfKeyRight))
        player_d(rpg, speed, move_v);
    handle_idle(rpg, move_h || move_v);
}

void handle_keyboard_input(rpg_t *rpg)
{
    bool move_h = false;
    bool move_v = false;

    if (rpg->player.state == IS_DEAD)
        return;
    if (KEY_PRESSED(sfKeyZ) || KEY_PRESSED(sfKeyS)
    || KEY_PRESSED(sfKeyUp) || KEY_PRESSED(sfKeyDown))
        move_v = true;
    if (KEY_PRESSED(sfKeyQ) || KEY_PRESSED(sfKeyD)
    || KEY_PRESSED(sfKeyLeft) || KEY_PRESSED(sfKeyRight))
        move_h = true;
    move_player(rpg, move_h, move_v);
}
