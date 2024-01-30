/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my
*/

#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

char *my_revstr(char *str);
int my_str_isalpha(const char *str);
int my_str_islower(const char *str);
int my_str_isprintable(char const *str);
char *my_strcapitalize(char *str);
char *my_strncpy(char *dest, const char *src, int n);

#endif /* !MY_H_ */
