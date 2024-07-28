/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** print_info
*/

#include "core.h"

static champ_t *get_next_champ(war_t *war, champ_t *current, int *index)
{
    champ_t *champ = current;

    for (int i = 0; i < *index; i++) {
        champ = champ->next ? champ->next : war->head;
    }
    *index = (*index + 1) % war->num_champ;
    return champ;
}

static void print_champ_life(champ_t *champ)
{
    my_printf(COLOR_RESET COLOR_BOLD"\t%s\t", champ->header.prog_name);
    switch (champ->alive) {
        case 0:
            my_printf(COLOR_RED"■"COLOR_RESET);
            break;
        case 1:
            my_printf(COLOR_GREEN"■"COLOR_RESET);
            break;
        case 2:
            my_printf(COLOR_YELLOW"■"COLOR_RESET);
            break;
        default:
            break;
    }
}

void print_info(war_t *war, const char *color)
{
    static bool done = false;
    champ_t *current = war->head;
    int count = 0;

    my_printf(COLOR_RESET COLOR_BOLD "|%s", color);
    while (current != NULL) {
        if (current->fork) {
            current = current->next;
            continue;
        }
        print_champ_life(current);
        count++;
        if (count >= war->num_champ) {
            break;
        }
        current = current->next;
    }
    my_printf(COLOR_BOLD"\n|%s%s", COLOR_RESET, color);
    war->done = true;
}
