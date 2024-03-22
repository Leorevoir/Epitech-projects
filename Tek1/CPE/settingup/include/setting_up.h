/*
** EPITECH PROJECT, 2024
** Tek1
** File description:
** setting_up
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef SETTING_UP_H_
    #define SETTING_UP_H_

typedef struct {
    int size;
    int row;
    int col;
} square_t;

typedef struct {
    char **matrix;
    int **cache;
    int rows;
    int cols;
} cache_data_t;

int my_strlen(const char *str);
square_t largest_square(char **matrix, int rows, int cols);
int read_file(char *path, char ***matrix, int *rows, int *cols);

#endif /* !SETTING_UP_H_ */
