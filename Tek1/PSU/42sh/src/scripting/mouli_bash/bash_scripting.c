/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** bash_scripting
*/

#include "my.h"
#include "scripting.h"
#include <sys/stat.h>
#include <sys/types.h>

char *open_bash_script(const char *filename, struct stat *st)
{
    FILE *file = fopen(filename, "r");
    char *buffer = NULL;
    size_t bytes_read = 0;

    if (file == NULL)
        return NULL;
    buffer = (char *)malloc((st->st_size + 1) * sizeof(char));
    if (buffer == NULL) {
        fclose(file);
        return NULL;
    }
    bytes_read = fread(buffer, sizeof(char), st->st_size, file);
    buffer[st->st_size] = '\0';
    fclose(file);
    return buffer;
}

void free_var_list(var_t **head)
{
    var_t *tmp = *head;
    var_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp->name);
        free(tmp->value);
        free(tmp);
        tmp = next;
    }
    *head = NULL;
}

int bash_scripting(const char *filename, mini_t *mini)
{
    struct stat st;
    char *buffer = NULL;
    char **input = NULL;

    if (stat(filename, &st) != 0)
        return 84;
    buffer = open_bash_script(filename, &st);
    if (buffer == NULL)
        return 84;
    input = my_str_to_word_array(buffer, '\n');
    parse_script_input(input, mini);
    free(buffer);
    free_word_array(input);
    free_var_list(&(mini->var_list));
    return 0;
}
