/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** core
*/

#include "includes.h"

#ifndef CORE_H_
    #define CORE_H_

typedef struct champ_s {
    int id;
    header_t header;
    unsigned char *inst;
    char **tab;
    char **reg;
    int starting_pos;
    int pc;
    int carry;
    int alive;
    bool fork;
    bool dont_move;
    struct champ_s *next;
} champ_t;

typedef struct war_s {
    int num_champ;
    int dump;
    int last;
    bool done;
    unsigned char *arena;
    champ_t *head;
    char **array;
} war_t;

typedef struct context_s {
    war_t *war;
    const unsigned char *arena;
    int i;
    int index;
    char *buffer;
    champ_t *champ_by_pc;
    const char *color;
} context_t;

typedef int (*inst_func_t)(champ_t *, int i, war_t *);

/// @brief hex code tab
extern char *my_hex_code[];

/// @brief function pointer tab
extern inst_func_t func[];

//---------- PARSER ----------//
int parse_arguments(int argc, char **argv);
int flag_are_correct(char **argv, int *index, war_t *war);
int parse_cor_file(int argc, char **argv, int index, war_t *war);

//---------- CHAMPIONS ----------//
bool game_loop(war_t *war, champ_t *head);
champ_t *remove_champ(champ_t *head, char *name);
int create_champ(int fd, war_t *war, champ_t *head, int count);
champ_t *add_champ(champ_t *head, header_t new_header, int count,
    unsigned char *inst);
champ_t *remove_champ_by_name(champ_t *head, champ_t *current, champ_t *prev);

//---------- TOOLS ----------//
void free_war(war_t *war);
char *int_to_hex_string(int num);
const char *get_color_by_id(int id);
void str_to_array(char ***tmp, char *str);
size_t unsigned_char_len(unsigned char c);
champ_t *add_champ(champ_t *head, header_t new_header, int count,
    unsigned char *inst);
champ_t *find_champ_by_instruction(champ_t *head, const unsigned char *arena,
    int index);

//---------- DISPLAY ----------//
unsigned char *init_arena(void);
void launch_game(war_t *war, champ_t *head);
void init_starting_pos(war_t *war, champ_t *head);
void print_info(war_t *war, const char *color);
void print_arena(const unsigned char *arena, war_t *war);

//---------- INSTRUCTIONS ----------//
int my_live(champ_t *champ, int i, war_t *war);
int my_ld(champ_t *champ, int i, war_t *war);
int my_st(champ_t *champ, int i, war_t *war);
int my_add(champ_t *champ, int i, war_t *war);
int my_sub(champ_t *champ, int i, war_t *war);
int my_and(champ_t *champ, int i, war_t *war);
int my_or(champ_t *champ, int i, war_t *war);
int my_xor(champ_t *champ, int i, war_t *war);
int my_zjmp(champ_t *champ, int i, war_t *war);
int my_ldi(champ_t *champ, int i, war_t *war);
int my_sti(champ_t *champ, int i, war_t *war);
int my_ffork(champ_t *champ, int i, war_t *war);
int my_lld(champ_t *champ, int i, war_t *war);
int my_lldi(champ_t *champ, int i, war_t *war);
int my_lfork(champ_t *champ, int i, war_t *war);
int my_aff(champ_t *champ, int i, war_t *war);

#endif /* !CORE_H_ */
