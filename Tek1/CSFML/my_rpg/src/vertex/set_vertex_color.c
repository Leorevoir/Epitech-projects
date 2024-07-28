/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** set_vertex_color
*/

#include "my_rpg.h"

void set_vertex_color(sfVertexArray* vertexArray, sfColor color)
{
    sfVertex *vertex;

    for (size_t i = 0; i < sfVertexArray_getVertexCount(vertexArray); ++i) {
        vertex = sfVertexArray_getVertex(vertexArray, i);
        vertex->color = color;
    }
}
