/*
** EPITECH PROJECT, 2024
** B-PSU-100-STG-1-1-navy-raphael.petrequin
** File description:
** my_navy
*/

#include "../include/my_navy.h"

int handle_connection(int argc, char **argv, game_info_t *game_info)
{
    if (argc == 3) {
        game_info->enemy_pid = my_atoi(argv[1]);
        if (kill(game_info->enemy_pid, SIGUSR1) == -1)
            return 84;
        kill(game_info->enemy_pid, SIGUSR1);
        pause();
        write(1, "\nsuccessfully connected\n", 25);
        return 3;
    }
    if (argc == 2) {
        while (!game_info->connected) {
            write(1, "\nwaiting for enemy connection...\n", 34);
            pause();
        }
        write(1, "\nenemy connected\n", 18);
        return 2;
    }
    return 84;
}

int load_and_print_map(int argc, char **argv, map_t *my_map)
{
    if ((argc == 3 && read_map(argv[2], my_map) != 0) ||
        (argc == 2 && read_map(argv[1], my_map) != 0)) {
        return 84;
    }
    print_grid(my_map);
    print_enemy_grid(my_map);
    return 0;
}

static void init_game(game_info_t *game_info, map_t *my_map, map_t *enemy_map)
{
    memset(my_map, 0, sizeof(map_t));
    memset(enemy_map, 0, sizeof(map_t));
    memset(game_info, 0, sizeof(game_info_t));
    setup_signal_handling(game_info);
    init_grid(my_map);
    init_grid(enemy_map);
    setup_signal_handling(game_info);
    game_info->is_my_turn = 1;
    game_info->connected = 0;
    game_info->enemy_pid = 0;
    game_info->attack_result = 0;
}

static int manage_connection(int argc, char **argv, game_info_t *game_info)
{
    int connection_status = handle_connection(argc, argv, game_info);

    if (connection_status == 84) {
        write(2, "\nfailed to connect\n", 20);
        return 84;
    }
    return connection_status;
}

static int load_and_display_map(int argc, char **argv, map_t *my_map)
{
    if (load_and_print_map(argc, argv, my_map) != 0) {
        return 84;
    }
    return 0;
}

int game_loop(game_info_t *game_info, map_t *my_map, map_t *enemy_map,
    int connection_status)
{
    if (connection_status == 3) {
        game_info->is_my_turn = 0;
    }
    while (game_not_finished(my_map)) {
        if (attack(game_info, my_map, enemy_map) == 84) {
            return 84;
        }
    }
    return 0;
}

int my_navy(int argc, char **argv)
{
    game_info_t game_info;
    map_t my_map;
    map_t enemy_map;
    int connection_status;

    init_game(&game_info, &my_map, &enemy_map);
    connection_status = manage_connection(argc, argv, &game_info);
    if (connection_status == 84)
        return 84;
    if (load_and_display_map(argc, argv, &my_map) != 0)
        return 84;
    return game_loop(&game_info, &my_map, &enemy_map, connection_status);
}
