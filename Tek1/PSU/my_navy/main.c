/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** main
*/

#include "include/my_printf.h"
#include "include/my_navy.h"

int main(int argc, char **argv)
{
    int index;

    if (argc == 1 || argc > 3) {
        write(2, "./navy -h\n", 11);
        return 84;
    }
    if (argc == 2)
        index = 1;
    else
        index = 2;
    if (my_strcmp(argv[1], "-h") == 0) {
        handle_help_option();
        return 0;
    } else {
        if (handle_error(argv[index]) == 84)
            return (84);
        my_printf("my_pid: %d\n", getpid());
        return my_navy(argc, argv);
    }
    return 0;
}
