/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** get_vertex_bounds
*/

#include "my_rpg.h"

sfFloatRect get_vertex_bounds(sfVertexArray *vertex_array)
{
    sfVector2f min;
    sfVector2f max;
    sfVector2f point;

    if (sfVertexArray_getVertexCount(vertex_array) == 0)
        return (sfFloatRect){0, 0, 0, 0};
    min = sfVertexArray_getVertex(vertex_array, 0)->position;
    max = min;
    for (size_t i = 1; i < sfVertexArray_getVertexCount(vertex_array); ++i) {
        point = sfVertexArray_getVertex(vertex_array, i)->position;
        if (point.x < min.x)
            min.x = point.x;
        if (point.y < min.y)
            min.y = point.y;
        if (point.x > max.x)
            max.x = point.x;
        if (point.y > max.y)
            max.y = point.y;
    }
    return (sfFloatRect){min.x, min.y, max.x - min.x, max.y - min.y};
}
