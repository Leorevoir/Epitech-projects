/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** zjmp
*/

#include "core.h"
#include "my_string.h"

int my_zjmp(champ_t *champ, int i, war_t *war)
{
    int num = 0;

    if (champ->carry == 1) {
        num = war->arena[(i + 2) % MEM_SIZE] % IDX_MOD;
        return (i + num);
    }
    return (i + 3) % MEM_SIZE;
}
