/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** move_hunter
*/

#include "update.h"

void change_npc_map(npc_t *n, int map, sfVector2f v2, int d)
{
    n->map = map;
    n->object.position = v2;
    sfSprite_setTexture(n->object.sprite, n->texture[d], sfFalse);
    sfSprite_setPosition(n->object.sprite, n->object.position);
}

static void modify_my_npc_texture(npc_t *n, rpg_t *rpg, int d)
{
    n->frame = 0;
    n->rect = (sfIntRect){0, 0, 16, 16};
    n->was_detected = false;
    rpg->player.quest++;
    sfSprite_setTexture(n->object.sprite, n->texture[d], 0);
    sfSprite_setTextureRect(n->object.sprite, n->rect);
}

static void make_it_jump(npc_t *n, rpg_t *rpg, bool v)
{
    sfTime dt = sfClock_getElapsedTime(n->hit_clock);
    float elapsed = sfTime_asSeconds(dt);

    if (rpg->inventory.has_spear && v) {
        modify_my_npc_texture(n, rpg, IDLE_LEFT);
        return;
    }
    if (elapsed >= 0.2f) {
        n->frame = (n->frame + 1) % 4;
        n->rect.left = n->frame * 16;
        n->rect.top = 0;
        n->rect.width = 16;
        n->rect.height = 16;
        sfClock_restart(n->hit_clock);
    }
    sfSprite_setTextureRect(n->object.sprite, n->rect);
}

void move_hunter_is_in_boss(npc_t *hunter, rpg_t *rpg)
{
    switch (rpg->player.quest) {
        case HUNTER_MOVE5:
            move_npc(hunter, (sfVector2f){154, -20}, HUNTER_SPEED, rpg);
            break;
        case HUNTER_MOVE6:
            change_npc_map(hunter, 3, (sfVector2f){238, 315}, IDLE_DOWN);
            break;
        case HUNTER_MOVE7:
            move_npc(hunter, (sfVector2f){247.85, 103.52}, HUNTER_SPEED, rpg);
            break;
        case 43:
            move_npc(hunter, (sfVector2f){239, 383}, HUNTER_SPEED, rpg);
            break;
        case 44:
            change_npc_map(
                hunter, 2, (sfVector2f){386.32, 297.80}, IDLE_DOWN);
            break;
        default:
            break;
    }
}

void move_hunter_to_boss(npc_t *hunter, rpg_t *rpg)
{
    switch (rpg->player.quest) {
        case HUNTER_MOVE:
            move_npc(hunter, (sfVector2f){688, 238}, HUNTER_SPEED, rpg);
            update_status_lvl3(rpg);
            break;
        case HUNTER_MOVE2:
            move_npc(hunter, (sfVector2f){645, 97}, HUNTER_SPEED + 1, rpg);
            break;
        case HUNTER_MOVE3:
            move_npc(hunter, (sfVector2f){489, 57}, HUNTER_SPEED + 1, rpg);
            break;
        case HUNTER_MOVE4:
            move_npc(hunter, (sfVector2f){154, 18}, HUNTER_SPEED, rpg);
            break;
        default:
            move_hunter_is_in_boss(hunter, rpg);
            break;
    }
}

static void move_hunter_to_spear(npc_t *hunter, rpg_t *rpg)
{
    switch (rpg->player.quest) {
        case MOVE_HUNTER7:
            move_npc(hunter, (sfVector2f){650.80, 323.98}, HUNTER_SPEED, rpg);
            break;
        case MOVE_HUNTER8:
            move_npc(hunter, (sfVector2f){607.26, 270.21}, HUNTER_SPEED, rpg);
            break;
        case MOVE_HUNTER9:
            modify_my_npc_texture(hunter, rpg, ATCK_DOWN);
            break;
        case HUNTER_JUMP:
            make_it_jump(hunter, rpg, true);
            break;
        default:
            move_hunter_to_boss(hunter, rpg);
            break;
    }
}

static void move_npc_hunter_in_road_map(npc_t *hunter, rpg_t *rpg)
{
    switch (rpg->player.quest) {
        case MOVE_HUNTER3:
            move_npc(hunter, (sfVector2f){76, 276}, HUNTER_SPEED, rpg);
            break;
        case MOVE_HUNTER5:
            move_npc(hunter, (sfVector2f){192, 389}, HUNTER_SPEED, rpg);
            break;
        case MOVE_HUNTER6:
            move_npc(hunter, (sfVector2f){523, 379}, HUNTER_SPEED, rpg);
            break;
        default:
            move_hunter_to_spear(hunter, rpg);
            break;
    }
}

void change_title_quest(rpg_t *rpg)
{
    rpg->text->picture.texture = sfTexture_createFromFile(
        HUNTER_PICTURE, NULL);
    sfSprite_setTexture(rpg->text->picture.sprite,
        rpg->text->picture.texture, sfTrue);
    sfText_setString(rpg->text->validate, "X");
    sfText_setColor(rpg->text->validate, sfRed);
}

void move_npc_hunter(npc_t *hunter, rpg_t *rpg)
{
    switch (rpg->player.quest) {
        case MOVE_HUNTER1:
            move_npc(hunter, (sfVector2f){580, 299}, HUNTER_SPEED, rpg);
            change_title_quest(rpg);
            break;
        case MOVE_HUNTER2:
            change_npc_map(hunter, 0, (sfVector2f){68.91, 373.69}, IDLE_LEFT);
            break;
        default:
            move_npc_hunter_in_road_map(hunter, rpg);
            break;
    }
}
