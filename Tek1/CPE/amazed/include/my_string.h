/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-robotfactory-leo.quinzler
** File description:
** my_string
*/

#include <stdlib.h>

#ifndef MY_STRING_H_
    #define MY_STRING_H_

/* my string . h*/
char *my_trim(char *str);
void my_error(const char *str);
char *my_strdup(char const *src);
size_t my_strlen(const char *str);
char *my_strchr(const char *str, int c);
char *my_itoa(int num);
char *my_strcpy(char *dest, char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strtok(char *str, const char *delim);
int my_strcmp(const char *s1, const char *s2);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, const char *to_find);
char **my_str_to_word_array(const char *str);
char *my_strndup(const char *str, int n);
void str_to_array(char ***tmp, char *str);
void *my_memset(void *ptr, int value, size_t num);

#endif /* !MY_STRING_H_ */
