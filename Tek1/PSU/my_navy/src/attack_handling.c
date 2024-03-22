/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** attack_handling
*/

#include "../include/my_navy.h"
#include "../include/my_printf.h"

static int are_coordinates_valid(char *attack_pos)
{
    if (my_strlen(attack_pos) != 3)
        return 0;
    if (attack_pos[0] < 'A' || attack_pos[0] > 'H')
        return 0;
    if (attack_pos[1] < '1' || attack_pos[1] > '8')
        return 0;
    return 1;
}

static int read_attack_coordinates(char *attack_pos)
{
    my_printf("\nattack: ");
    if (read(0, attack_pos, 1024) == -1)
        return 84;
    if (!are_coordinates_valid(attack_pos)) {
        write(2, "invalid coordinates\n", 20);
        return 84;
    }
    return 0;
}

static void update_enemy_grid(map_t *enemy_map, int row, int col, int result)
{
    if (result == HIT)
        enemy_map->grid[row][col] = 'x';
    else
        enemy_map->grid[row][col] = 'o';
}

int perform_attack(game_info_t *game_info, map_t *enemy_map, const char *pos)
{
    int row = pos[1] - '1';
    int col = pos[0] - 'A';
    int result;

    send_attack(game_info->enemy_pid, row, col);
    result = receive_attack_result(&row, &col, game_info);
    if (result == HIT) {
        enemy_map->grid[row][col] = 'x';
        return 1;
    } else {
        enemy_map->grid[row][col] = '.';
        return 0;
    }
    return 0;
}

static void handle_enemy_attack(map_t *my_map, game_info_t *game_info)
{
    int row = -1;
    int col = -1;
    int result = 0;

    my_printf("\nwaiting for enemy's attack...\n");
    result = receive_attack_result(&row, &col, game_info);
    update_my_grid(my_map, row, col, result);
}

int handle_player_attack(game_info_t *game_info, map_t *enemy_map)
{
    char pos[3] = {0};
    int row;
    int col;
    int attack_result;

    if (read_attack_coordinates(pos) == 84)
        return 84;
    row = pos[1] - '1';
    col = pos[0] - 'A';
    attack_result = perform_attack(game_info, enemy_map, pos);
    if (attack_result == HIT) {
        update_enemy_grid(enemy_map, row, col, HIT);
        my_printf("\nresult: %c%c:%s\n", pos[0], pos[1], "hit");
    } else {
        update_enemy_grid(enemy_map, row, col, MISS);
        my_printf("\nresult: %c%c:%s\n", pos[0], pos[1], "missed");
    }
    return 0;
}

int attack(game_info_t *game_info, map_t *my_map, map_t *enemy_map)
{
    if (game_info->is_my_turn) {
        if (handle_player_attack(game_info, enemy_map) == 84)
            return 84;
        game_info->is_my_turn = 0;
    } else {
        handle_enemy_attack(my_map, game_info);
        game_info->is_my_turn = 1;
    }
    print_grid(my_map);
    print_enemy_grid(enemy_map);
    return 0;
}
