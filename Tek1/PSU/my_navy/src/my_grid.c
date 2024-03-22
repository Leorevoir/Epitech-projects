/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** my_grid
*/

#include "../include/my_printf.h"
#include "../include/my_navy.h"

static char check_hit(map_t *map, int i, int j)
{
    if (map->grid[i][j] == 'x')
        return 'x';
    else if (map->grid[i][j] == 'o')
        return 'o';
    else
        return '.';
}

void init_grid(map_t *map)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map->grid[i][j] = 0;
            map->enemy_grid[i][j] = 0;
        }
    }
}

void update_my_grid(map_t *map, int row, int col, int result)
{
    if (result == HIT)
        map->grid[row][col] = 'x';
    else
        map->grid[row][col] = 'o';
}

void print_enemy_grid(map_t *map)
{
    char c;

    my_printf("\nenemy navy:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            c = check_hit(map, i, j);
            my_printf("%c ", c);
        }
        my_putchar('\n');
    }
}

void make_print_grid(map_t *map, int i, int j)
{
    char c;

    if (map->grid[i][j] == 'x' || map->grid[i][j] == 'o') {
        c = map->grid[i][j];
        my_printf("%c ", c);
    } else
        my_printf("%c ", map->grid[i][j] ? map->grid[i][j] + '0' : '.');
}

void print_grid(map_t *map)
{
    my_printf("\nmy navy:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            make_print_grid(map, i, j);
        }
        my_putchar('\n');
    }
}
