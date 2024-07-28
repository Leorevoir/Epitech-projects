/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-robotfactory-leo.quinzler
** File description:
** my_stdlib
*/

#include <stdlib.h>
#include <limits.h>

#ifndef MY_STDLIB_H_
    #define MY_STDLIB_H_

int my_atoi(char *str);
void *my_realloc(void *ptr, size_t size);
void my_memcpy(void *dest, void *src, size_t n);
void *my_calloc(size_t num_elements, size_t element_size);

#endif /* !MY_STDLIB_H_ */
