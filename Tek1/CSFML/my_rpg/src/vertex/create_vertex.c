/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** create_vertex
*/

#include "my_rpg.h"

void add_corner(sfVertexArray* vertex_array, sfVector2f center, float radius,
    sfVector2f angles)
{
    float rad;
    float angle;
    sfVertex vertex;
    sfVector2f point;
    float angle_step = (angles.y - angles.x) / 10;

    for (int i = 1; i <= 10; i++) {
        angle = angles.x + i * angle_step;
        rad = angle * PI / 180.f;
        point = (VECT){center.x + radius * cosf(rad),
            center.y + radius * sinf(rad)};
        vertex = (sfVertex){point, sfTransparent, (sfVector2f){0, 0}};
        sfVertexArray_append(vertex_array, vertex);
    }
}

sfVertexArray *create_vertex(float width, float height, float radius)
{
    sfVertexArray* vertex_array = sfVertexArray_create();
    sfVertex first_vertex;

    sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesFan);
    add_corner(vertex_array, (VECT){radius, radius},
        radius, (VECT){180, 270});
    add_corner(vertex_array, (VECT){width - radius, radius},
        radius, (VECT){270, 360});
    add_corner(vertex_array, (VECT){width - radius, height - radius},
        radius, (VECT){0, 90});
    add_corner(vertex_array, (VECT){radius, height - radius},
        radius, (VECT){90, 180});
    first_vertex = *sfVertexArray_getVertex(vertex_array, 0);
    sfVertexArray_append(vertex_array, first_vertex);
    return vertex_array;
}
