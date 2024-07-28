/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_ui
*/

#include "my_rpg.h"

void destroy_ui(ui_t *ui)
{
    if (!ui)
        return;
    destroy_object(&(ui->text_box));
    destroy_object(&(ui->arrow));
    destroy_object(&(ui->hp));
    if (ui->clock)
        sfClock_destroy(ui->clock);
    free(ui);
}
