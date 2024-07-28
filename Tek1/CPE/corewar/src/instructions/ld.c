/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** ld
*/

#include "core.h"

int my_ld(champ_t *champ, int i, war_t *war)
{
    my_printf("executing LD\t");
    my_printf("0x%d    0x%d\n", champ->inst[i], champ->inst[i + 1]);
    return (i + 1) % MEM_SIZE;
}
