/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** my_trim
*/

#include "maze.h"
#include "my_string.h"

int my_isspace(unsigned char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int is_only_spaces(const char *cmd)
{
    for (int i = 0; cmd[i]; i++) {
        if (!my_isspace((unsigned char)cmd[i]))
            return 0;
    }
    return 1;
}

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
