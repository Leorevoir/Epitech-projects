/*
** EPITECH PROJECT, 2024
** main
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "alias.h"
#include "scripting.h"
#include "struct.h"

void sys_commands(void)
{
    FILE *fp = popen("man -k .", "r");
    FILE *output_file = fopen("system_commands.txt", "w");
    char path[1035];
    char *token;

    if (fp == NULL) {
        printf("Failed to get command\n");
        exit(84);
    }
    if (output_file == NULL) {
        printf("Failed to open system commands file\n");
        exit(84);
    }
    while (fgets(path, sizeof(path), fp) != NULL) {
        token = strtok(path, " ");
        if (token != NULL)
            fprintf(output_file, "%s\n", token);
    }
    pclose(fp);
    fclose(output_file);
}

mini_t *init_mini(void)
{
    mini_t *mini = malloc(sizeof(mini_t));

    mini->path = NULL;
    mini->full_cmd = NULL;
    mini->oldpwd = NULL;
    mini->nooldpwd = malloc(sizeof(char) * 256);
    mini->nooldpwd[0] = '\0';
    mini->var_list = NULL;
    mini->alias = NULL;
    mini->is_tty = 0;
    mini->history = NULL;
    return mini;
}

int main(int ac, char **av, char **env)
{
    int caca = 0;
    mini_t *mini = init_mini();

    sys_commands();
    load_aliases_from_bashrc(get_bashrc_path(), &(mini->alias));
    if (ac == 2)
        return bash_scripting(av[1], mini);
    if (ac > 2)
        return (84);
    my_list(mini, env);
    caca = minishell(mini, env);
    return (caca);
}
