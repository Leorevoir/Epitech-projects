/*
** EPITECH PROJECT, 2023
** main c
** File description:
** setting up main
*/

#include "include/setting_up.h"
#include "include/my_printf.h"

static int is_valid(char *line)
{
    for (int j = 0; line[j] != '\0'; j++) {
        if (line[j] != '.' && line[j] != 'o')
            return 0;
    }
    return 1;
}

static int check_matrix_content(char **matrix, int rows)
{
    for (int i = 1; i < rows; i++) {
        if (!is_valid(matrix[i]))
            return 1;
    }
    return 0;
}

static void free_matrix(char **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

static void replace_with_x(char **matrix, square_t largest)
{
    for (int i = largest.row; i > largest.row - largest.size; i--) {
        for (int j = largest.col; j > largest.col - largest.size; j--) {
            matrix[i][j] = 'x';
        }
    }
}

void print_matrix(char **matrix, int rows, int cols)
{
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            my_printf("%c", matrix[i][j]);
        }
        my_printf("\n");
    }
}

int main(int argc, char **argv)
{
    char **matrix;
    int rows;
    int cols;
    square_t largest;

    if (argc != 2) {
        write(2, "Usage: ./setting_up <file_path>\n", 32);
        return 84;
    }
    read_file(argv[1], &matrix, &rows, &cols);
    if (check_matrix_content(matrix, rows)) {
        write(2, "Error: file must contain '.' and 'o'.\n", 39);
        free_matrix(matrix, rows);
        return 84;
    }
    largest = largest_square(matrix, rows, cols);
    replace_with_x(matrix, largest);
    print_matrix(matrix, rows, cols);
    free_matrix(matrix, rows);
    return 0;
}
