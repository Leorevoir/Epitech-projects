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

char *my_trim(char *str);
char *my_strdup(char const *src);
size_t my_strlen(char const *str);
void free_word_array(char **words);
char *my_strndup(const char *str, int n);
char *my_strrchr(const char *str, int c);
char *my_strcpy(char *dest, char const *str);
char *my_strcat(char *dest, char const *src);
char **my_str_to_word_array(const char *str);
int my_strcmp(const char *s1, const char *s2);
char *my_strstr(char *str, const char *to_find);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);

#endif /* !MY_STRING_H_ */
