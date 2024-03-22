/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-leo.quinzler
** File description:
** my_string
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef MY_STRING_H_
    #define MY_STRING_H_

char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *str);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strrchr(const char *str, int c);
size_t my_strlen(char const *str);

#endif /* !MY_STRING_H_ */
