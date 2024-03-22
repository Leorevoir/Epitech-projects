/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** radar_helper
*/

#include "../../include/radar.h"

void radar_usage(void)
{
    my_putstr("USAGE:\n  ./my_radar -h\n");
}

void radar_help(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("  path_to_script\tthe path to script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h\tprint the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  'L'\tkey\t\tenable/disable hitboxes and areas.\n");
    my_putstr("  'S'\tkey\t\tenable/disable sprites.\n");
}

void handle_help_option(radar_t *radar)
{
    radar->value = STATUS_HELP;
    radar_help();
}

void handle_invalid_args(radar_t *radar)
{
    radar->value = STATUS_ERROR;
    radar_usage();
}
