/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** radar_planes
*/

#include "../../include/radar.h"

int plane_collides(plane_t *plane, plane_t *other)
{
    return other->pos.x + PLANE_SIZE > plane->pos.x
        && other->pos.y + PLANE_SIZE > plane->pos.y
        && plane->pos.x + PLANE_SIZE > other->pos.x
        && plane->pos.y + PLANE_SIZE > other->pos.y;
}

plane_t *plane_create(sfVector2f position, sfVector2f velocity,
    float distance, float delay)
{
    plane_t *plane = malloc(sizeof(plane_t));

    plane->pos = position;
    plane->velocity = velocity;
    plane->distance = distance;
    plane->delay = delay;
    plane->status = WAITING;
    plane->next = NULL;
    return plane;
}

void plane_prepend(plane_t **list, plane_t *plane)
{
    if (*list != NULL)
        plane->next = *list;
    *list = plane;
}

int parse_plane(radar_t *radar, char **words, unsigned long count)
{
    sfVector2f position;
    sfVector2f terminus;
    sfVector2f velocity;
    float distance;

    if (count != 7)
        return 84;
    if (!is_number(words[1]) || !is_number(words[2]) || !is_number(words[3])
        || !is_number(words[4]) || !is_number(words[5])
        || !is_number(words[6]))
        return 84;
    position = (sfVector2f) {str_to_int(words[1]), str_to_int(words[2])};
    terminus = (sfVector2f) {str_to_int(words[3]), str_to_int(words[4])};
    velocity = (sfVector2f) {terminus.x - position.x, terminus.y - position.y};
    distance = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    velocity.x = velocity.x / distance * str_to_int(words[5]);
    velocity.y = velocity.y / distance * str_to_int(words[5]);
    plane_prepend(&radar->planes, plane_create(position, velocity,
        distance, str_to_int(words[6])));
    return 0;
}
