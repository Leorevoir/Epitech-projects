/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** parse_bash
*/

#include "scripting.h"

static void if_syntax(void)
{
    printf("\033[1;31mERROR: syntaxe incorrecte. ");
    printf("Utilisez:\nif ( condition ) then\n");
    printf("    instructions\nendif\033[0m\n");
    exit(1);
}

static int is_if_operator(const char *str, int start)
{
    for (int i = 0; i < sizeof(ope) / sizeof(ope[0]); i++) {
        if (strncmp(&str[start], ope[i], strlen(ope[i])) == 0) {
            return i;
        }
    }
    return -1;
}

static void it_is_actually_an_if(const char *str, my_if_t *my_if)
{
    int index = -1;

    my_if->condition = extract_string(str, '(', ')');
    for (int i = 0; my_if->condition[i] != '\0'; i++) {
        index = is_if_operator(my_if->condition, i);
        if (index != -1) {
            my_if->op = i_hate_spaces(strdup(ope[index]));
            my_if->before = i_hate_spaces(strndup(my_if->condition, i));
            my_if->after = i_hate_spaces(strdup(&my_if->condition[
                i + strlen(ope[index])]));
            break;
        }
    }
    if (my_if->op == NULL)
        if_syntax();
}

static void parse_one_more_time_if(char *input, mini_t *mini)
{
    free(mini->cleaned);
    mini->cleaned = remove_tab(strdup(input));
    if (strncmp(mini->cleaned, "set ", 4) == 0)
        set_var(mini);
    if (strncmp(mini->cleaned, "echo", 4) == 0)
        my_echo(mini);
    if (strncmp(mini->cleaned, "unset ", 6) == 0)
        unset_var(mini);
    if (mini->cleaned[0] == '@')
        omg_handle_script_0_o(mini, my_trim(mini->cleaned + 1));
    mini->my_if->is_if = false;
}

static void execute_the_if(mini_t *mini)
{
    if (if_is_true(mini->my_if, mini))
        parse_one_more_time_if(mini->my_if->array[mini->my_if->i - 1], mini);
    else
        return;
}

static void is_instruction_an_if(mini_t *mini)
{
    static bool have_then = false;
    static bool is_endif = false;

    if (strncmp(mini->cleaned, "if", 2) == 0
        && !mini->my_if->is_if && !is_endif) {
        if (strstr(mini->cleaned, "then") == NULL)
            if_syntax();
        it_is_actually_an_if(mini->cleaned, mini->my_if);
        mini->my_if->is_if = true;
        have_then = true;
    }
    if (strcmp(mini->cleaned, "endif") == 0
        && mini->my_if->is_if && !is_endif && have_then) {
        is_endif = true;
        execute_the_if(mini);
    }
}

static bool what_instruction_is_it(mini_t *mini)
{
    if (!mini->my_if->is_if) {
        if (strncmp(mini->cleaned, "set ", 4) == 0)
            set_var(mini);
        if (strncmp(mini->cleaned, "echo", 4) == 0)
            my_echo(mini);
        if (strncmp(mini->cleaned, "unset ", 6) == 0)
            unset_var(mini);
        if (mini->cleaned[0] == '@')
            return omg_handle_script_0_o(mini, my_trim(mini->cleaned + 1));
    }
    is_instruction_an_if(mini);
}

my_if_t *init_my_if(void)
{
    my_if_t *my_if = (my_if_t *)malloc(sizeof(my_if_t));

    if (my_if != NULL) {
        my_if->condition = NULL;
        my_if->inside = NULL;
        my_if->i = 0;
        my_if->array = NULL;
        my_if->op = NULL;
        my_if->before = NULL;
        my_if->after = NULL;
        my_if->is_if = false;
    }
    return my_if;
}

void parse_script_input(char **array, mini_t *mini)
{
    my_if_t *my_if = init_my_if();

    mini->my_if = NULL;
    mini->my_if = my_if;
    mini->cleaned = NULL;
    mini->my_if->array = array;
    for (int i = 1; array[i]; i++) {
        mini->cleaned = strdup(array[i]);
        mini->my_if->i = i;
        what_instruction_is_it(mini);
        free(mini->cleaned);
    }
    free(my_if->before);
    free(my_if->after);
    free(my_if->condition);
    free(my_if->inside);
    free(my_if);
}
