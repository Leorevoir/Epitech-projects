/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** init_arena
*/

#include "core.h"

unsigned char *init_arena(void)
{
    unsigned char *arena = (unsigned char *)malloc(sizeof(char) * MEM_SIZE);

    if (arena == NULL)
        return NULL;
    my_memset(arena, '0', MEM_SIZE);
    return arena;
}

void init_starting_pos(war_t *war, champ_t *head)
{
    champ_t *current = head;
    int spacing = 0;

    while (current != NULL) {
        spacing = MEM_SIZE / war->num_champ;
        current->starting_pos = (current->id - 1) * spacing;
        current->pc = current->starting_pos;
        current = current->next;
    }
}
