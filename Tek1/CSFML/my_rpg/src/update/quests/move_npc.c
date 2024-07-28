/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** move_npc
*/

#include "update.h"

static void move_skeletton(npc_t *sklt, rpg_t *rpg)
{
    switch (rpg->player.quest) {
        case MOVE3:
            move_npc(sklt, (sfVector2f){581, 358}, PLAYER_SPEED - 0.2, rpg);
            break;
        case MOVE4:
            move_npc_to_player(sklt, rpg, -1);
            break;
        default:
            break;
    }
}

static void handle_skeletton_things(npc_t *sklt, rpg_t *rpg)
{
    move_skeletton(sklt, rpg);
    if (sklt->hp > 0) {
        if (rpg->player.quest == MOVE4)
            handle_sklt_attack(sklt, rpg);
        handle_sklt_respons(sklt, rpg);
    }
    if (sklt->hp <= 0) {
        sklt->is_alive = false;
        rpg->player.quest++;
    }
}

void check_quest_status(rpg_t *rpg, sfEvent *event)
{
    for (npc_t *current = rpg->npc;
        current != NULL; current = current->next) {
        if (strcmp(current->name, "sensei") == 0)
            move_npc_sensei(current, rpg, event);
        if (strcmp(current->name, "sklt") == 0 && current->is_alive)
            handle_skeletton_things(current, rpg);
        if (strcmp(current->name, "hunter") == 0) {
            move_npc_hunter(current, rpg);
        }
    }
}
