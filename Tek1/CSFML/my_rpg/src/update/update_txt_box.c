/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_txt_box
*/

#include "update.h"

sfVector2f convert_vector2i_to_vector2f(sfVector2i vector2i)
{
    sfVector2f vector2f;

    vector2f.x = (float)vector2i.x;
    vector2f.y = (float)vector2i.y;
    return vector2f;
}

void update_sprite_pos(rpg_t *rpg, sfVector2f pos_convert, npc_t *npc)
{
    sfVector2f picture_pos = pos_convert;
    sfVector2f arrow_pos = pos_convert;

    picture_pos.x += PICTURE_OFFSET_X;
    picture_pos.y += PICTURE_OFFSET_Y;
    arrow_pos.x += ARROW_OFFSET_X;
    arrow_pos.y += ARROW_OFFSET_Y;
    sfSprite_setPosition(rpg->ui->arrow.sprite, arrow_pos);
    sfSprite_setPosition(npc->picture.sprite, picture_pos);
}

void update_txt_pos(rpg_t *rpg, sfVector2f pos_convert)
{
    sfVector2f name_pos = pos_convert;

    name_pos.x += NAME_OFFSET_X;
    name_pos.y += NAME_OFFSET_Y;
    pos_convert.x += TEXT_OFFSET_X;
    pos_convert.y += TEXT_OFFSET_Y;
    sfText_setPosition(rpg->text->text, pos_convert);
    sfText_setPosition(rpg->text->name, name_pos);
}

void update_text_box(tmp_txt_t *tmp, rpg_t *rpg, npc_t *npc)
{
    sfVector2f view_pos = sfView_getCenter(rpg->view);
    sfVector2f box_pos = {
        view_pos.x + BOX_OFFSET_X,
        view_pos.y + BOX_OFFSET_Y
    };
    sfVector2i screen_pos = sfRenderWindow_mapCoordsToPixel(
        rpg->window, box_pos, rpg->view);
    sfVector2f pos_convert = {
        convert_vector2i_to_vector2f(screen_pos).x,
        convert_vector2i_to_vector2f(screen_pos).y
    };

    tmp->elapsed_time = sfClock_getElapsedTime(tmp->clock);
    tmp->elapsed_seconds = sfTime_asSeconds(tmp->elapsed_time);
    sfSprite_setPosition(rpg->ui->text_box.sprite,
        convert_vector2i_to_vector2f(screen_pos));
    update_sprite_pos(rpg, pos_convert, npc);
    update_txt_pos(rpg, pos_convert);
    rpg->player.speed = (sfVector2f){PLAYER_SPEED, PLAYER_SPEED};
}
