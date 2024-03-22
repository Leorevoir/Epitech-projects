/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** radar_towers
*/

#include "../../include/radar.h"

void tower_prepend(tower_t **list, tower_t *tower)
{
    if (*list != NULL)
        tower->next = *list;
    *list = tower;
}

int parse_tower(radar_t *radar, char **words, unsigned long count)
{
    sfVector2f position;

    if (count != 4)
        return 84;
    if (!is_number(words[1]) || !is_number(words[2]))
        return 84;
    position = (sfVector2f) {str_to_int(words[1]), str_to_int(words[2])};
    tower_prepend(&radar->towers, tower_create(position,
        str_to_int(words[3])));
    return 0;
}
