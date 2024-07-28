/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-amazed-leo.quinzler
** File description:
** create_room
*/

#include "maze.h"

int extract_int(const char *str, int *index)
{
    int num = 0;

    while (str[*index] != '\0'
        && str[*index] >= '0'
        && str[*index] <= '9') {
        num = num * 10 + (str[*index] - '0');
        (*index)++;
    }
    return num;
}

void update_room(room_t *room, int value, int index)
{
    switch (index) {
        case 0:
            room->id = value;
            break;
        case 1:
            room->x = value;
            break;
        case 2:
            room->y = value;
            break;
        default:
            break;
    }
}

room_t create_room(const char *str)
{
    room_t room = {0};
    int num = 0;
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = extract_int(str, &i);
            update_room(&room, num, index);
            index++;
        }
    }
    return room;
}
