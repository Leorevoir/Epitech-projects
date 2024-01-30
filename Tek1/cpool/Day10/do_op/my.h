/*
** EPITECH PROJECT, 2024
** Epitech-projects
** File description:
** my
*/

#include <unistd.h>
#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_
    #define LONG_MAX 9223372036854775807
    #define LONG_MIN -9223372036854775807

int my_strcmp(const char *a, const char *b);
int my_strlen(const char *str);
void my_putstr(const char *str);
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);

#endif /* !MY_H_ */
