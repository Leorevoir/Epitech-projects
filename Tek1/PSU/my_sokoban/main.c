/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-sokoban-leo.quinzler
** File description:
** main
*/

#include "include/sokoban.h"

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, containing ‘#’");
    my_putstr(" for walls,\n");
    my_putstr("            ‘P’ for the player, ‘X’ for boxes and");
    my_putstr("‘O’ for storage locations.\n");
    exit(0);
}

int main(int argc, char **argv)
{
    map_t *map = malloc(sizeof(map_t));

    return parse_arguments(argc, argv, map);
}
