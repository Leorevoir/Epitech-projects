/*
** EPITECH PROJECT, 2024
** asd
** File description:
** asd
*/

#include "my.h"
#include "struct.h"

static void termios_init(void)
{
    struct termios init;

    tcgetattr(0, &init);
    init.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &init);
}

static void termios_reset(void)
{
    struct termios new_termios;

    tcgetattr(0, &new_termios);
    new_termios.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

void clear_line(edit_t *edit)
{
    int difference = edit->i - strlen(edit->rep);

    if (difference < 0)
        difference = difference * -1;
    printf("\r");
    for (int i = 0; edit->rep[i] != '\0'; i++)
        printf(" ");
    printf("\r");
    printf("$> %s", edit->rep);
    for (int i = 0; i < difference; i++)
        printf("\b");
    fflush(stdout);
}

static edit_t *init_edit(void)
{
    edit_t *edit = malloc(sizeof(edit_t));

    edit->buf;
    edit->rep = malloc(sizeof(char) * 1080);
    edit->rep[0] = '\0';
    edit->i = 0;
    edit->string_len = 0;
}

char *insert_char(char *str, char ch, int pos)
{
    int len = strlen(str);

    for (int i = len; i >= pos; i--) {
        str[i + 1] = str[i];
    }
    str[pos] = ch;
    return str;
}

static int is_enter(edit_t *edit)
{
    if (edit->buf == '\n' || edit->buf == '\r') {
        edit->rep[edit->string_len] = '\0';
        return 1;
    } else {
        edit->rep = insert_char(edit->rep, edit->buf, edit->i);
        edit->i++;
        edit->string_len++;
        clear_line(edit);
    }
}

int command_loop(edit_t *edit, history_t *his)
{
    while (1) {
        if (read(STDIN_FILENO, &edit->buf, 1) <= 0) {
            termios_reset();
            exit(0);
        }
        if (is_arrow(edit, &his) == 1)
            continue;
        if (edit->buf == 127) {
            backspace(edit);
            continue;
        }
        if (is_enter(edit) == 1)
            return 0;
        if (edit->buf == 4) {
            termios_reset();
            printf("\n");
            exit(0);
        }
    }
}

char *get_command(history_t *his)
{
    edit_t *edit = init_edit();
    char *command;
    history_t *temp = copy_history(his);

    my_rev_list(&temp);
    termios_init();
    command_loop(edit, temp);
    termios_reset();
    printf("\n");
    command = strdup(edit->rep);
    free(edit->rep);
    free(edit);
    return command;
}
