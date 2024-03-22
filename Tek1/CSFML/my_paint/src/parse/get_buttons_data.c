/*
** EPITECH PROJECT, 2024
** test
** File description:
** get_buttons_data
*/

#include "game.h"
#include "my_string.h"

char **get_buttons_data(void)
{
    char **buttons_data = NULL;
    char buffer[4096] = {0};
    ssize_t bytes_read = 0;
    FILE *file = fopen("data/buttons.conf", "r");

    if (file == NULL) {
        my_error("buttons.conf doesn't exist or isn't in the data's folder\n");
        return NULL;
    }
    bytes_read = fread(buffer, 1, sizeof(buffer) - 1, file);
    fclose(file);
    if (bytes_read == 0)
        return NULL;
    buffer[bytes_read] = '\0';
    buttons_data = my_str_to_word_array_line(buffer);
    return buttons_data;
}
