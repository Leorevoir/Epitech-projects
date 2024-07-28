/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** parse_arguments
*/

#include "core.h"

static int usage(void)
{
    my_printf("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] ");
    my_printf("[-a load_address] prog_name] ...\nDESCRIPTION\n");
    my_printf("-dump nbr_cycle dumps the memory after the nbr_cycle executi");
    my_printf("on (if the round isn’t\nalready over) with the following");
    my_printf(" form");
    my_printf("at: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)\n-n ");
    my_printf("prog_number sets the next program’s number. By default,");
    my_printf(" the ");
    my_printf("first free number in the\nparameter order\n");
    my_printf("-a load_address sets the next program’s loading address. ");
    my_printf("When no address is specified,\noptimize the addresses so that");
    my_printf(" the processes are as far away from each other as\npossible.");
    my_printf(" The addresses are MEM_SIZE modulo.\n");
    return 0;
}

war_t *init_war(void)
{
    war_t *war = malloc(sizeof(war_t));

    if (war == NULL)
        return NULL;
    war->num_champ = 0;
    war->dump = -1;
    war->last = 0;
    war->head = NULL;
    war->arena = NULL;
    war->done = false;
    return war;
}

int parse_arguments(int argc, char **argv)
{
    int index = 1;
    war_t *war = init_war();

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return usage();
    if (argc < 3)
        return 84;
    if (flag_are_correct(argv, &index, war) == 84)
        return 84;
    return parse_cor_file(argc, argv, index, war);
}
