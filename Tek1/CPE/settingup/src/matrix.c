/*
** EPITECH PROJECT, 2024
** B-CPE-110-STG-1-1-settingup-leo.quinzler
** File description:
** matrix
*/

#include "../include/setting_up.h"
#include "../include/my_printf.h"

static int open_file(char *path, struct stat *st)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1 || stat(path, st) == -1)
        return -1;
    return fd;
}

static char *read_file_content(int fd, ssize_t size)
{
    char *str = malloc(size + 1);
    ssize_t bytes_read;

    if (!str)
        return NULL;
    bytes_read = read(fd, str, size);
    str[bytes_read] = '\0';
    return str;
}

static void update_max_col(int *max_col, int col)
{
    if (col > *max_col)
        *max_col = col;
}

static void count_rows_cols(char *str, int *rows, int *cols)
{
    int row = 0;
    int col = 0;
    int max_col = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            row++;
            update_max_col(&max_col, col);
            col = 0;
        } else {
            col++;
        }
    }
    *rows = row;
    *cols = max_col;
}

static void allocate_matrix(char ***matrix, int rows, int cols)
{
    *matrix = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++)
        (*matrix)[i] = malloc((cols + 1) * sizeof(char));
}

static void fill_matrix(char **matrix, char *str)
{
    int row = 0;
    int col = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '\n' || str[i] == '\0') {
            matrix[row][col] = '\0';
            row++;
            col = 0;
        } else {
            matrix[row][col] = str[i];
            col++;
        }
    }
}

int read_file(char *path, char ***matrix, int *rows, int *cols)
{
    struct stat st;
    int fd = open_file(path, &st);
    char *str;

    if (fd == -1)
        return 84;
    str = read_file_content(fd, st.st_size);
    if (!str) {
        close(fd);
        return 84;
    }
    count_rows_cols(str, rows, cols);
    allocate_matrix(matrix, *rows, *cols);
    fill_matrix(*matrix, str);
    free(str);
    close(fd);
    return 0;
}
