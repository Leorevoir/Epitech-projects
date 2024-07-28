/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** free_word_array
*/

#include "maze.h"
#include <stdlib.h>

void free_tmp_array(char **tmp)
{
    for (int i = 0; tmp[i]; i++)
        free(tmp[i]);
    free(tmp);
}

void free_word_array(char **array, int size)
{
    if (!array)
        return;
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

void free_matrice(int **matrix)
{
    if (matrix == NULL)
        return;
    free(matrix[0]);
    free(matrix);
    matrix = NULL;
}
