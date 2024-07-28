/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** destroy_dialogues
*/

#include "my_rpg.h"

void destroy_all_dialogues(dialogue_t *head)
{
    dialogue_t *tmp = NULL;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp->name);
        free(tmp->text);
        free(tmp->quest);
        free(tmp);
    }
}
