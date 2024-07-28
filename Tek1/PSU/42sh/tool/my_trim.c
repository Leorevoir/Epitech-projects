/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** trim
*/

#include "struct.h"
#include "my.h"

char *my_ltrim(char *str)
{
    while (isspace(*str))
        str++;
    return str;
}

char *my_rtrim(char *str)
{
    char *back = str + strlen(str);

    while (isspace(*back)) {
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
