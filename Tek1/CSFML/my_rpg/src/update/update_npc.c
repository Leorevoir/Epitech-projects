/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_npc
*/

#include "update.h"

/// @brief convert current map to int
/// @param rpg
/// @return 0 = road, 1 = village !rebuilt, 2 = village rebuilt, 3 = boss
int get_map_id(rpg_t *rpg)
{
    if (rpg->background == &(rpg->maps.map_road))
        return 0;
    if (rpg->background == &(rpg->maps.map_village) && !rpg->rebuilt)
        return 1;
    if (rpg->background == &(rpg->maps.map_village) && rpg->rebuilt)
        return 2;
    if (rpg->background == &(rpg->maps.map_boss))
        return 3;
    return -1;
}

void check_npc_proximity(rpg_t *rpg, sfEvent *event)
{
    int id = get_map_id(rpg);
    float distance = 0.0f;
    npc_t *current = NULL;
    sfVector2f player_pos = {0};

    if (id == -1) {
        fprintf(stderr, "ERROR:\tcheck_npc_proximity\n\tid == -1\n");
        return;
    }
    current = rpg->npc;
    player_pos = rpg->player.object.position;
    while (current != NULL) {
        distance = calculate_distance(current->object.position, player_pos);
        if (distance <= PROXIMITY_THRESHOLD && id == current->map
            && !current->was_detected) {
            what_quest_do_you_have(current, rpg, event);
            break;
        }
        current = current->next;
    }
}
