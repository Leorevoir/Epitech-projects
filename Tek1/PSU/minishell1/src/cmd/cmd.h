/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** cmd
*/

#include "minishell.h"

#ifndef CMD_H_
    #define CMD_H_

extern const command_mapping_t commands[];

void my_cd(cmd_t *cmd);
void my_env(cmd_t *cmd);
void set_env(cmd_t *cmd);
void unset_env(cmd_t *cmd);
void execute_cmd(cmd_t *cmd);
void check_segfault(int status, cmd_t *cmd);

#endif /* !CMD_H_ */
