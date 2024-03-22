/*
** EPITECH PROJECT, 2024
** secured
** File description:
** my_putchar
*/

#include <unistd.h>
#include "../../include/hashtable.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
