/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** main
*/

#include "include/radar.h"

int main(int argc, char **argv)
{
    radar_t radar;

    my_radar(&radar, argc, argv);
    radar_run(&radar);
    radar_destroy(&radar);
    return radar.value == STATUS_ERROR ? 84 : 0;
}
