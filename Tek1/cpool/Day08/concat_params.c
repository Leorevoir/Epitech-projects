/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** concat_params
*/

#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int l = 0;
    char *result;

    for (int i = 0; i < argc; i++)
        l += my_strlen(argv[i]) + 1;
    result = malloc(l);
    if (result == NULL)
        return NULL;
    my_strcpy(result, "");
    for (int i = 0; i < argc; i++) {
        my_strcat(result, argv[i]);
        if (i < argc - 1)
            my_strcat(result, "\n");
    }
    return result;
}
