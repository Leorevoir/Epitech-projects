/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** history
*/

#include "my.h"
#include "struct.h"
#include <time.h>

static struct history_s *create_newnode(char *line)
{
    struct history_s *newnode = malloc(sizeof(*newnode));
    char *timestr = malloc(6);
    time_t secondes;
    struct tm instant;

    time(&secondes);
    instant = *localtime(&secondes);
    snprintf(timestr, 6, "%02d:%02d", instant.tm_hour, instant.tm_min);
    newnode->time = timestr;
    newnode->line = malloc(strlen(line) + 1);
    strcpy(newnode->line, line);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void append_to_history(struct history_s *newnode, history_t **his)
{
    struct history_s *current = *his;

    if (*his == NULL) {
        *his = newnode;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

void create_history(char *line, history_t **his)
{
    static int number = 0;
    struct history_s *newnode = create_newnode(line);

    if (line[0] == '\0')
        return;
    newnode->number = number + 1;
    append_to_history(newnode, his);
    number++;
}

int my_space(int number)
{
    int nbdigits = 0;
    int nbspace = 0;

    for (; number > 9; nbdigits++)
        number = number / 10;
    nbspace = nbdigits;
    return nbspace;
}

void display_history(mini_t *mini, history_t *his)
{
    int space_base;
    int space_less;

    while (his != NULL) {
        space_base = 5;
        space_less = space_base - my_space(his->number);
        for (; space_less != 0; space_less--)
            my_putstr(" ");
        my_put_nbr(his->number);
        my_putstr("  ");
        my_putstr(his->time);
        my_putstr("   ");
        my_putstr(his->line);
        my_putstr("\n");
        his = his->next;
    }
}
