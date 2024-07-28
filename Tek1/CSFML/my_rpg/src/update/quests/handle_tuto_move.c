/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** handle_tuto_move
*/

#include "update.h"

static void one_more_quest_for_sensei(npc_t *s, rpg_t *rpg)
{
    switch (rpg->player.quest) {
        case WAKE_UP:
            sfSprite_setTexture(s->object.sprite, s->texture[IDLE_RIGHT], 0);
            break;
        case 44:
            change_npc_map(s, 2, (sfVector2f){346.32, 297.80}, IDLE_DOWN);
            break;
        default:
            break;
    }
}

static void move_npc_to_other_quest(npc_t *s, rpg_t *rpg)
{
    switch (rpg->player.quest) {
        case VILLAGE:
            s->map = 1;
            s->object.position = (sfVector2f){330.31, 509.51};
            sfSprite_setPosition(s->object.sprite,
                s->object.position);
            break;
        case VILLAGE2:
            move_npc(s, (sfVector2f){385.45, 484.41}, 1.0, rpg);
            break;
        case VILLAGE3:
            move_npc(s, (sfVector2f){361.04, 418.84}, 1.0, rpg);
            break;
        case VILLAGE4:
            move_npc(s, (sfVector2f){352.37, 296.39}, 1.0, rpg);
            break;
        default:
            one_more_quest_for_sensei(s, rpg);
            break;
    }
}

static void omg_better_smooth_move(npc_t *s, rpg_t *rpg)
{
    switch (rpg->player.quest) {
        case MOVE8:
            move_npc(s, (sfVector2f){84, 419},
                PLAYER_SPEED + 0.2, rpg);
            break;
        case MOVE9:
            move_npc(s, (sfVector2f){39, 366},
                PLAYER_SPEED + 0.2, rpg);
            break;
        case MOVE10:
            move_npc(s, (sfVector2f){-16, 366},
                PLAYER_SPEED + 0.2, rpg);
            break;
        default:
            move_npc_to_other_quest(s, rpg);
            break;
    }
}

static void omg_very_smooth_move(npc_t *s, rpg_t *rpg)
{
    switch (rpg->player.quest) {
        case MOVE6:
            if (s->object.position.x >= 392)
                move_npc(s, (sfVector2f){392, 387}, PLAYER_SPEED + 0.2, rpg);
            else
                rpg->player.quest = MOVE7;
            break;
        case MOVE7:
            move_npc(s, (sfVector2f){178, 397},
                PLAYER_SPEED + 0.2, rpg);
            break;
        default:
            omg_better_smooth_move(s, rpg);
            break;
    }
}

void more_move_npc_sensei(npc_t *s, rpg_t *rpg, sfEvent *event)
{
    switch (rpg->player.quest) {
        case TUTO4:
            if (rpg->lang == ENGLISH)
                tuto_quest_eng(s, rpg, event, "tuto4");
            else
                tuto_quest(s, rpg, event, "tuto4");
            update_status_lvl2(rpg);
            break;
        default:
            omg_very_smooth_move(s, rpg);
            break;
    }
}

void move_npc_sensei(npc_t *s, rpg_t *rpg, sfEvent *event)
{
    switch (rpg->player.quest) {
        case MOVE1:
            move_npc(s, (sfVector2f){339, 387}, PLAYER_SPEED, rpg);
            break;
        case MOVE2:
            move_npc(s, (sfVector2f){539, 387}, PLAYER_SPEED + 0.2, rpg);
            break;
        case MOVE5:
            move_npc_to_player(s, rpg, 1);
            break;
        default:
            more_move_npc_sensei(s, rpg, event);
            break;
    }
}
