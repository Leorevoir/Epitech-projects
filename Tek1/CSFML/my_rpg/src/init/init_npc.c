/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_npc
*/

#include "my_rpg.h"

static npc_t *stock_npc_to_list(const char *name, const char **paths,
    tmp_npc_t *tmp)
{
    npc_t *new_npc = malloc(sizeof(npc_t));

    if (!new_npc)
        return NULL;
    new_npc->name = strdup(name);
    new_npc->object = init_object(paths[IDLE_DOWN], tmp->pos);
    new_npc->texture = malloc(sizeof(sfTexture *) * COUNT);
    new_npc->is_alive = true;
    new_npc->was_detected = false;
    new_npc->map = tmp->map;
    new_npc->picture = tmp->object;
    new_npc->rect = (sfIntRect){0, 0, 16, 16};
    new_npc->frame = 0;
    new_npc->move_clock = sfClock_create();
    if (!new_npc->texture) {
        free(new_npc->name);
        free(new_npc);
        return NULL;
    }
    return new_npc;
}

static void init_npc_weapon(npc_t *new_npc, const char *name)
{
    if (strcmp(name, "sklt") == 0) {
        new_npc->weapon = init_object(BONE, (sfVector2f){0, 0});
    } else
        new_npc->weapon = (object_t){0};
    new_npc->show_weapon = false;
    new_npc->can_hit = true;
}

static npc_t *create_npc(const char *name, const char **paths, tmp_npc_t *tmp)
{
    npc_t *new_npc = stock_npc_to_list(name, paths, tmp);

    if (new_npc == NULL)
        return NULL;
    for (int i = 0; i < COUNT; i++) {
        if (paths[i] != NULL)
            new_npc->texture[i] = sfTexture_createFromFile(paths[i], NULL);
        else
            new_npc->texture[i] = NULL;
    }
    init_npc_weapon(new_npc, name);
    new_npc->hit_clock = sfClock_create();
    new_npc->hit_time_limit = sfSeconds(0.5);
    new_npc->hit = false;
    new_npc->last_direction = 0;
    new_npc->hp = 30;
    new_npc->next = NULL;
    new_npc->animation = false;
    return new_npc;
}

static void add_npc(npc_t **head, npc_t *new_npc)
{
    if (!head || !new_npc)
        return;
    new_npc->next = *head;
    *head = new_npc;
}

static tmp_npc_t *stock_npc_to_tmp(object_t object, sfVector2f pos, int map)
{
    tmp_npc_t *new_npc = malloc(sizeof(tmp_npc_t));

    if (!new_npc)
        return NULL;
    new_npc->object = object;
    new_npc->pos = pos;
    new_npc->map = map;
    return new_npc;
}

void init_hunter_npc(rpg_t *rpg)
{
    sfVector2f pos = {408, 285};
    int map = 1;
    const char *paths[COUNT] = {
        HUNTER_UP, HUNTER_DOWN, HUNTER_LEFT,
        HUNTER_RIGHT, HUNTER_I_UP, HUNTER_I_DOWN,
        HUNTER_I_LEFT, HUNTER_I_RIGHT, HUNTER_POINT, HUNTER_JUMPP, NULL, NULL
    };
    object_t picture = init_object(HUNTER_PICTURE, (sfVector2f){0, 0});
    npc_t *hunter = NULL;
    tmp_npc_t *tmp = stock_npc_to_tmp(picture, pos, map);

    sfSprite_scale(picture.sprite, (sfVector2f){3, 3});
    hunter = create_npc("hunter", paths, tmp);
    add_npc(&(rpg->npc), hunter);
    free(tmp);
}

void init_sensei_npc(rpg_t *rpg)
{
    sfVector2f pos = {175, 387};
    int map = 0;
    const char *paths[COUNT] = {
        SENSEI_UP, SENSEI_DOWN, SENSEI_LEFT,
        SENSEI_RIGHT, SENSEI_I_UP, SENSEI_I_DOWN,
        SENSEI_I_LEFT, SENSEI_I_RIGHT, NULL, NULL, NULL, NULL
    };
    object_t picture = init_object(SENSEI_PICTURE, (sfVector2f){0, 0});
    npc_t *sensei = NULL;
    tmp_npc_t *tmp = stock_npc_to_tmp(picture, pos, map);

    sfSprite_scale(picture.sprite, (sfVector2f){3, 3});
    sensei = create_npc("sensei", paths, tmp);
    add_npc(&(rpg->npc), sensei);
    free(tmp);
}

void init_sklt_npc(rpg_t *rpg)
{
    sfVector2f pos = {581, 399};
    int map = 0;
    const char *paths[COUNT] = {
        SKLT_UP, SKLT_DOWN, SKLT_LEFT, SKLT_RIGHT,
        SKLT_I_UP, SKLT_I_DOWN, SKLT_I_LEFT, SKLT_I_RIGHT,
        SKLT_ATTACK1, SKLT_ATTACK2, SKLT_ATTACK3, SKLT_ATTACK4,
        NULL
    };
    object_t picture = init_object(SKLT_PICTURE, (sfVector2f){0, 0});
    npc_t *sklt = NULL;
    tmp_npc_t *tmp = stock_npc_to_tmp(picture, pos, map);

    sfSprite_scale(picture.sprite, (sfVector2f){3, 3});
    sklt = create_npc("sklt", paths, tmp);
    add_npc(&(rpg->npc), sklt);
    free(tmp);
}

void init_npc(rpg_t *rpg)
{
    rpg->npc = NULL;
    init_hunter_npc(rpg);
    init_sensei_npc(rpg);
    init_sklt_npc(rpg);
}
