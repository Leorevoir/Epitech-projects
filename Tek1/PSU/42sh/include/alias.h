/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-alexandre.bacha
** File description:
** alias
*/

#include "my.h"

#ifndef ALIAS_H_
    #define ALIAS_H_

//---------- CREATE ALIAS ----------//
bool create_alias(char *input, alias_t **head);
void create_new_alias(char **cmd, alias_t **head);
void load_aliases_from_bashrc(const char *filename, alias_t **head);
//---------- FIND ALIAS ----------//
char *get_bashrc_path(void);
void is_input_alias(mini_t *mini, alias_t *head);
char *get_alias_by_name(char *alias_name, alias_t **head);
//---------- REMOVE ALIAS ----------//
void remove_all_aliases(alias_t **head);
void remove_alias_by_name(char *alias_name, alias_t **head);

#endif /* !ALIAS_H_ */
