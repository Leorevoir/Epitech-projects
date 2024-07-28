/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** main
*/

#include "my_rpg.h"
#include "display.h"
#include "update.h"

int main(void)
{
    rpg_t rpg = {0};
    tile_t *head = NULL;
    hud_t *hud = NULL;
    stats_t *stats = NULL;

    return my_rpg(&rpg, head, hud, stats);
}
