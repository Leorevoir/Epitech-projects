/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** my_attack
*/

#include "../include/my_navy.h"
#include "../include/my_printf.h"

MY game_info_t EXTERN IS NULL;

int receive_attack_result(int *row, int *col, game_info_t *game_info)
{
    int position;

    while (game_info->attack_status == 0) {
        pause();
    }
    position = convert_from_binary(game_info->b_pos);
    *row = position / 8;
    *col = position % 8;
    game_info->b_index = 0;
    game_info->attack_status = 0;
    return (position & 1) ? HIT : MISS;
}

void binary_data(int signum, game_info_t *game_info)
{
    if (game_info->b_index < 16) {
        game_info->b_pos[game_info->b_index] = (signum == SIGUSR2);
        game_info->b_index++;
    }
    if (game_info->b_index == 16) {
        game_info->attack_status = 1;
    }
}

void signal_handler(int signum, siginfo_t *info, void *context)
{
    game_info_t *game_info = global_game_info;

    (void)context;
    if (signum == SIGUSR1 && game_info->connected == 0) {
        game_info->enemy_pid = info->si_pid;
        kill(game_info->enemy_pid, SIGUSR1);
        game_info->connected = 1;
    } else if (signum == SIGUSR1 || signum == SIGUSR2) {
        binary_data(signum, game_info);
    }
}

void setup_signal_handling(game_info_t *game_info)
{
    struct sigaction sa;

    memset(&sa, 0, sizeof(struct sigaction));
    global_game_info = game_info;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    game_info->connected = 0;
}

void send_attack(pid_t enemy_pid, int row, int col)
{
    int position = row * 8 + col;
    int *b_pos = convert_to_binary(position);

    for (int i = 0; i < 16; i++) {
        if (b_pos[i] == 0)
            kill(enemy_pid, SIGUSR1);
        else
            kill(enemy_pid, SIGUSR2);
        usleep(10000);
    }
    free(b_pos);
}
