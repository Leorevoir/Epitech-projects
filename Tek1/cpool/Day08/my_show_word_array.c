/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_show_word_array
*/

#include <unistd.h>

int my_show_word_array(char *const *tab)
{
    if (tab == NULL)
        return 1;
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        write(1, "\n", 1);
    }
    return 0;
}
