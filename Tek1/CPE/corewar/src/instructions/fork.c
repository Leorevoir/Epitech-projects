/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** fork
*/

#include "core.h"

static champ_t *dup_champ(war_t *war, champ_t *current, int pos)
{
    champ_t *new = add_champ(war->head, current->header, current->id,
        current->inst);

    new->fork = true;
    new->alive = current->alive;
    new->starting_pos = pos;
    new->pc = new->pc + pos % IDX_MOD;
}

int my_ffork(champ_t *champ, int i, war_t *war)
{
    int pos = FORK;
    champ_t *duped_champ = NULL;

    duped_champ = dup_champ(war, champ, pos);
    war->head = duped_champ;
    return (i + T_DIR) % MEM_SIZE;
}
