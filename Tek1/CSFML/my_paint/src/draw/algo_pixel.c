/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** algo_pixel
*/

#include "algo.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief
/// Applique une couleur à un pixel dans un tableau de pixels RGBA
/// Si l'offset est valide, modifie les composantes RGBA du pixel correspondant
///
/// \param pixels: Tableau de pixels RGBA
/// \param offset: Position du pixel dans le tableau
/// \param color: Couleur à appliquer
///////////////////////////////////////////////////////////////////////////////
void apply_color_to_pixel(sfUint8 *pixels, int offset, sfColor color)
{
    if (offset >= 0 && offset < RECT_WIDTH * RECT_HEIGHT * 4) {
        pixels[offset] = color.r;
        pixels[offset + 1] = color.g;
        pixels[offset + 2] = color.b;
        pixels[offset + 3] = color.a;
    }
}

void apply_anti_aliased_color(sfUint8 *pixel, sfColor color,
    float brightness)
{
    float alpha;
    sfUint8 existing_alpha;

    if (color.a == 0) {
        pixel[0] = 255;
        pixel[1] = 255;
        pixel[2] = 255;
        pixel[3] = 0;
    } else {
        alpha = brightness * color.a;
        existing_alpha = pixel[3];
        alpha = alpha + existing_alpha * (1 - alpha / 255.0);
        color.a = (sfUint8)alpha;
        pixel[0] = color.r;
        pixel[1] = color.g;
        pixel[2] = color.b;
        pixel[3] = color.a;
    }
}

static void draw_endpoint(drawing_info_t *info)
{
    float xend = roundf(info->coords.x0);
    float yend = info->coords.y0 + info->gradient * (xend - info->coords.x0);
    float xgap = rfpart(info->coords.x0 + 0.5);
    int xpxl1 = (int)xend;
    int ypxl1 = (int)yend;

    if (info->steep) {
        xiaolin_wu_plot(info, ypxl1, xpxl1, rfpart(yend) * xgap);
        xiaolin_wu_plot(info, ypxl1 + 1, xpxl1, fpart(yend) * xgap);
    } else {
        xiaolin_wu_plot(info, xpxl1, ypxl1, rfpart(yend) * xgap);
        xiaolin_wu_plot(info, xpxl1, ypxl1 + 1, fpart(yend) * xgap);
    }
    info->coords.y0 = yend + info->gradient;
}

static void draw_line(drawing_info_t *info)
{
    float intery = info->coords.y0 + info->gradient;

    for (int x = info->coords.x0 + 1; x <= info->coords.x1 - 1; x++) {
        if (info->steep) {
            xiaolin_wu_plot(info, (int)intery, x, rfpart(intery));
            xiaolin_wu_plot(info, (int)intery + 1, x, fpart(intery));
        } else {
            xiaolin_wu_plot(info, x, (int)intery, rfpart(intery));
            xiaolin_wu_plot(info, x, (int)intery + 1, fpart(intery));
        }
        intery += info->gradient;
    }
}

void interpolate_and_apply_color(game_t *game, coordinates_t coords)
{
    drawing_info_t info = {game, coords, game->pencil.current, 0, false};

    info.steep = abs(coords.y1 - coords.y0) > abs(coords.x1 - coords.x0);
    if (info.steep) {
        my_swap(&info.coords.x0, &info.coords.y0);
        my_swap(&info.coords.x1, &info.coords.y1);
    }
    if (info.coords.x0 > info.coords.x1) {
        my_swap(&info.coords.x0, &info.coords.x1);
        my_swap(&info.coords.y0, &info.coords.y1);
    }
    info.gradient = (info.coords.x1 - info.coords.x0) != 0
        ? (float)(info.coords.y1 - info.coords.y0)
        / (info.coords.x1 - info.coords.x0) : 1.0;
    draw_endpoint(&info);
    draw_line(&info);
}
