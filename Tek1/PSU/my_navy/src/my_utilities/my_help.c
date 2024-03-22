/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** my_help
*/

#include "../../include/my_printf.h"

void handle_help_option(void)
{
    my_printf("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n     first_player_pid: only for the 2nd player. ");
    my_printf("pid of the first player.\n     navy_positions: file ");
    my_printf("representing the positions of the ships\n");
}
