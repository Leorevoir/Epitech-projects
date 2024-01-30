/*
** EPITECH PROJECT, 2024
** Epitech-projects
** File description:
** my_show_params_array
*/

#include "include/my.h"

void my_apanyan(struct info_param const *par)
{
    for (int i = 0; i < par->nb_param; i++)
        my_putstr(par->param[i]);
    my_putchar('\n');
}

int my_show_param_array(struct info_param const *par)
{
    while (par->str != NULL) {
        my_putstr(par->str);
        my_putchar('\n');
        my_put_nbr(par->length);
        my_putchar('\n');
        if (par->word_array != NULL) {
            my_apanyan(par);
        }
        my_putchar('\n');
        par++;
    }
    return (0);
}
