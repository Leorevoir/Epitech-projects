/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** algo_maths
*/

#include "algo.h"

static int get_pixel_index(int x, int y)
{
    return (x + y * RECT_WIDTH) * 4;
}

static bool is_position_valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < RECT_WIDTH && y < RECT_HEIGHT;
}

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

float fpart(float x)
{
    return x - floorf(x);
}

float rfpart(float x)
{
    return 1 - fpart(x);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief
/// Trace un pixel si sa position est dans le rayon spécifié.
///
/// \param info: Informations sur le dessin.
/// \param wu: Informations sur le pixel.
/// \param brightness: Luminosité du pixel.
///////////////////////////////////////////////////////////////////////////////
static void plot_pixel_if_in_radius(drawing_info_t *info, wo_xi_huan_t wu,
    float brightness)
{
    game_t *game = info->game;
    sfUint8 *pixel;
    int radius = game->pencil.size / 2;
    int x_index = 0;
    int y_index = 0;
    int index = 0;

    if (wu.dx * wu.dx + wu.dy * wu.dy <= radius * radius) {
        x_index = wu.x + wu.dx;
        y_index = wu.y + wu.dy;
        if (is_position_valid(x_index, y_index)) {
            index = get_pixel_index(x_index, y_index);
            pixel = game->pencil.pixels + index;
            apply_anti_aliased_color(pixel, info->color, brightness);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief
/// Trace un pixel anti-aliasé en fonction de sa luminosité.
///
/// \param info: Informations sur le dessin.
/// \param x: Coordonnée x du pixel.
/// \param y: Coordonnée y du pixel.
/// \param brightness: Luminosité du pixel.
///////////////////////////////////////////////////////////////////////////////
void xiaolin_wu_plot(drawing_info_t *info, int x, int y, float brightness)
{
    wo_xi_huan_t wu = {0};
    int radius = info->game->pencil.size / 2;

    wu.x = x;
    wu.y = y;
    for (wu.dy = -radius; wu.dy <= radius; ++wu.dy)
        for (wu.dx = -radius; wu.dx <= radius; ++wu.dx)
            plot_pixel_if_in_radius(info, wu, brightness);
}
