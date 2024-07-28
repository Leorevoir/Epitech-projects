/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** arena_tools
*/

#include "core.h"

const char *get_color_by_id(int id)
{
    switch (id) {
        case 1:
            return COLOR_YELLOW;
        case 2:
            return COLOR_MAGENTA;
        case 3:
            return COLOR_RED;
        case 4:
            return COLOR_CYAN;
        default:
            return COLOR_GRAY;
    }
}

champ_t *find_champ_by_instruction(champ_t *head,
    const unsigned char *arena, int index)
{
    int start = 0;
    int end = 0;

    while (head != NULL) {
        start = head->starting_pos;
        end = (start + head->header.prog_size) % MEM_SIZE;
        if (index >= start && index < end)
            return head;
        head = head->next;
    }
    return NULL;
}

size_t unsigned_char_len(unsigned char c)
{
    return UNSIGNED_LEN;
}
