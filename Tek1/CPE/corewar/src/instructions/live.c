/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** live
*/

#include "core.h"

static void player_is_alive(unsigned int id, war_t *war)
{
    champ_t *champ = war->head;

    while (champ != NULL) {
        if (champ->id == id) {
            champ->alive = 1;
            my_printf("The player %d(%s) is alive\n", champ->id,
                champ->header.prog_name);
            war->last = id;
        }
        champ = champ->next;
    }
}

int my_live(champ_t *champ, int i, war_t *war)
{
    for (int j = i + 1; j < i + 5; j++) {
        if (j == i + T_DIR) {
            player_is_alive(war->arena[j], war);
        }
    }
    return (i + 5) % MEM_SIZE;
}
