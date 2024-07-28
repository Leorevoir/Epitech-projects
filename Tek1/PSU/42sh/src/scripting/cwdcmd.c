/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** special_var
*/

#include "scripting.h"
#include "alias.h"

static bool has_directory_changed(mini_t *mini)
{
    char *cwd = (char *)malloc(4096);

    if (getcwd(cwd, 4096) != NULL) {
        if (strcmp(cwd, get_var_value(mini->var_list, "cwd")) != 0) {
            add_var(&(mini->var_list), "cwd", cwd);
            return true;
        }
    }
}

static bool does_alias_exists(alias_t *head, char *name)
{
    alias_t *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0)
            return true;
        current = current->next;
    }
    return false;
}

void update_cmdcwd(mini_t *mini, char **env)
{
    if (has_directory_changed(mini)) {
        if (does_alias_exists(mini->alias, "cwdcmd")) {
            free_word_array(mini->tab_clean);
            mini->tab_clean = my_str_to_word_array("cwdcmd", ' ');
            is_input_alias(mini, mini->alias);
            mini->rtn = my_builtins(mini, env);
        }
    }
    free_word_array(mini->tab_clean);
}
