/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** tools
*/

#include "my_rpg.h"

#ifndef TOOLS_H_
    #define TOOLS_H_

//---------------------------------------------//
// fonctions static inline pour l'IA des NPCs //
// demander à Léo avant de toucher svp !!!! //
//----------------------------------------//

void move_npc(npc_t *npc, sfVector2f t, float speed, rpg_t *rpg);

////////// TEMP SAVE/LOAD MAPS ////////////////
typedef struct temp_load_s {
    sfVector2f pos;
    sfVector2f v;
    sfVector2f se;
    sfVector2f sk;
    sfVector2f ht;
    float hp;
    int q;
    int r;
    int m;
    int w;
    int ska;
    int sw;
    int sp;
    int sem;
    int hm;
    int au;
    int ni;
    int la;
}t_t;

static inline void update_position(npc_t *npc, sfVector2f t, float r)
{
    npc->object.position.x += (t.x - npc->object.position.x) * r;
    npc->object.position.y += (t.y - npc->object.position.y) * r;
}

static inline void set_npc_texture(npc_t *npc, direction_t direction)
{
    sfSprite_setTexture(npc->object.sprite, npc->texture[direction], 0);
}

static inline direction_t get_direction(sfVector2f current, sfVector2f t)
{
    if (fabs(t.x - current.x) > fabs(t.y - current.y))
        return (t.x > current.x) ? WALK_RIGHT : WALK_LEFT;
    else
        return (t.y > current.y) ? WALK_DOWN : WALK_UP;
}

static inline float calculate_distance(sfVector2f pos1, sfVector2f pos2)
{
    return hypotf(pos2.x - pos1.x, pos2.y - pos1.y);
}

static inline sfVector2f restrict_view_center(
    sfVector2f c, sfVector2f v, int w, int h)
{
    float min_x = v.x / 2.0f;
    float max_x = w - min_x;
    float min_y = v.y / 2.0f;
    float max_y = h - min_y;

    if (c.x < min_x)
        c.x = min_x;
    else if (c.x > max_x)
        c.x = max_x;
    if (c.y < min_y)
        c.y = min_y;
    else if (c.y > max_y)
        c.y = max_y;
    return c;
}

static inline void move_npc_to_player(npc_t *npc, rpg_t *rpg, int i)
{
    float distance_to_player = DISTANCE(npc->object.position.x,
        npc->object.position.y, rpg->player.object.position.x,
        rpg->player.object.position.y);

    if (npc->hp > 0 && distance_to_player > MIN_DISTANCE) {
        move_npc(npc, (sfVector2f){
        rpg->player.object.position.x,
        rpg->player.object.position.y}, PLAYER_SPEED - 0.2, rpg);
    }
    if (i == 1 && distance_to_player <= PROXIMITY_THRESHOLD) {
        rpg->player.quest++;
        return;
    }
}

#endif /* !TOOLS_H_ */
