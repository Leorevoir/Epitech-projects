/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** my_echo
*/

#include "scripting.h"

void free_word_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    array = NULL;
}

static char *extract_variable_name(const char *input, int *length)
{
    char *var_name = NULL;
    int len = 0;

    while (isalnum(input[len]) || input[len] == '_')
        len++;
    *length = len;
    var_name = (char *)malloc(len + 1);
    strncpy(var_name, input, len);
    var_name[len] = '\0';
    return var_name;
}

static void make_place_for_my_var(char *var_value, char **output,
    echo_t *echo, int len)
{
    size_t too_small = 0;
    char *new_output = NULL;

    too_small = strlen(var_value);
    while (echo->out + too_small >= echo->size) {
        echo->size *= 2;
        new_output = realloc(*output, echo->size);
        *output = new_output;
    }
    memcpy(*output + echo->out, var_value, too_small);
    echo->out += too_small;
    echo->in += len + 1;
}

static void omg_it_is_a_variable(mini_t *mini, const char *input,
    char **output, echo_t *echo)
{
    char *var_name = NULL;
    char *var_value = NULL;
    int len = 0;

    var_name = extract_variable_name(&input[echo->in + 1], &len);
    var_value = get_var_value(mini->var_list, var_name);
    if (var_value == NULL) {
        echo->in += len + 1;
        free(var_name);
        return;
    }
    make_place_for_my_var(var_value, output, echo, len);
    free(var_name);
}

static void omg_it_is_not_a_variable(mini_t *mini, const char *input,
    char **output, echo_t *echo)
{
    char *new_output = NULL;

    if (echo->out >= echo->size - 1) {
        echo->size *= 2;
        new_output = realloc(*output, echo->size);
        *output = new_output;
    }
    (*output)[echo->out] = input[echo->in];
    echo->out++;
    echo->in++;
}

char *prepare_echo(mini_t *mini, const char *input)
{
    echo_t echo = {.size = BUFFER_SIZE, .out = 0, .in = 0};
    char *output = malloc(echo.size);

    while (input[echo.in] != '\0') {
        if (input[echo.in] == '$' && input[echo.in + 1])
            omg_it_is_a_variable(mini, input, &output, &echo);
        else
            omg_it_is_not_a_variable(mini, input, &output, &echo);
    }
    output[echo.out] = '\0';
    return output;
}

char *remove_quotes(const char *input)
{
    int len = strlen(input);
    char *output = malloc((len + 1) * sizeof(char));
    int j = 0;

    if (!output)
        return NULL;
    for (int i = 0; i < len; ++i) {
        if (input[i] != '"') {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';
    return output;
}

void my_echo(mini_t *mini)
{
    char *cleaned = mini->cleaned + 4;
    char *output = NULL;

    if (strlen(cleaned) == 0) {
        printf("\n");
        return;
    }
    output = prepare_echo(mini, remove_quotes(mini->cleaned + 5));
    printf("%s\n", output);
    free(output);
}
