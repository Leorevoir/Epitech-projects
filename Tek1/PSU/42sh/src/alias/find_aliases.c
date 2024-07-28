/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** find_aliases
*/

#include "alias.h"

static bool is_alias(mini_t *mini, char *cmd)
{
    char **words = my_str_to_word_array(cmd, ' ');
    alias_t *current = mini->alias;
    bool is_alias = false;

    if (!words || !words[0]) {
        free_word_array(words);
        return false;
    }
    while (current) {
        if (my_strcmp(current->name, words[0]) == 0) {
            is_alias = true;
            break;
        }
        current = current->next;
    }
    free_word_array(words);
    return is_alias;
}

static void resolve_aliases(mini_t *mini, alias_t *current, alias_t *head)
{
    if (my_strcmp(current->name, mini->tab_clean[0]) == 0) {
        if (is_alias(mini, current->cmd)) {
            mini->tab_clean = my_str_to_word_array(current->cmd, ' ');
            is_input_alias(mini, head);
        } else {
            free_word_array(mini->tab_clean);
            mini->tab_clean = my_str_to_word_array(current->cmd, ' ');
        }
        return;
    }
}

void is_input_alias(mini_t *mini, alias_t *head)
{
    alias_t *current = head;

    while (current) {
        resolve_aliases(mini, current, head);
        current = current->next;
    }
    return;
}
