/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** calculator_parser
*/

#include "scripting.h"

token_t get_next_token(parser_t *parser)
{
    int value = 0;
    char c;

    while (parser->input[parser->position] == ' '
        || parser->input[parser->position] == '\t')
        parser->position++;
    c = parser->input[parser->position];
    if (c == '\0')
        return (token_t){TOKEN_EOF, 0};
    if (is_digit(c))
        return token_digit(c, parser, value);
    for (int i = TOKEN_PLUS; i <= TOKEN_RPAREN; i++) {
        if (tokens_list[i] && c == tokens_list[i][0]) {
            parser->position++;
            return (token_t){i, 0};
        }
    }
}

void consume(parser_t *parser, token_type_t token_type)
{
    if (parser->current_token.type == token_type)
        parser->current_token = get_next_token(parser);
    else
        return;
}

int factor(parser_t *parser, mini_t *mini)
{
    int value = 0;

    if (parser->current_token.type == TOKEN_NUMBER) {
        value = parser->current_token.value;
        consume(parser, TOKEN_NUMBER);
    } else if (parser->current_token.type == TOKEN_LPAREN) {
        consume(parser, TOKEN_LPAREN);
        value = expr(parser, mini);
        consume(parser, TOKEN_RPAREN);
    } else
        return 0;
    return value;
}

int termm(parser_t *parser, mini_t *mini)
{
    int value = factor(parser, mini);

    while (parser->current_token.type == TOKEN_MULTIPLY ||
            parser->current_token.type == TOKEN_DIVIDE)
        divide_or_multiply(parser, &value, mini);
    return value;
}

int expr(parser_t *parser, mini_t *mini)
{
    int value = termm(parser, mini);

    while (parser->current_token.type == TOKEN_PLUS ||
            parser->current_token.type == TOKEN_MINUS)
        add_or_substract(parser, &value, mini);
    return value;
}
