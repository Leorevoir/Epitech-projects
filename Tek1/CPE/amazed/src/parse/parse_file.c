/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** stock_file
*/

#include "maze.h"
#include "my_stdlib.h"
#include "my_string.h"
#include "my_stdio.h"

static bool is_num(const char *str)
{
    if (str == NULL || *str == '\0')
        return false;
    while (*str != '\0' && *str != '\n') {
        if (*str < '0' || *str > '9')
            return false;
        str++;
    }
    return true;
}

static int check_start_end(char **array, int i, bool *start, bool *end)
{
    if (my_strcmp("##start\n", array[i]) == 0) {
        *start = true;
        return 1;
    }
    if (my_strcmp("##end\n", array[i]) == 0) {
        if (start)
            *end = true;
        else
            return 84;
    }
    return 0;
}

static void remove_comment(char *line)
{
    char *one_sharp = my_strchr(line, '#');
    char *two_sharp = my_strstr(line, "##");
    char *first_hash = NULL;

    if (two_sharp != NULL) {
        first_hash = my_strchr(two_sharp + 2, '#');
        if (first_hash != NULL)
            *first_hash = '\0';
    } else if (one_sharp != NULL) {
        *one_sharp = '\0';
        *(one_sharp - 1) = '\n';
    }
}

int error_handling(char **array, int lines)
{
    bool start = false;
    bool end = false;
    int rtn = 0;

    if (array == NULL)
        return 84;
    if (!is_num(array[0]))
        return 84;
    for (int i = 0; array[i]; i++) {
        remove_comment(array[i]);
        rtn = check_start_end(array, i, &start, &end);
        if (rtn == 84)
            return 84;
        if (rtn == 1)
            continue;
    }
    if (!start || !end)
        return 84;
    return parse_file(array, lines);
}

int read_labyrinth(void)
{
    char **array = (char **)malloc(sizeof(char *));
    char *buffer = NULL;
    size_t len = 0;
    int lines = 0;
    ssize_t read = getline(&buffer, &len, stdin);

    while (read != -1) {
        if (read > 0) {
            array = (char **)my_realloc(array, sizeof(char *) * (lines + 1));
            array[lines] = (char *)malloc(sizeof(char) * (read + 1));
            my_strcpy(array[lines], buffer);
            lines++;
        }
        read = getline(&buffer, &len, stdin);
    }
    free(buffer);
    array[lines] = NULL;
    return error_handling(array, lines);
}
