/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** conditional
*/

#include "scripting.h"

static void error_conditional(void)
{
    printf("\033[1;31mERROR: syntaxe incorrecte. ");
    printf("Utilisez:\nif [ condition ]; then\n");
    printf("\tinstructions\nfi\033[0m\n");
}

static bool parse_operator_2(char *before, char *after, int i)
{
    if (strcmp(ops[i], "-ne") == 0) {
        if (atoi(before) != atoi(after))
            return true;
        else
            return false;
    }
    if (strcmp(ops[i], "-lt") == 0) {
        if (atoi(before) < atoi(after))
            return true;
        else
            return false;
    }
    if (strcmp(ops[i], "-le") == 0) {
        if (atoi(before) <= atoi(after))
            return true;
        else
            return false;
    }
    return false;
}

static bool parse_operator(char *before, char *after, int i)
{
    if (strcmp(ops[i], "-ge") == 0) {
        if (atoi(before) >= atoi(after))
            return true;
        else
            return false;
    }
    if (strcmp(ops[i], "-gt") == 0) {
        if (atoi(before) > atoi(after))
            return true;
        else
            return false;
    }
    if (strcmp(ops[i], "-eq") == 0) {
        if (atoi(before) == atoi(after))
            return true;
        else
            return false;
    }
    return parse_operator_2(before, after, i);
}

static char *check_conditional_brackets(char *closing_bracket, int i,
    char *operator_found)
{
    char *after = NULL;

    if (closing_bracket != NULL) {
        after = strndup(operator_found + strlen(ops[i]),
        closing_bracket - (operator_found + strlen(ops[i])));
        after = i_hate_spaces(after);
    } else {
        error_conditional();
        after = strdup("");
    }
    return after;
}

static bool check_conditional_syntax(char *input,
    char *operator_found, int i)
{
    char *before = NULL;
    char *after = NULL;
    char *closing_bracket = NULL;
    bool is = false;

    if (operator_found != NULL) {
        before = strndup(input, operator_found - input);
        before = i_hate_spaces(before);
        closing_bracket = strchr(operator_found, ']');
        after = check_conditional_brackets(closing_bracket, i,
            operator_found);
        is = parse_operator(before, after, i);
        free(before);
        free(after);
    } else
        error_conditional();
    return is;
}

static bool first_syntax_check(const char *input)
{
    size_t i = 0;
    bool then = false;
    bool point_virgule = false;

    for (; i < strlen(input); i++) {
        if (input[i] == ']' && input[i + 1] == ';') {
            point_virgule = true;
            i++;
        }
        if (input[i + 1] == 't' && input[i + 2] == 'h'
            && input[i + 3] == 'e' && input[i + 4] == 'n') {
            then = true;
            break;
        }
    }
    if (then && point_virgule)
        return true;
    return false;
}

static char *process_variable(char **current, char *temp_result, mini_t *mini)
{
    char var_name[BUFFER_SIZE];
    char *value = NULL;
    int i = 0;

    (*current)++;
    while (isalnum(**current) || **current == '_') {
        var_name[i] = **current;
        i++;
        (*current)++;
    }
    var_name[i] = '\0';
    value = get_var_value(mini->var_list, var_name);
    if (value) {
        strcpy(temp_result, value);
        temp_result += strlen(value);
        free(value);
    }
    return temp_result;
}

static char *resolve_variables(char *input, mini_t *mini)
{
    char *result = (char *)malloc(strlen(input) + 1);
    char *temp_result = result;
    char *current = input;

    while (*current) {
        if (*current == '$')
            temp_result = process_variable(&current, temp_result, mini);
        else
            MOVE_PTR;
    }
    *temp_result = '\0';
    return result;
}

bool nona_conditional(char *input, mini_t *mini)
{
    char *op_found = NULL;
    char *resolved_input = NULL;
    int i = 0;
    bool is = false;

    input = i_hate_spaces(input);
    if (input[0] == '[')
        input++;
    resolved_input = resolve_variables(input, mini);
    for (; i < OP_SIZE; i++) {
        op_found = strstr(resolved_input, ops[i]);
        if (op_found != NULL)
            break;
    }
    if (first_syntax_check(resolved_input))
        is = check_conditional_syntax(resolved_input, op_found, i);
    else
        error_conditional();
    free(resolved_input);
    return is;
}
