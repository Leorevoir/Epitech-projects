/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** scripting
*/

#include "my.h"

#ifndef SCRIPTING_H_
    #define SCRIPTING_H_
    #define MAX_BUFFER 5012
    #define BUFFER_SIZE 512
    #define OP_SIZE 6
    #define BFR_CPY (*end_var++ = **local_current)
    #define VLUE_CPY (*(*temp_result)++ = *value++)
    #define MNEY_CPY (*(*temp_result)++ = '$')
    #define MOVE_PTR *temp_result++ = *current++

typedef struct {
    size_t size;
    int in;
    int out;
} echo_t;

typedef struct tmp_delim_s {
    int i;
    int count;
} tmp_delim_t;

typedef enum token_type_s {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    NB_TOKENS,
    TOKEN_EOF
} token_type_t;

typedef struct token_s {
    token_type_t type;
    int value;
} token_t;

static const char *ope[] = {
    "==",
    ">=",
    "<=",
    ">",
    "<",
    "!="
};

static const char *ops[] = {
    "-eq",
    "-ne",
    "-lt",
    "-le",
    "-gt",
    "-ge"
};

static const char *tokens_list[] = {
    NULL,
    "+",
    "-",
    "*",
    "/",
    "(",
    ")",
    NULL,
    NULL,
};

typedef struct parser_s {
    char *input;
    int position;
    token_t current_token;
} parser_t;

//-------------------- SCRIPTING --------------------//
void my_echo(mini_t *mini);
bool is_scripting(mini_t *mini, char **env);
bool nona_conditional(char *input, mini_t *mini);
char *prepare_echo(mini_t *mini, const char *input);
int nona_loop(mini_t *mini, char **env, size_t bufsize, char *b);
int minishell_loop(mini_t *mini, char **env, size_t bufsize);
int bash_scripting(const char *filename, mini_t *mini);
bool omg_handle_script_0_o(mini_t *mini, char *input);
void parse_script_input(char **array, mini_t *mini);
bool if_is_true(my_if_t *my_if, mini_t *mini);
//-------------------- VAR --------------------//
bool set_var(mini_t *mini);
bool unset_var(mini_t *mini);
void update_cmdcwd(mini_t *mini, char **env);
void remove_var(var_t **var_list, char *name);
char *get_var_value(var_t *var_list, char *name);
void add_var(var_t **var_list, char *name, char *value);
//-------------------- CALCULATOR --------------------//
int is_digit(char c);
int termm(parser_t *parser, mini_t *mini);
int expr(parser_t *parser, mini_t *mini);
token_t get_next_token(parser_t *parser);
int factor(parser_t *parser, mini_t *mini);
void consume(parser_t *parser, token_type_t token_type);
token_t token_digit(char c, parser_t *parser, int value);
void divide_or_multiply(parser_t *parser, int *value, mini_t *mini);
void add_or_substract(parser_t *parser, int *value, mini_t *mini);
char *prepare_expression(mini_t *mini, const char *input);
//-------------------- TOOLS --------------------//
char *remove_tab(char *str);
char *i_hate_spaces(char *str);
void free_command_array(char **array, int j, char *str);
void add_string_to_array(char ***array, const char *string, int *count);
void is_it_an_if(char **cmd, bool *correct, mini_t *mini, cmd_pos_t *pos);
char *extract_string(const char *str, const char c1, const char c2);

#endif /* !SCRIPTING_H_ */
