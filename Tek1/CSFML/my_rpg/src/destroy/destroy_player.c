/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_player
*/

#include "my_rpg.h"

void destroy_player(character_t player)
{
    destroy_object(&player.object);
    sfTexture_destroy(player.textures[WALK_DOWN]);
    sfTexture_destroy(player.textures[WALK_UP]);
    sfTexture_destroy(player.textures[WALK_LEFT]);
    sfTexture_destroy(player.textures[WALK_RIGHT]);
    sfTexture_destroy(player.textures[IDLE_DOWN]);
    sfTexture_destroy(player.textures[IDLE_UP]);
    sfTexture_destroy(player.textures[IDLE_LEFT]);
    sfTexture_destroy(player.textures[IDLE_RIGHT]);
    sfTexture_destroy(player.textures[ATCK_DOWN]);
    sfTexture_destroy(player.textures[ATCK_UP]);
    sfTexture_destroy(player.textures[ATCK_LEFT]);
    sfTexture_destroy(player.textures[ATCK_RIGHT]);
    sfTexture_destroy(player.textures[DEAD]);
}
