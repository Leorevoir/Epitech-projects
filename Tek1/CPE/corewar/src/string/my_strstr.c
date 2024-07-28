/*
** EPITECH PROJECT, 2023
** MY_STRSTR
** File description:
** Reproduce strstr function
*/

#include "my_string.h"

int count_array(char **array)
{
    int count = 0;

    if (array == NULL)
        return -1;
    while (array[count])
        count++;
    return count;
}

int compare_str(const char *str1, const char *str2, size_t length)
{
    for (size_t a = 0; a < length; a++)
        if (str1[a] != str2[a])
            return 0;
    return 1;
}

char *my_strstr(char *str, const char *to_find)
{
    size_t str_length = my_strlen(str);
    size_t find_length = my_strlen(to_find);

    if (str_length == 0
        || find_length == 0
        || find_length > str_length)
        return 0;
    for (size_t i = 0; i < (str_length - find_length + 1); i++)
        if (compare_str(str + i, to_find, find_length))
            return str + i;
    return 0;
}
