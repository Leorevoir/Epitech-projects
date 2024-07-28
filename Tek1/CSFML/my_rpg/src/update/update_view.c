/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_view
*/

#include "update.h"

void update_view_position(rpg_t *rpg, int w, int h)
{
    sfVector2f player_position = rpg->player.object.position;
    sfVector2f c = player_position;
    sfVector2f view_size = sfView_getSize(rpg->view);

    c = restrict_view_center(c, view_size, w, h);
    sfView_setCenter(rpg->view, c);
}

void update_view(rpg_t *rpg)
{
    int width = 0;
    int height = 0;

    if (!rpg->player.has_moved && rpg->cinema)
        return;
    if (rpg->background == &(rpg->maps.map_road)) {
        width = S_WIDTH;
        height = S_HEIGHT;
    }
    if (rpg->background == &(rpg->maps.map_village)) {
        width = V_WIDTH;
        height = V_HEIGHT;
    }
    if (rpg->background == &(rpg->maps.map_boss)) {
        width = TEST_WIDTH;
        height = TEST_HEIGHT;
    }
    if (width > 0 && height > 0)
        update_view_position(rpg, width, height);
    rpg->player.has_moved = false;
}
