/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** my_strcat
*/

#include "my_string.h"

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = 0;

    if (dest == 0 || src == 0) {
        return (0);
    }
    while (dest[a] != '\0') {
        a++;
    }
    while (src[b] != '\0') {
        dest[a] = src[b];
        a++;
        b++;
    }
    dest[a] = '\0';
    return (dest);
}

char *my_strncat(char *dest, const char *src, int n)
{
    int dest_length = 0;
    int src_index = 0;

    if (dest == NULL || src == NULL || n <= 0) {
        return dest;
    }
    while (dest[dest_length] != '\0') {
        dest_length++;
    }
    while (src[src_index] != '\0' && src_index < n) {
        dest[dest_length] = src[src_index];
        dest_length++;
        src_index++;
    }
    dest[dest_length] = '\0';
    return dest;
}
