/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** print_arena
*/

#include "core.h"

static char *find_name_by_id(champ_t *head, int id)
{
    champ_t *current = head;

    while (current != NULL) {
        if (current->id == id)
            return current->header.prog_name;
        current = current->next;
    }
    return NULL;
}

void my_delay(int milliseconds)
{
    volatile int i;
    volatile int j;

    for (i = 0; i < milliseconds * 10000; i++) {
        j = i * i;
    }
}

static void print_winner(war_t *war, champ_t *head)
{
    if (war->last != 0) {
        my_printf(COLOR_BOLD COLOR_YELLOW);
        my_printf("                             ___________\n\t\t\t");
        my_printf("    '._==_==_=_.'\n\t\t\t    .-\\:      /-.\n\t\t\t");
        my_printf("   | (|:.     |) |\n\t\t\t    '-|:.     |-'\n\t\t\t");
        my_printf("      \\::.    /\n\t\t\t       '::. .'\n\t\t\t");
        my_printf("         ) (\n\t\t\t       _.' '._\n\t\t\t");
        my_printf("      `\"\"\"\"\"\"\"`\n");
        my_printf(COLOR_RESET"\n\n\t\t\tlast to be alive: (%d)%s\n",
            war->last, find_name_by_id(war->head, war->last));
        }
}

static bool are_all_champ_dead(war_t *war, champ_t *head)
{
    champ_t *current = head;
    int num = 0;

    while (current != NULL && !current->fork) {
        if (current->alive == 0)
            num++;
        current = current->next;
    }
    if (num >= war->num_champ - 1)
        return true;
    return false;
}

static void dump_loop(war_t *war, champ_t *head)
{
    while (war->dump > 0) {
        write(1, "\033[2J\033[1;1H", 11);
        war->done = false;
        if (game_loop(war, head))
            break;
        war->dump--;
        my_delay(8000);
    }
}

static void classic_loop(war_t *war, champ_t *head)
{
    int dt = 0;

    while (true) {
        if (are_all_champ_dead(war, head)
            && dt >= 55)
            return;
        write(1, "\033[2J\033[1;1H", 11);
        war->done = false;
        if (game_loop(war, head))
            break;
        dt++;
        my_delay(10000);
    }
}

void launch_game(war_t *war, champ_t *head)
{
    war->arena = init_arena();
    if (war->arena == NULL)
        return;
    init_starting_pos(war, head);
    if (war->dump != -1) {
        dump_loop(war, head);
    } else
        classic_loop(war, head);
    print_winner(war, head);
}
