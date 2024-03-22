/*
** EPITECH PROJECT, 2024
** B-CPE-110-STG-1-1-settingup-leo.quinzler
** File description:
** indian_square
*/

#include "../include/my_printf.h"
#include "../include/setting_up.h"

static int my_min(int a, int b, int c)
{
    int mini = a;

    if (b < mini)
        mini = b;
    if (c < mini)
        mini = c;
    return mini;
}

static int calculate_cache_value(char cell)
{
    return (cell == '.') ? 1 : 0;
}

static void initialize_cache(char **matrix, int rows, int cols, int **cache)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cache[i][j] = calculate_cache_value(matrix[i][j]);
        }
    }
}

static void update_cache_value(cache_data_t *data, int i, int j)
{
    if (i > 0 && j > 0 && data->matrix[i][j] == '.')
        data->cache[i][j] = 1 + my_min(data->cache[i][j - 1],
            data->cache[i - 1][j], data->cache[i - 1][j - 1]);
}

static void update_largest_value(cache_data_t *d, int i, int j, square_t *l)
{
    if (d->cache[i][j] > l->size) {
        l->size = d->cache[i][j];
        l->row = i;
        l->col = j;
    }
}

static square_t find_largest_square(char **matrix, int rows, int cols)
{
    int *cache[rows];
    square_t largest = {0, 0, 0};
    cache_data_t data = {matrix, cache, rows, cols};

    for (int i = 0; i < rows; i++)
        cache[i] = (int *)malloc(cols * sizeof(int));
    initialize_cache(matrix, rows, cols, cache);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            update_cache_value(&data, i, j);
            update_largest_value(&data, i, j, &largest);
        }
    }
    for (int i = 0; i < rows; i++)
        free(cache[i]);
    return largest;
}

square_t largest_square(char **matrix, int rows, int cols)
{
    square_t largest = {0, 0, 0};
    int **cache = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
        cache[i] = malloc(cols * sizeof(int));
    initialize_cache(matrix, rows, cols, cache);
    largest = find_largest_square(matrix, rows, cols);
    for (int i = 0; i < rows; i++)
        free(cache[i]);
    free(cache);
    return largest;
}
