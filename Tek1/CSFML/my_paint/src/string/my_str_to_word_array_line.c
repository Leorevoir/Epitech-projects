/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_str_to_word_array
*/

#include "my_stdlib.h"
#include "my_string.h"

int count_words_line(const char *str)
{
    int count = 0;
    int in_word = 0;

    if (!str)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '\n') && in_word)
            in_word = 0;
        if (str[i] != '\n' && !in_word) {
            in_word = 1;
            count++;
        }
    }
    return count;
}

void extract_word_line(const char *str,
    char **words, int *word_idx, int word_len)
{
    if (word_len > 0) {
        words[*word_idx] = my_strndup(str, word_len);
        (*word_idx)++;
    }
}

char **str_to_word_array_line(const char *str, char **words, int start, int in)
{
    int word_idx = 0;
    int word_len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '\n') && in) {
            word_len = i - start;
            extract_word_line(str + start, words, &word_idx, word_len);
            in = 0;
        }
        if (str[i] != '\n' && !in) {
            start = i;
            in = 1;
        }
    }
    if (in) {
        word_len = my_strlen(str) - start;
        extract_word_line(str + start, words, &word_idx, word_len);
    }
    words[word_idx] = NULL;
    return words;
}

char **my_str_to_word_array_line(const char *str)
{
    int num_words = count_words_line(str);
    char **words = malloc((num_words + 1) * sizeof(char *));
    int start = 0;
    int in_word = 0;

    if (!str || !words)
        return NULL;
    else
        return str_to_word_array_line(str, words, start, in_word);
}
