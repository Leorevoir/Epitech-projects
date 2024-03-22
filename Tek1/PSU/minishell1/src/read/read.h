/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** read
*/

#include "minishell.h"

#ifndef READ_H_
    #define READ_H_

void add_to_arguments(cmd_t *cmd, int arg_count);
void check_ctr_d(ssize_t nread, char *line, cmd_t *cmd);

#endif /* !READ_H_ */
