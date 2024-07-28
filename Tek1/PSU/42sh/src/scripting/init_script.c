/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** init_script
*/

#include "scripting.h"

void copy_variable_value(const char **local_current, char **temp_result,
    mini_t *mini)
{
    char buffer[BUFFER_SIZE];
    char *end_var = buffer;
    char *value = NULL;

    while (isalnum(**local_current) || **local_current == '_') {
        BFR_CPY;
        (*local_current)++;
    }
    *end_var = '\0';
    value = get_var_value(mini->var_list, buffer);
    if (value)
        while (*value)
            VLUE_CPY;
    else {
        MNEY_CPY;
        strcpy(*temp_result, buffer);
        (*temp_result) += strlen(buffer);
    }
}

char *prepare_expression(mini_t *mini, const char *input)
{
    char *result = malloc(strlen(input) + 1);
    char *temp_result = result;
    const char *current = input;

    while (*current) {
        if (*current == '$') {
            current++;
            copy_variable_value(&current, &temp_result, mini);
        } else {
            *temp_result = *current;
            temp_result++;
            current++;
        }
    }
    *temp_result = '\0';
    return result;
}

static void my_very_first_operation(mini_t *mini, char *var_name,
    char *expression)
{
    char *prepared_expr = prepare_expression(mini, my_trim(expression));
    parser_t parser = {prepared_expr, 0, {0, 0}};
    char result_str[MAX_BUFFER];
    int result = 0;

    parser.current_token = get_next_token(&parser);
    result = expr(&parser, mini);
    free(prepared_expr);
    sprintf(result_str, "%d", result);
    add_var(&(mini->var_list), var_name, result_str);
}

bool omg_handle_script_0_o(mini_t *mini, char *input)
{
    char *good = i_hate_spaces(input);
    char *var_name = strtok((char *)good, "=");
    char *expression = NULL;

    if (var_name == NULL)
        return false;
    var_name = my_trim(var_name);
    expression = strtok(NULL, "");
    if (expression == NULL)
        return false;
    my_very_first_operation(mini, var_name, expression);
    return true;
}

bool unset_var(mini_t *mini)
{
    char *var_name = my_trim(mini->cleaned + 6);

    if (var_name)
        remove_var(&(mini->var_list), var_name);
    else
        return false;
    return true;
}

static bool basic_terminal_script(mini_t *mini, char **env)
{
    if (strncmp(mini->cleaned, "echo", 4) == 0) {
        my_echo(mini);
        return true;
    }
    if (strncmp(mini->cleaned, "set ", 4) == 0)
        if (set_var(mini))
            return true;
    if (strncmp(mini->cleaned, "unset ", 6) == 0)
        if (unset_var(mini))
            return true;
    if (mini->cleaned[0] == '@')
        return omg_handle_script_0_o(mini, my_trim(mini->cleaned + 1));
    return false;
}

static void advanced_shell_script(mini_t *mini, char **env)
{
    mini->nona = true;
    system("clear");
    printf("\033[1;36m");
    printf("Bienvenue dans la version 1.1 de ");
    printf("\033[1;35m");
    printf("nona");
    printf("\033[0m\n");
}

bool is_scripting(mini_t *mini, char **env)
{
    if (basic_terminal_script(mini, env))
        return true;
    if (strncmp(mini->cleaned, "nona", 4) == 0) {
        advanced_shell_script(mini, env);
        return true;
    }
    return false;
}
