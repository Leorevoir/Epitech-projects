/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** convert_base
*/

#include <stdlib.h>

static int char_to_val(char c, const char *base)
{
    int i;

    for (i = 0; i < my_strlen(base); i++) {
        if (c == base[i])
            return i;
    }
    return -1;
}

static int to_base_10(const char *nbr, const char *base_from)
{
    int result = 0;
    int base = my_strlen(base_from);
    int val;

    for (int i = 0; nbr[i] != '\0'; i++) {
        val = char_to_val(nbr[i], base_from);
        if (val == -1)
            return -1;
        result = result * base + val;
    }
    return result;
}

static char *reverse_string(char *str)
{
    int length = my_strlen(str);
    char tmp;

    for (int i = 0; i < length / 2; i++) {
        tmp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = tmp;
    }
    return str;
}

static char *from_base_10(int nbr, const char *base_to)
{
    char *result;
    int base = my_strlen(base_to);
    int i = 0;

    result = malloc(sizeof(char) * (100));
    if (!result)
        return NULL;
    if (nbr == 0) {
        result[0] = base_to[0];
        result[1] = '\0';
        return result;
    }
    while (nbr > 0) {
        result[i] = base_to[nbr % base];
        i++;
        nbr /= base;
    }
    result[i] = '\0';
    return reverse_string(result);
}

static int is_valid_base(const char *base)
{
    int len = my_strlen(base);

    if (len < 2)
        return 0;
    for (int i = 0; i < len; i++) {
        if (char_to_val(base[i], base) != i)
            return 0;
    }
    return 1;
}

char *convert_base(const char *nbr, const char *base_from, const char *base_to)
{
    int base_10;

    if (!nbr || !base_from || !base_to || !is_valid_base(base_from)
        || !is_valid_base(base_to))
        return NULL;
    base_10 = to_base_10(nbr, base_from);
    return from_base_10(base_10, base_to);
}
