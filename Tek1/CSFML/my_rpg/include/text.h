/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** text
*/

#include "macro.h"
#include "object.h"

#ifndef TEXT_H_
    #define TEXT_H_

////////// TEMP PARSING STRUCT //////////////
typedef struct temp_s {
    char *name;
    char *text;
    char *quest;
    int num;
} temp_t;

////////// TEMP DISPLAY STRUCT //////////////
typedef struct tmp_txt_s {
    sfClock *clock;
    sfTime elapsed_time;
    float elapsed_seconds;
    size_t text_length;
    sfVector2f pos;
    char *displayed_text;
} tmp_txt_t;

////////// DIALOGUE NPC //////////////
typedef struct dialogue_s {
    char *name;
    char *text;
    char *quest;
    int num;
    struct dialogue_s *next;
} dialogue_t;

////////// TEXT DISPLAY //////////////
typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfText *name;
    sfText *quest;
    sfText *description;
    sfText *validate;
    object_t picture;
    char *txt_to_print;
    bool continue_display;
} text_t;

#endif /* !TEXT_H_ */
