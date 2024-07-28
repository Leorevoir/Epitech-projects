/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** collisions
*/

#include "my_rpg.h"

bool is_blocked(sfVector2f start, sfVector2f end, rpg_t *rpg)
{
    sfColor color;
    sfColor dont_go = {255, 0, 245, 255};

    for (; start.x <= end.x; start.x++) {
        color = sfImage_getPixel(rpg->maps.current, start.x, start.y);
        if (color.r == dont_go.r
        && color.g == dont_go.g
        && color.b == dont_go.b)
            return true;
    }
    return false;
}

bool check_collision(rpg_t *rpg, char direction)
{
    sfVector2f start = rpg->player.object.position;
    sfVector2f end = rpg->player.object.position;
    int factor = 0;

    start.y += 16;
    end.x += 16;
    end.y += 16;
    if (direction == 'u')
        start.y--;
    if (direction == 'd')
        start.y++;
    if (direction == 'l')
        factor -= 2;
    if (direction == 'r')
        factor += 2;
    start.x += factor;
    end.x += factor;
    return is_blocked(start, end, rpg);
}
