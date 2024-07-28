/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_npc
*/

#include "my_rpg.h"

void destroy_npc_texture(npc_t *npc)
{
    for (int i = 0; i < COUNT; i++)
        if (npc->texture[i] != NULL)
            sfTexture_destroy(npc->texture[i]);
}

void destroy_npc(npc_t *npc)
{
    if (npc) {
        free(npc->name);
        destroy_object(&npc->object);
        destroy_object(&npc->picture);
        destroy_object(&npc->weapon);
        destroy_npc_texture(npc);
        sfClock_destroy(npc->move_clock);
        sfClock_destroy(npc->hit_clock);
        free(npc->texture);
        free(npc);
    }
}

void destroy_all_npcs(npc_t **head)
{
    npc_t *current = *head;
    npc_t *next;

    while (current != NULL) {
        next = current->next;
        destroy_npc(current);
        current = next;
    }
    *head = NULL;
}
