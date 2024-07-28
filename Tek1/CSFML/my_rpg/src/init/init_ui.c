/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_ui
*/

#include "my_rpg.h"

void init_ui(rpg_t *rpg)
{
    rpg->ui = (ui_t *)malloc(sizeof(ui_t));
    rpg->ui->hp = init_object(HP, (sfVector2f){0, 0});
    rpg->ui->text_box = init_object(DIALOG_BOX, (sfVector2f){0, 0});
    sfSprite_scale(rpg->ui->text_box.sprite, (sfVector2f){3, 3});
    rpg->ui->arrow = init_object(ARROW_UI, (sfVector2f){0, 0});
    sfSprite_scale(rpg->ui->arrow.sprite, (sfVector2f){3, 3});
    rpg->ui->clock = sfClock_create();
}
