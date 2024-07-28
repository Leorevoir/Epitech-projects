/*
** EPITECH PROJECT, 2024
** asda
** File description:
** sd
*/

#include "my.h"
#include "struct.h"

int right_arrow(edit_t *edit)
{
    if (edit->buf == 'C') {
        if (edit->i < strlen(edit->rep)) {
            printf("\033[C");
            (edit->i)++;
            fflush(stdout);
        }
        return 1;
    }
    return 0;
}

int left_arrow(edit_t *edit)
{
    if (edit->buf == 'D') {
        if (edit->i > 0) {
            printf("\033[D");
            (edit->i)--;
            fflush(stdout);
        }
        return 1;
    }
    return 0;
}

int up_arrow(edit_t *edit, history_t **his)
{
    if (edit->buf == 'A') {
        if (*his == NULL)
            return 1;
        free(edit->rep);
        printf("\033[K\r$> ");
        edit->rep = strdup((*his)->line);
        edit->i = strlen(edit->rep);
        edit->string_len = strlen(edit->rep);
        printf("\033[K\r$> %s", edit->rep);
        if ((*his)->next != NULL) {
            (*his)->next->prev = *his;
            *his = (*his)->next;
        }
        fflush(stdout);
        return 1;
    }
    return 0;
}

int down_arrow(edit_t *edit, history_t **his)
{
    if (edit->buf == 'B') {
        if (*his == NULL)
            return 1;
        printf("\033[K\r$> ");
        free(edit->rep);
        edit->rep = strdup((*his)->line);
        edit->i = strlen(edit->rep);
        edit->string_len = strlen(edit->rep);
        printf("\033[K\r$> %s", edit->rep);
        if ((*his)->prev != NULL)
            (*his) = (*his)->prev;
        fflush(stdout);
        return 1;
    }
    return 0;
}

static int arrow_opt(edit_t *edit, history_t **his)
{
    if (up_arrow(edit, his) == 1)
        return 1;
    if (down_arrow(edit, his) == 1)
        return 1;
    if (right_arrow(edit) == 1)
        return 1;
    if (left_arrow(edit) == 1)
        return 1;
    return 1;
}

int is_arrow(edit_t *edit, history_t **his)
{
    int verif = 0;

    if (edit->buf == '\033') {
        read(STDIN_FILENO, &edit->buf, 1);
        if (edit->buf == '[') {
            read(STDIN_FILENO, &edit->buf, 1);
            verif = arrow_opt(edit, his);
        }
        if (verif == 1)
            return 1;
    }
    if (edit->buf == '\t') {
        autocompletion(edit);
        return 1;
    }
    return 0;
}
