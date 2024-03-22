/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** string_processing
*/

#include "../../include/radar.h"

unsigned long get_count(char const *string)
{
    unsigned long count = 0;
    int space = 1;

    for (unsigned long i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
            space = 1;
            continue;
        }
        if (space)
            count++;
        space = 0;
    }
    return count;
}

char *get_next(char const **string)
{
    char const *word;

    while (**string == ' ' || **string == '\t' || **string == '\n')
        (*string)++;
    word = *string;
    while (**string != ' ' && **string != '\t' && **string != '\n'
        && **string != '\0')
        (*string)++;
    return my_strndup(word, *string - word);
}
