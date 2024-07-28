/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-virgile.mulley
** File description:
** my_str_to_word_array_condition
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static int my_cara_is_condition(char c, char *condition)
{
    for (int i = 0; condition[i] != '\0'; i++) {
        if (c == condition[i])
            return (0);
    }
    return (1);
}

int count_size_string(char *str, char *condition, int i)
{
    int result = 0;
    int size = 0;

    if (my_cara_is_condition(str[0], condition) == 1)
        result = 1;
    for (int k = 0; str[k] != '\0'; k++) {
        if (k != 0 && my_cara_is_condition(str[k - 1], condition) == 0 &&
            my_cara_is_condition(str[k], condition) == 1) {
                result++;
        }
        if ((i + 1) == result && my_cara_is_condition(str[k], condition) == 1)
            size++;
        if (size != 0 && (i + 1) != result) {
            break;
        }
    }
    return (size);
}

char *init_string(int size)
{
    char *str = malloc(sizeof(char) * (size) + 2);

    for (int i = 0; i <= size; i++)
        str[i] = '\0';
    return str;
}

char *find_word(char *str, char *condition, int i)
{
    int size_string = count_size_string(str, condition, i);
    char *result = init_string(size_string);
    int index = 0;
    int size = 0;

    if (my_cara_is_condition(str[0], condition) == 1)
        index = 1;
    for (int k = 0; str[k] != '\0'; k++) {
        if (k != 0 && my_cara_is_condition(str[k - 1], condition) == 0 &&
            my_cara_is_condition(str[k], condition) == 1) {
                index++;
        }
        if ((i + 1) == index && my_cara_is_condition(str[k], condition) == 1) {
            result[size] = str[k];
            size++;
        }
        if (size != 0 && (i + 1) != index)
            break;
    }
    return (result);
}

int count_nbr_word(char *str, char *condition)
{
    int result = 0;

    if (my_cara_is_condition(str[0], condition) == 1)
        result = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (i != 0 && my_cara_is_condition(str[i - 1], condition) == 0 &&
            my_cara_is_condition(str[i], condition) == 1)
                result++;
    }
    return (result);
}

char **my_str_to_word_array_condition(char *str, char *condition)
{
    int nbr_word = count_nbr_word(str, condition);
    char **tab = malloc(sizeof(char *) * (nbr_word + 1));
    int i;

    for (i = 0; i < nbr_word; i++) {
        tab[i] = find_word(str, condition, i);
    }
    tab[i] = NULL;
    return (tab);
}
