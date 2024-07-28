/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** str_to_array
*/

#include "my_string.h"
#include "my_stdlib.h"

void str_to_array(char ***tmp, char *str)
{
    char **new_tmp = NULL;
    size_t size = 0;

    if (*tmp != NULL)
        while ((*tmp)[size] != NULL)
            size++;
    new_tmp = (char **)my_realloc(*tmp, sizeof(char *) * (size + 2));
    new_tmp[size] = (char *)malloc(my_strlen(str) + 1);
    my_strcpy(new_tmp[size], str);
    new_tmp[size + 1] = NULL;
    *tmp = new_tmp;
}
