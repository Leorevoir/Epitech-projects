/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** hunter_quests
*/

#include "update.h"
#include "display.h"

void heal_sound(rpg_t *rpg)
{
    sfMusic_stop(rpg->music.village);
    sfMusic_setLoop(rpg->music.menu, sfTrue);
    sfMusic_play(rpg->music.heal_sound);
}

static void final_hunter_quest(npc_t *hunter, rpg_t *rpg, sfEvent *event)
{
    switch (rpg->player.quest) {
        case 42:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(hunter, rpg, event, "end_boss");
            else
                tuto_quest(hunter, rpg, event, "end_boss");
            sfText_setString(rpg->text->validate, "V");
            sfText_setColor(rpg->text->validate, sfGreen);
            break;
        default:
            break;
    }
}

static void more_hunter_quests_road(npc_t *hunter, rpg_t *rpg, sfEvent *event)
{
    switch (rpg->player.quest) {
        case HUNTER_QUEST2:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(hunter, rpg, event, "okletsgo");
            else
                tuto_quest(hunter, rpg, event, "okletsgo");
            break;
        case HUNTER_QUEST3:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(hunter, rpg, event, "start_boss");
            else
                tuto_quest(hunter, rpg, event, "start_boss");
            break;
        default:
            final_hunter_quest(hunter, rpg, event);
            break;
    }
}

static void hunter_quests_road(npc_t *hunter, rpg_t *rpg, sfEvent *event)
{
    switch (rpg->player.quest) {
        case MOVE_HUNTER4:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(hunter, rpg, event, "mid2");
            else
                tuto_quest(hunter, rpg, event, "mid2");
            break;
        case HUNTER_QUEST:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(hunter, rpg, event, "omgqqc");
            else
                tuto_quest(hunter, rpg, event, "omgqqc");
            break;
        default:
            more_hunter_quests_road(hunter, rpg, event);
            break;
    }
}

void hunter_quests(npc_t *hunter, rpg_t *rpg, sfEvent *event)
{
    switch (rpg->player.quest) {
        case WAKE_UP:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(hunter, rpg, event, "wake_up");
            else
                tuto_quest(hunter, rpg, event, "wake_up");
            heal_sound(rpg);
            rpg->player.hp = 100;
            break;
        case MOVE_HUNTER2:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(hunter, rpg, event, "mid");
            else
                tuto_quest(hunter, rpg, event, "mid");
            break;
        default:
            hunter_quests_road(hunter, rpg, event);
            break;
    }
}
