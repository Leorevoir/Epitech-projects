/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** create_button
*/

#include "my_string.h"
#include "my_stdlib.h"
#include "button.h"

sfRectangleShape *init_button_selection_shape(sfUint8 pixels, sfVector2f pos,
    sfVector2f size)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, (sfColor){pixels, pixels,
        pixels, 255});
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}

void what_action(button_t *new_button)
{
    for (int i = 0; button_actions[i].name != NULL; i++) {
        if (my_strcmp(button_actions[i].name, new_button->name) == 0) {
            new_button->action = button_actions[i].action;
            break;
        }
    }
}

button_t *create_button(char **button_data)
{
    button_t *new_button;

    if (!button_data)
        return NULL;
    new_button = malloc(sizeof(button_t));
    new_button->name = my_strdup(button_data[0]);
    new_button->pos = (sfVector2f){my_getnbr(button_data[1]),
        my_getnbr(button_data[2])};
    new_button->size = (sfVector2f){my_getnbr(button_data[3]),
        my_getnbr(button_data[4])};
    new_button->rect = init_button_selection_shape(128,
        new_button->pos, new_button->size);
    new_button->action = NULL;
    what_action(new_button);
    new_button->state = BUTTON_INACTIVE;
    return new_button;
}

void add_button_to_list(button_t **button_list, button_t *new_button)
{
    if (new_button == NULL)
        return;
    new_button->next = *button_list;
    *button_list = new_button;
}

void create_buttons(button_t **button_list, char **buttons_data)
{
    char **button_data;
    button_t *new_button;

    if (!buttons_data)
        return;
    for (int i = 0; buttons_data[i] != NULL; i++) {
        button_data = my_str_to_word_array_space(buttons_data[i]);
        new_button = create_button(button_data);
        add_button_to_list(button_list, new_button);
        free_word_array(button_data);
    }
}
