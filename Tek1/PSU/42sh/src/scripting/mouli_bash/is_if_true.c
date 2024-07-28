/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** is_if_true
*/

#include "scripting.h"

static bool parse_if_conditions(my_if_t *my_if)
{
    int before_val = atoi(my_if->before);
    int after_val = atoi(my_if->after);

    if (strcmp(my_if->op, "!=") == 0)
        return before_val != after_val;
    if (strcmp(my_if->op, "==") == 0)
        return before_val == after_val;
    if (strcmp(my_if->op, ">") == 0)
        return before_val > after_val;
    if (strcmp(my_if->op, "<") == 0)
        return before_val < after_val;
    if (strcmp(my_if->op, ">=") == 0)
        return before_val >= after_val;
    if (strcmp(my_if->op, "<=") == 0)
        return before_val <= after_val;
    return false;
}

static char *is_it_a_variable(char *var, mini_t *mini)
{
    char *var_value = NULL;

    if (var[0] == '$' && var[1]) {
        var_value = get_var_value(mini->var_list, var + 1);
        if (var_value == NULL) {
            fprintf(stderr, "%s: Undefined variable.", var + 1);
            exit(1);
        }
        strcpy(var, var_value);
    }
    return var;
}

bool if_is_true(my_if_t *my_if, mini_t *mini)
{
    my_if->before = is_it_a_variable(my_if->before, mini);
    my_if->after = is_it_a_variable(my_if->after, mini);
    return parse_if_conditions(my_if);
}
