/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** my_memset
*/

#include <stddef.h>
#include <stdlib.h>

char *my_itoa(int num)
{
    char *str = NULL;
    int temp = num;
    int digit_count = 0;

    do {
        temp /= 10;
        digit_count++;
    } while (temp != 0);
    str = (char *)malloc((digit_count + 1) * sizeof(char));
    if (str == NULL)
        return NULL;
    temp = num;
    str[digit_count] = '\0';
    for (int i = digit_count - 1; i >= 0; i--) {
        str[i] = '0' + (temp % 10);
        temp /= 10;
    }
    return str;
}

void *my_memset(void *ptr, int value, size_t num)
{
    unsigned char *p = ptr;

    for (size_t i = 0; i < num; i++) {
        *(p + i) = (unsigned char)value;
    }
    return ptr;
}
