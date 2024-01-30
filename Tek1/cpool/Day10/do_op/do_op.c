/*
** EPITECH PROJECT, 2024
** Epitech-projects
** File description:
** do_op
*/

#include "my.h"

int (*get_op_func(char *op))(int, int)
{
    if (my_strcmp(op, "+") == 0)
        return add;
    if (my_strcmp(op, "-") == 0)
        return sub;
    if (my_strcmp(op, "*") == 0)
        return mul;
    if (my_strcmp(op, "/") == 0)
        return div;
    if (my_strcmp(op, "%") == 0)
        return mod;
    return 0;
}

int start_op(int val1, int val2, char **argv)
{
    int (*op_func)(int, int) = get_op_func(argv[2]);

    if (op_func == NULL)
        return 84;
    if ((my_strcmp(argv[2], "/") == 0
        || my_strcmp(argv[2], "%") == 0) && val2 == 0) {
        my_putstr("Stop: division or modulo by zero\n");
        return 84;
    }
    my_putstr(op_func(val1, val2));
    my_putchar('\n');
    return 0;
}

int parse_arguments(char **argv)
{
    int val1;
    int val2;
    char *endptr;

    val1 = my_strtol(argv[1], &endptr, 10);
    if (*endptr != '\0')
        return 84;
    val2 = my_strtol(argv[3], &endptr, 10);
    if (*endptr != '\0')
        return 84;
    return (start_op(val1, val2, argv));
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        my_putstr("error: only [ + - / * % ] are supported");
        return 84;
    }
    return parse_arguments(argv);
}
