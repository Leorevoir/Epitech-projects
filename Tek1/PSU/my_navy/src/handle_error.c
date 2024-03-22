/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** handle_error
*/

#include "../include/my_printf.h"
#include "../include/my_navy.h"

int is_valid_ship(char *line)
{
    char token[20];
    size_t position = 0;
    ship_t ship;

    if (!my_strtok(line, token, ':', &position))
        return 84;
    ship.length = my_getnbr(token);
    if (!my_strtok(line, token, ':', &position))
        return 84;
    ship.ipos1 = my_getnbr(token);
    ship.cpos1 = token[0];
    if (!my_strtok(line, token, ':', &position))
        return 84;
    ship.ipos2 = my_getnbr(token);
    ship.cpos2 = token[0];
    if (check_int(&ship) == 84
    || check_letter(ship.cpos1, ship.cpos2) == 84
    || check_length(&ship) == 84)
        return 84;
    return (0);
}

void free_all(FILE *file, char *line)
{
    fclose(file);
    free(line);
}

int handle_error(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int ship_count = 0;

    if (file == NULL)
        return (84);
    read = getline(&line, &len, file);
    while (read != -1) {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        if (is_valid_ship(line) != 84)
            ship_count++;
        read = getline(&line, &len, file);
    }
    free_all(file, line);
    return (ship_count != 4) ? 84 : 0;
}
