/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-bsminishell1-leo.quinzler
** File description:
** main
*/

#include "my_stdio.h"
#include "minishell.h"
#include "my_string.h"

int usage(void)
{
    my_printf("USAGE:\n\t./mysh\nDESCRIPTION:\n\tminishell2 is a small shell");
    my_printf(" terminal with\n\t- semicolons (';')\n\t- pipes ('|')\n\t");
    my_printf("- and the four redirections ('>', '<', '>>', '<<')\n");
    return SUCCESS;
}

int parse_arguments(int argc, char **argv, char **env)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return usage();
    if (argc != 1)
        return ERROR;
    return shell_loop(env);
}

int main(int argc, char **argv, char **env)
{
    return parse_arguments(argc, argv, env);
}
