/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** calculator
*/

#include "scripting.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

token_t token_digit(char c, parser_t *parser, int value)
{
    value = 0;
    while (is_digit(parser->input[parser->position])) {
        value = value * 10 + (parser->input[parser->position] - '0');
        parser->position++;
    }
    return (token_t){TOKEN_NUMBER, value};
}

void divide_or_multiply(parser_t *parser, int *value, mini_t *mini)
{
    int right = 0;
    token_type_t op = parser->current_token.type;

    consume(parser, op);
    right = factor(parser, mini);
    if (op == TOKEN_MULTIPLY)
        *value *= right;
    if (op == TOKEN_DIVIDE) {
        if (right == 0) {
            fprintf(stderr, "Division by 0.\n");
            mini->rtn = 1;
            return;
        }
        *value /= right;
    }
}

void add_or_substract(parser_t *parser, int *value, mini_t *mini)
{
    token_type_t op = {0};
    int right = 0;

    op = parser->current_token.type;
    consume(parser, op);
    right = termm(parser, mini);
    if (op == TOKEN_PLUS)
        *value += right;
    else if (op == TOKEN_MINUS)
        *value -= right;
}
