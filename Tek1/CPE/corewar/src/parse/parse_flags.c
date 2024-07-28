/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** parse_flags
*/

#include "core.h"

int flag_are_correct(char **argv, int *index, war_t *war)
{
    if (my_strcmp(argv[1], "-dump") == 0) {
        if (!argv[2] || !my_isnum(argv[2]))
            return 84;
        war->dump = my_getnbr(argv[2]);
        *index += 2;
    }
    return 0;
}
