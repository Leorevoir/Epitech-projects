/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** my_string
*/

#include <unistd.h>
#include <stdlib.h>

#ifndef MY_STRING_H_
    #define MY_STRING_H_

/* my string . h*/
size_t my_strlen(const char *str);
char *my_strdup(char const *src);
void free_word_array(char **words);
char *my_strndup(const char *str, int n);
char *my_strrchr(const char *str, int c);
char *my_strcpy(char *dest, char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strtok(char *str, const char *delim);
int my_strcmp(const char *s1, const char *s2);
char *my_strstr(char *str, const char *to_find);
char *my_strncat(char *dest, const char *src, int n);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char **my_str_to_word_array_space(const char *str);
char **my_str_to_word_array_line(const char *str);

#endif /* !MY_STRING_H_ */
