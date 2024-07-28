/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_last_quest
*/

#include "update.h"

static void display_last_quest(npc_t *n, rpg_t *rpg, sfEvent *event)
{
    if (rpg->lang == ENGLISH)
        tuto_quest_eng(n, rpg, event, "ggwp");
    else
        tuto_quest(n, rpg, event, "ggwp");
    rpg->game_finished = true;
}

static void launch_last_quest(npc_t *n, rpg_t *rpg, sfEvent *event)
{
    if (rpg->game_finished)
        return;
    for (npc_t *current = n; current; current = current->next) {
        if (strcmp(current->name, "sensei") == 0) {
            display_last_quest(current, rpg, event);
            break;
        }
    }
}

void update_last_quest(npc_t *n, rpg_t *rpg, sfEvent *event)
{
    sfVector2f pos = rpg->player.object.position;

    if (pos.x <= 400 && pos.x >= 342 && pos.y <= 324 && pos.y >= 301)
        launch_last_quest(n, rpg, event);
}
