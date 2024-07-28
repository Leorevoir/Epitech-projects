/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** lfork
*/

#include "core.h"

static champ_t *dup_champ_lfork(war_t *war, champ_t *current, int pos)
{
    champ_t *new = add_champ(war->head, current->header, current->id,
        current->inst);

    new->fork = true;
    new->starting_pos = pos;
    new->alive = current->alive;
    new->pc = new->pc + pos;
}

int my_lfork(champ_t *champ, int i, war_t *war)
{
    int pos = FORK;
    champ_t *duped_champ = NULL;

    duped_champ = dup_champ_lfork(war, champ, pos);
    war->head = duped_champ;
    return (i + T_DIR) % MEM_SIZE;
}
