/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** tools
*/

#include "core.h"

void str_to_array(char ***tmp, char *str)
{
    char **new_tmp = NULL;
    size_t size = 0;

    if (*tmp != NULL)
        while ((*tmp)[size] != NULL)
            size++;
    new_tmp = (char **)realloc(*tmp, sizeof(char *) * (size + 2));
    new_tmp[size] = (char *)malloc(my_strlen(str) + 1);
    my_strcpy(new_tmp[size], str);
    new_tmp[size + 1] = NULL;
    *tmp = new_tmp;
}

static char *convert_hex_to_str(char **str, int num, int *i)
{
    int remainder = 0;
    int count = 0;

    do {
        remainder = num % 16;
        if (remainder < 10)
            (*str)[*i] = remainder + '0';
        else
            (*str)[*i] = remainder - 10 + 'a';
        (*i)++;
        count++;
        num /= 16;
    } while (num != 0);
    if (count == 1) {
        (*str)[*i] = '0';
        (*i)++;
    }
    return *str;
}

static void reverse_hex_string(char *str, int start, int end)
{
    char temp = 0;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char *int_to_hex_string(int num)
{
    char *str = (char *)malloc(6 * sizeof(char));
    int i = 0;

    str[i] = '0';
    i++;
    str[i] = 'x';
    i++;
    convert_hex_to_str(&str, num, &i);
    reverse_hex_string(str, 2, i - 1);
    str[i] = '\0';
    return str;
}
