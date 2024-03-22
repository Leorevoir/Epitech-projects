/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** my_strtok
*/

#include "../../include/my_navy.h"

int my_strtok(const char *line, char *token, const char delimiter,
    size_t *position)
{
    size_t i = *position;
    size_t token_index = 0;

    while (line[i] == delimiter)
        i++;
    while (line[i] != '\0' && line[i] != delimiter) {
        token[token_index] = line[i];
        token_index++;
        i++;
    }
    token[token_index] = '\0';
    *position = i;
    return token_index > 0 ? 1 : 0;
}
