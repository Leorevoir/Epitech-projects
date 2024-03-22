/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** free
*/

#include "my_string.h"

void free_word_array(char **words)
{
    if (!words)
        return;
    for (int i = 0; words[i] != NULL; i++)
        free(words[i]);
    free(words);
}
