/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_boss
*/

#include "my_rpg.h"

static void destroy_smokes(fx_t *fx)
{
    sfClock_destroy(fx->clock);
    sfClock_destroy(fx->move1);
    sfClock_destroy(fx->move2);
    sfClock_destroy(fx->move3);
    sfClock_destroy(fx->move4);
    sfClock_destroy(fx->red1_clock);
    sfClock_destroy(fx->red2_clock);
    sfClock_destroy(fx->clock1);
    destroy_object(&(fx->smoke1));
    destroy_object(&(fx->smoke2));
    destroy_object(&(fx->smoke3));
    destroy_object(&(fx->smoke4));
    destroy_object(&(fx->rocket));
    destroy_object(&(fx->red1));
    destroy_object(&(fx->red2));
}

void destroy_all_boss(boss_t *boss)
{
    if (!boss)
        return;
    destroy_object(&(boss->object));
    destroy_object(&boss->fx.thunder);
    if (boss->textures[0])
        sfTexture_destroy(boss->textures[0]);
    if (boss->textures[1])
        sfTexture_destroy(boss->textures[1]);
    if (boss->textures[2])
        sfTexture_destroy(boss->textures[2]);
    if (boss->textures[3])
        sfTexture_destroy(boss->textures[3]);
    sfClock_destroy(boss->clock);
    sfClock_destroy(boss->flame_clock);
    sfClock_destroy(boss->hit_clock);
    destroy_smokes(&(boss->fx));
    free(boss);
}
