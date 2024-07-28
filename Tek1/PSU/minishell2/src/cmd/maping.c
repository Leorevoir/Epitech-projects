/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell2-leo.quinzler
** File description:
** maping
*/

#include "cmd.h"

const command_mapping_t commands[] = {
    {"cd", my_cd}, {"env", my_env}, {"setenv", set_env},
    {"unsetenv", unset_env},
    {NULL, execute_cmd}
};
