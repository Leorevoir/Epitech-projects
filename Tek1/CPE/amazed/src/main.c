/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** main
*/

#include "maze.h"
#include "my_string.h"
#include "my_stdio.h"
#include "my_stdlib.h"

int usage(void)
{
    my_printf("USAGE:\n\t./laby_gen.pl <size> <density> <robots>\n");
    my_printf("\t./amazed <labyrinth>\nDESCRIPTION:\n\tA-Maze-d aims to move");
    my_printf(" all the robots in a maze from the entrance to the exit\n");
    my_printf("\twhile getting as many robots through as possible \n\tat the");
    my_printf(" same time and in as little time as possible.\n");
    return SUCCESS;
}

int parse_arguments(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return usage();
    if (argc != 1)
        return ERROR;
    return read_labyrinth();
}

int main(int argc, char **argv)
{
    return parse_arguments(argc, argv);
}
