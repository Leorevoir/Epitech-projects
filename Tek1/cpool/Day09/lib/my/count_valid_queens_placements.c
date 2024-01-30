/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** count_valid_queens_placements
*/

static int absolute(int value)
{
    return (value > 0) ? value : -value;
}

static int is_safe(int row, int col, int positions[], int n)
{
    for (int i = 0; i < col; i++) {
        if (positions[i] == row
            || absolute(positions[i] - row) == absolute(i - col))
            return 0;
    }
    return 1;
}

static int count_placements(int col, int positions[], int n)
{
    int count = 0;

    if (col == n)
        return 1;
    count = 0;
    for (int i = 0; i < n; i++) {
        if (is_safe(i, col, positions, n)) {
            positions[col] = i;
            count += count_placements(col + 1, positions, n);
        }
    }
    return count;
}

int count_valid_queens_placements(int n)
{
    int positions[n];

    for (int i = 0; i < n; i++)
        positions[i] = -1;
    return count_placements(0, positions, n);
}
