/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** handle_exit
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/struct.h"

int handle_exit(mini_t *mini)
{
    if (my_strcmp(mini->tab_clean[0], "exit") == 0)
        return my_exit(mini);
    return -1;
}
