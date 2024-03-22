/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** my_split
*/

#include "../../include/radar.h"

char **my_split(char const *string)
{
    unsigned long count = get_count(string);
    char **words = malloc((count + 1) * sizeof(char *));

    for (unsigned long i = 0; i < count; i++)
        words[i] = get_next(&string);
    words[count] = 0;
    return words;
}

unsigned long my_split_length(char **array)
{
    unsigned long length = 0;

    while (array[length])
        length++;
    return length;
}

void my_free_split(char **array)
{
    for (unsigned long i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
