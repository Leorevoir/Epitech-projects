/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** free
*/

#include "core.h"

static void free_register_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; i < REG_NUMBER + 2; i++) {
        free(array[i]);
    }
    free(array);
}

static void free_everything(champ_t *current)
{
    if (current->inst != NULL)
        free(current->inst);
    if (current->tab)
        free_word_array(current->tab);
    if (current->reg)
        free_register_array(current->reg);
}

void free_war(war_t *war)
{
    champ_t *current = war->head;
    champ_t *next = NULL;

    while (current != NULL && current->fork != true) {
        if (current->fork != true)
            free_everything(current);
        free(current);
        current = current->next;
    }
    free(war->arena);
    free(war);
}
