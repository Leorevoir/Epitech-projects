/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** is_in_vertex
*/

#include "update.h"

sfVector2i convert_mouse_vertex(
    sfRenderWindow *window, rpg_t *rpg, const sfView *view)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f v_size = sfView_getSize(view);
    sfVector2f v_center = sfView_getCenter(view);
    sfFloatRect resize_v = {
        v_center.x - (v_size.x / 2),
        v_center.y - (v_size.y / 2),
        v_size.x,
        v_size.y
    };
    sfVector2i adjusted_mouse_pos = {
        (int)(((float)mouse_pos.x / sfRenderWindow_getSize(
            window).x) * resize_v.width + resize_v.left),
        (int)(((float)mouse_pos.y / sfRenderWindow_getSize(
            window).y) * resize_v.height + resize_v.top)
    };

    return adjusted_mouse_pos;
}

sfBool is_in_vertex(rpg_t *rpg)
{
    const sfView *default_v = sfRenderWindow_getDefaultView(rpg->window);
    sfVector2i mouse_pos = convert_mouse_vertex(rpg->window, rpg, default_v);
    sfVector2f mp_float = { mouse_pos.x, mouse_pos.y };
    sfTransform inverse = sfTransform_getInverse(&(CMD_INV.transform_btn));
    sfFloatRect bounds = get_vertex_bounds(CMD_INV.button);

    mp_float = sfTransform_transformPoint(&inverse, mp_float);
    if (sfFloatRect_contains(&bounds, mp_float.x, mp_float.y))
        return sfTrue;
    return sfFalse;
}
