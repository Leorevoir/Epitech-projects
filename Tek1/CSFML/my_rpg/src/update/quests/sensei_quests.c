/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** sensei_quests
*/

#include "update.h"

void tuto_quest_eng(
    npc_t *sensei, rpg_t *rpg, sfEvent *event, const char *str)
{
    dialogue_t *current = rpg->dialogue_eng;
    int quest_num = 0;

    while (current != NULL) {
        if (strcmp(sensei->name, current->name) == 0 &&
            strcmp(current->quest, str) == 0 &&
            current->num == quest_num) {
            display_my_quest(sensei, rpg, event, current);
            quest_num++;
            current = rpg->dialogue_eng;
            continue;
        }
        current = current->next;
    }
    sensei->was_detected = !sensei->was_detected;
    rpg->player.quest++;
}

void tuto_quest(
    npc_t *sensei, rpg_t *rpg, sfEvent *event, const char *str)
{
    dialogue_t *current = rpg->dialogue;
    int quest_num = 0;

    while (current != NULL) {
        if (strcmp(sensei->name, current->name) == 0 &&
            strcmp(current->quest, str) == 0 &&
            current->num == quest_num) {
            display_my_quest(sensei, rpg, event, current);
            quest_num++;
            current = rpg->dialogue;
            continue;
        }
        current = current->next;
    }
    sensei->was_detected = !sensei->was_detected;
    rpg->player.quest++;
}

void more_sensei_quests(npc_t *sensei, rpg_t *rpg, sfEvent *event)
{
    switch (rpg->player.quest) {
        case TUTO3:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(sensei, rpg, event, "tuto3");
            else
                tuto_quest(sensei, rpg, event, "tuto3");
            break;
        case VILLAGE:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(sensei, rpg, event, "village");
            else
                tuto_quest(sensei, rpg, event, "village");
            break;
        default:
            break;
    }
}

void sensei_quests(npc_t *sensei, rpg_t *rpg, sfEvent *event)
{
    sensei->was_detected = !sensei->was_detected;
    switch (rpg->player.quest) {
        case TUTO:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(sensei, rpg, event, "tuto");
            else
                tuto_quest(sensei, rpg, event, "tuto");
            break;
        case TUTO2:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(sensei, rpg, event, "tuto2");
            else
                tuto_quest(sensei, rpg, event, "tuto2");
            break;
        default:
            more_sensei_quests(sensei, rpg, event);
            break;
    }
}
