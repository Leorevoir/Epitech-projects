/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** nona
*/

#include "scripting.h"
#include <string.h>

static void nona_calculate(mini_t *mini, char *expression)
{
    parser_t parser = {expression, 0, 0};
    int result = 0;

    parser.current_token = get_next_token(&parser);
    result = expr(&parser, mini);
    if (!mini->rtn)
        printf("%d\n", result);
}

static void nona_echo(mini_t *mini, char *cmd)
{
    char *output = prepare_echo(mini, cmd);

    printf("%s\n", output);
    free(output);
}

static void nona_var(mini_t *mini, char *name, char *value)
{
    char *trimmed_name = i_hate_spaces(strdup(name));
    char *trimmed_value = i_hate_spaces(strdup(value));

    add_var(&(mini->var_list), trimmed_name, trimmed_value);
    free(trimmed_name);
    free(trimmed_value);
}

static void handle_expression(mini_t *mini, char *expression, char *var_name)
{
    parser_t parser = {expression, 0, {0, 0}};
    int result = 0;
    char result_str[32];

    parser.current_token = get_next_token(&parser);
    result = expr(&parser, mini);
    sprintf(result_str, "%d", result);
    add_var(&(mini->var_list), var_name, result_str);
}

static void input_is_variable(mini_t *mini, char *better)
{
    char *name = i_hate_spaces(better);
    char *expression = strtok(NULL, "");

    if (expression != NULL) {
        expression = prepare_expression(mini, expression);
        handle_expression(mini, expression, name);
    }
}

static void parse_one_more_time(char *cmd, mini_t *mini, bool execute)
{
    char *cmd_copy = NULL;
    char *token = NULL;
    char *better = NULL;
    char *name = NULL;
    char *expression = NULL;

    if (!execute)
        return;
    cmd_copy = strdup(cmd);
    token = strtok(cmd_copy, "=");
    better = remove_tab(token);
    if (strncmp(better, "echo ", 5) == 0)
        nona_echo(mini, better + 5);
    else
        input_is_variable(mini, better);
    free(cmd_copy);
    free(better);
}

static void go_to_the_if(char **cmd, int size, char *condition, mini_t *mini)
{
    if (!condition)
        return;
    if (nona_conditional(condition + 3, mini)) {
        printf("\033[1m\t\t\t\t[DEBUG]\033[0m true\n");
        for (int i = 0; i < size; i++)
            parse_one_more_time(cmd[i], mini, true);
    } else
        printf("\033[1m\t\t\t\t[DEBUG]\033[0m false\n");
}

static void parse_nona_instructions(mini_t *mini, char **cmd, cmd_pos_t *pos)
{
    bool correct = false;

    pos->if_block_count = 0;
    for (pos->i = 0; cmd[pos->i]; pos->i++) {
        is_it_an_if(cmd, &correct, mini, pos);
        if (!pos->is_inside_if_block)
            parse_one_more_time(cmd[pos->i], mini, true);
    }
    if (correct && pos->is_done)
        go_to_the_if(pos->if_block_commands, pos->if_block_count,
        pos->if_condition, mini);
    free_command_array(pos->if_block_commands, pos->if_block_count,
        pos->if_condition);
    pos->if_block_commands = NULL;
}

void execute_nona_commands(mini_t *mini, char *commands)
{
    char **cmds = my_str_to_word_array(commands, '\n');
    cmd_pos_t *pos = malloc(sizeof(cmd_pos_t));

    memset(pos, 0, sizeof(cmd_pos_t));
    if (cmds) {
        parse_nona_instructions(mini, cmds, pos);
        free_word_array(cmds);
    }
    free(pos);
}

int nona_loop(mini_t *mini, char **env, size_t bufsize, char *b)
{
    char *cmd = (char *)calloc(1, 10240);

    while (mini->nona) {
        printf("~> ");
        if (getline(&b, &bufsize, stdin) == -1) {
            printf("exit nona\n");
            mini->nona = false;
            clearerr(stdin);
            free(cmd);
            return minishell_loop(mini, env, bufsize);
        }
        if (strcmp(b, "go\n") == 0) {
            execute_nona_commands(mini, cmd);
            memset(cmd, 0, 10240);
        } else
            strcat(cmd, b);
    }
    free(cmd);
    return 0;
}
