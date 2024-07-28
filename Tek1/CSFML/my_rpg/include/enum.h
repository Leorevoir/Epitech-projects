/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** enum
*/

#ifndef ENUM_H_
    #define ENUM_H_


////////// STRUCT RESOLUTIONS /////////
typedef enum {
    DFLT,
    FULLSCREEN,
    TWOK,
} res_t;

////////// STRUCT DIRECTIONS //////////

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
    MAX_COUNT
} four_dir_t;

typedef enum {
    WALK_UP,
    WALK_DOWN,
    WALK_LEFT,
    WALK_RIGHT,
    IDLE_UP,
    IDLE_DOWN,
    IDLE_LEFT,
    IDLE_RIGHT,
    ATCK_UP,
    ATCK_DOWN,
    ATCK_LEFT,
    ATCK_RIGHT,
    DEAD,
    COUNT
} direction_t;

typedef enum {
    WAS_RIGHT,
    WAS_LEFT,
    WAS_UP,
    WAS_DOWN
} last_direction_t;

typedef enum state_e {
    WALKING,
    JUMPING,
    IDLE,
    IS_DEAD
} state_t;

////////// STRUCT QUEST //////////////
typedef enum quest_e {
    TUTO,
    MOVE1,
    TUTO2,
    MOVE2,
    TUTO3,
    MOVE3,
    MOVE4,
    MOVE5,
    TUTO4,
    MOVE6,
    MOVE7,
    MOVE8,
    MOVE9,
    MOVE10,
    VILLAGE,
    VILLAGE2,
    VILLAGE3,
    VILLAGE4,
    WAKE_UP,
    MOVE_HUNTER1,
    MOVE_HUNTER2,
    MOVE_HUNTER3,
    MOVE_HUNTER4,
    MOVE_HUNTER5,
    MOVE_HUNTER6,
    MOVE_HUNTER7,
    MOVE_HUNTER8,
    HUNTER_QUEST,
    MOVE_HUNTER9,
    HUNTER_JUMP,
    HUNTER_QUEST2,
    HUNTER_MOVE,
    HUNTER_MOVE2,
    HUNTER_MOVE3,
    HUNTER_MOVE4,
    HUNTER_MOVE5,
    HUNTER_MOVE6,
    HUNTER_MOVE7,
    HUNTER_QUEST3,
    THUNDER_BOOM,
    HUNTER_QUEST4,
} quest_t;

#endif /* !ENUM_H_ */
