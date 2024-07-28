/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** my_trim
*/

#include "minishell.h"
#include "my_string.h"

char *my_ltrim(char *str)
{
    while (my_isspace(*str))
        str++;
    return str;
}

char *my_rtrim(char *str)
{
    char *back = str + my_strlen(str);

    while (my_isspace(*back)) {
        *(back + 1) = '\0';
        back--;
    }
    return str;
}

char *my_trim(char *str)
{
    char *ltrimed = my_ltrim(str);

    return my_rtrim(ltrimed);
}
