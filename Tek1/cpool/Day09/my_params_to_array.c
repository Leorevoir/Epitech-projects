/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_params_to_array
*/

#include "include/my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *par = malloc((ac + 1) * sizeof(struct info_param));
    int length;
    char *copy;
    char **word_array;

    if (par == NULL)
        return NULL;
    for (int i = 0; i < ac; i++) {
        length = strlen(av[i]);
        copy = strdup(av[i]);
        word_array = my_str_to_word_array(av[i]);
        par[i].length = length;
        par[i].str = av[i];
        par[i].copy = copy;
        par[i].word_array = word_array;
    }
    par[ac].str = 0;
    return par;
}
