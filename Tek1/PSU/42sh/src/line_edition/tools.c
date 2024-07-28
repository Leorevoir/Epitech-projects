/*
** EPITECH PROJECT, 2024
** asd
** File description:
** asd
*/

#include "my.h"
#include "struct.h"

static char *delete_char(char *str, int pos)
{
    int len = strlen(str);

    for (int i = pos; i < len - 1; i++)
        str[i] = str[i + 1];
    str[len - 1] = '\0';
    return str;
}

void backspace(edit_t *edit)
{
    int difference = edit->i - strlen(edit->rep);

    if (difference < 0)
        difference = difference * -1;
    if (edit->i > 0) {
        edit->i--;
        printf("\r");
        for (int i = 0; i <= edit->string_len + 2; i++)
            printf(" ");
        edit->string_len--;
        edit->rep = delete_char(edit->rep, edit->i);
        printf("\r");
        printf("$> %s", edit->rep);
        for (int i = 0; i < difference; i++)
            printf("\b");
        fflush(stdout);
    }
}

void back_history(history_t *history)
{
    return;
}

void next_history(history_t *history)
{
    return;
}
