/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** what_quest
*/

#include "update.h"
#include "display.h"

void display_my_quest(npc_t *npc, rpg_t *rpg, sfEvent *e, dialogue_t *c)
{
    rpg->text->txt_to_print = strdup(c->text);
    display_text(rpg->text, rpg, npc, e);
    free(rpg->text->txt_to_print);
}

void what_quest_do_you_have(npc_t *current, rpg_t *rpg, sfEvent *event)
{
    if (strcmp(current->name, "hunter") == 0)
        hunter_quests(current, rpg, event);
    if (strcmp(current->name, "sensei") == 0)
        sensei_quests(current, rpg, event);
}
