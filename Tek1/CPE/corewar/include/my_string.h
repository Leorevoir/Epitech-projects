/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-robotfactory-leo.quinzler
** File description:
** my_string
*/

#include <stdlib.h>
#include <stdbool.h>

#ifndef MY_STRING_H_
    #define MY_STRING_H_

/* my string . h*/
char *my_trim(char *str);
char *my_strdup(char const *src);
int my_isspace(unsigned char c);
size_t my_strlen(const char *str);
int is_only_spaces(const char *cmd);
char *my_strchr(const char *str, int c);
char *my_itoa(int num);
bool my_isnum(const char *str);
int count_array(char **array);
char *my_strcpy(char *dest, char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strtok(char *str, const char *delim);
int my_strcmp(const char *s1, const char *s2);
char **my_str_to_word_array_spaces(const char *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, const char *to_find);
char **my_str_to_word_array(const char *str);
void free_word_array(char **array);
void *my_memset(void *ptr, int value, size_t num);
char *my_strndup(const char *str, int n);
int my_intlen(int nb);
char *int_to_str(int nb, char *str);

#endif /* !MY_STRING_H_ */
