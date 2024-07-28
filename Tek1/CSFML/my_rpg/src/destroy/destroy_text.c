/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_text
*/

#include "my_rpg.h"

void destroy_text(text_t *text)
{
    if (!text)
        return;
    if (text->text)
        sfText_destroy(text->text);
    if (text->name)
        sfText_destroy(text->name);
    if (text->quest)
        sfText_destroy(text->quest);
    if (text->validate)
        sfText_destroy(text->validate);
    if (text->description)
        sfText_destroy(text->description);
    if (text->font)
        sfFont_destroy(text->font);
    destroy_object(&(text->picture));
    free(text);
}
