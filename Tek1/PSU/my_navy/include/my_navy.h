/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** my_navy
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_
    #define MY static
    #define EXTERN *global_game_info
    #define IS =
    #define HIT 1
    #define MISS 0

typedef struct ship_s {
    int length;
    int ipos1;
    char cpos1;
    int ipos2;
    char cpos2;
} ship_t;

typedef struct map_s {
    int grid[8][8];
    int enemy_grid[8][8];
} map_t;

typedef struct game_info_s {
    pid_t enemy_pid;
    int connected;
    int is_my_turn;
    int attack_result;
    int b_pos[16];
    int b_index;
    int attack_status;
} game_info_t;

void free_all(FILE *file, char *line);
int my_atoi(char *str);
void init_grid(map_t *map);
int my_strlen(const char *str);
void handle_help_option(void);
void print_grid(map_t *map);
int *convert_to_binary(int number);
int convert_from_binary(int *binary);
void print_enemy_grid(map_t *map);
int receive_attack_result(int *row, int *col, game_info_t *game_info);
int my_navy(int argc, char **argv);
int my_strcmp(const char *s1, const char *s2);
int my_strtok(const char *line, char *token, const char delimiter,
    size_t *position);
int is_valid_ship(char *line);
void free_all(FILE *file, char *line);
int handle_error(char *filepath);
int check_letter(char cpos1, char cpos2);
int check_format_letter(int length, char cpos1, char cpos2);
int check_length(ship_t *ship);
int check_int(ship_t *ship);
int read_map(const char *filename, map_t *map);
void setup_signal_handling(game_info_t *game_info);
void send_attack(pid_t enemy_pid, int row, int col);
int game_not_finished(map_t *my_map);
void signal_handler(int signum, siginfo_t *info, void *context);
void update_my_grid(map_t *my_map, int row, int col, int result);
void fill_grid(map_t *map, char *start, char *end, int ship_length);
int attack(game_info_t *game_info, map_t *my_map, map_t *enemy_map);
void update_my_grid(map_t *enemy_map, int row, int col, int result);

#endif /* !MY_NAVY_H_ */
