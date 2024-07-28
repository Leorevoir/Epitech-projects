/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** extract_str
*/

#include "scripting.h"
#include <stdlib.h>
#include <string.h>

static int find_char_index(const char *str, char c, int start)
{
    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}

static char *extract_substring(const char *str, int start, int end)
{
    int length = end - start;
    char *substring = (char *)malloc((length + 1) * sizeof(char));

    if (substring != NULL) {
        strncpy(substring, &str[start], length);
        substring[length] = '\0';
    }
    return substring;
}

static int found_delim(int count, int *start, int i)
{
    if (count == 0) {
        *start = i + 1;
    }
    count++;
    return count;
}

static bool found_last_delim(const char *str, const char c2, int **end,
    tmp_delim_t *tmp)
{
    if (str[tmp->i] == c2) {
        tmp->count--;
        if (tmp->count == 0) {
            **end = tmp->i;
            return true;
        }
    }
    return false;
}

int find_delimiter_indices(const char *str, char c1, char c2, int *end)
{
    tmp_delim_t tmp = {0};
    int start = -1;

    *end = -1;
    for (; str[tmp.i] != '\0'; tmp.i++) {
        if (str[tmp.i] == c1) {
            tmp.count = found_delim(tmp.count, &start, tmp.i);
        }
        if (found_last_delim(str, c2, &end, &tmp)) {
            break;
        }
    }
    return start;
}

char *extract_string(const char *str, const char c1, const char c2)
{
    int start = -1;
    int end = -1;

    start = find_delimiter_indices(str, c1, c2, &end);
    if (start != -1 && end != -1) {
        return extract_substring(str, start, end);
    }
    return NULL;
}
