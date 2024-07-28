/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** loop
*/

#include "core.h"

static void update_arena(war_t *war, champ_t *champ)
{
    int pos = champ->starting_pos;

    for (int i = 0; i < champ->header.prog_size; i++) {
        war->arena[pos % MEM_SIZE] = champ->inst[i];
        pos++;
    }
}

static int compare_hex_with_code(champ_t *champ, int i, int j, war_t *war)
{
    char *str = int_to_hex_string(war->arena[i]);

    if (my_strcmp(str, my_hex_code[j]) == 0) {
        champ->pc = func[j](champ, i, war);
    }
    free(str);
    return i;
}

void convert_hexa(unsigned char *arena, champ_t *champ, war_t *war)
{
    for (int j = 0; my_hex_code[j]; j++) {
        compare_hex_with_code(champ, champ->pc, j, war);
    }
}

static void switch_alive(champ_t *champ)
{
    switch (champ->alive) {
        case 0:
            champ->alive = 0;
            champ->dont_move = true;
            break;
        case 1:
            champ->alive = 1;
            champ->dont_move = false;
            break;
        default:
            champ->alive = 0;
            champ->dont_move = true;
        break;
    }
}

static void check_if_anyone_dies(war_t *war, champ_t *head)
{
    champ_t *current = head;

    while (current != NULL) {
        switch_alive(current);
        current = current->next;
    }
}

static bool do_things_in_the_loop(war_t *war, champ_t *head)
{
    static int cycle_de_vie = 0;

    write(1, "\033[2J\033[1;1H", 11);
    print_arena(war->arena, war);
    cycle_de_vie++;
    my_printf("%d\n", cycle_de_vie);
    if (cycle_de_vie >= 100) {
        check_if_anyone_dies(war, head);
        cycle_de_vie = 0;
    }
    return false;
}

bool game_loop(war_t *war, champ_t *head)
{
    champ_t *current = head;
    int pc_before = 0;

    while (current != NULL) {
        if (current->dont_move == true) {
            current = current->next;
            continue;
        }
        pc_before = current->pc;
        convert_hexa(war->arena, current, war);
        update_arena(war, current);
        if (current->pc == pc_before) {
            current->pc = (current->pc + 1) % MEM_SIZE;
        }
        current = current->next;
    }
    do_things_in_the_loop(war, head);
    return false;
}
