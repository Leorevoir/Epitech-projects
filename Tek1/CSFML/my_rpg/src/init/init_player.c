/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_player
*/

#include "my_rpg.h"

character_t create_character(const char *path, sfVector2f pos,
    sfVector2f speed)
{
    character_t player;

    player.object = init_object(path, pos);
    player.speed = speed;
    return player;
}

static character_t init_player_texture_frog(void)
{
    character_t player = create_character(FROG_DOWN, (sfVector2f){PLAYER_POSX,
        PLAYER_POSY}, (sfVector2f){PLAYER_SPEED, PLAYER_SPEED});

    player.textures[WALK_DOWN] = sfTexture_createFromFile(FROG_DOWN, NULL);
    player.textures[WALK_UP] = sfTexture_createFromFile(FROG_UP, NULL);
    player.textures[WALK_LEFT] = sfTexture_createFromFile(FROG_LEFT, NULL);
    player.textures[WALK_RIGHT] = sfTexture_createFromFile(FROG_RIGHT, NULL);
    player.textures[IDLE_DOWN] = sfTexture_createFromFile(FROG_I_DOWN, NULL);
    player.textures[IDLE_UP] = sfTexture_createFromFile(FROG_I_UP, NULL);
    player.textures[IDLE_LEFT] = sfTexture_createFromFile(FROG_I_LEFT, NULL);
    player.textures[IDLE_RIGHT] = sfTexture_createFromFile(FROG_I_RIGHT, NULL);
    player.textures[ATCK_DOWN] = sfTexture_createFromFile(FROG_A_DOWN, NULL);
    player.textures[ATCK_UP] = sfTexture_createFromFile(FROG_A_UP, NULL);
    player.textures[ATCK_LEFT] = sfTexture_createFromFile(FROG_A_LEFT, NULL);
    player.textures[ATCK_RIGHT] = sfTexture_createFromFile(FROG_A_RIGHT, NULL);
    player.textures[DEAD] = sfTexture_createFromFile(FROG_DEAD_PLAYER, NULL);
    return player;
}

static character_t init_player_texture_boy(void)
{
    character_t player = create_character(BOY_DOWN, (sfVector2f){PLAYER_POSX,
        PLAYER_POSY}, (sfVector2f){PLAYER_SPEED, PLAYER_SPEED});

    player.textures[WALK_DOWN] = sfTexture_createFromFile(BOY_DOWN, NULL);
    player.textures[WALK_UP] = sfTexture_createFromFile(BOY_UP, NULL);
    player.textures[WALK_LEFT] = sfTexture_createFromFile(BOY_LEFT, NULL);
    player.textures[WALK_RIGHT] = sfTexture_createFromFile(BOY_RIGHT, NULL);
    player.textures[IDLE_DOWN] = sfTexture_createFromFile(BOY_I_DOWN, NULL);
    player.textures[IDLE_UP] = sfTexture_createFromFile(BOY_I_UP, NULL);
    player.textures[IDLE_LEFT] = sfTexture_createFromFile(BOY_I_LEFT, NULL);
    player.textures[IDLE_RIGHT] = sfTexture_createFromFile(BOY_I_RIGHT, NULL);
    player.textures[ATCK_DOWN] = sfTexture_createFromFile(BOY_A_DOWN, NULL);
    player.textures[ATCK_UP] = sfTexture_createFromFile(BOY_A_UP, NULL);
    player.textures[ATCK_LEFT] = sfTexture_createFromFile(BOY_A_LEFT, NULL);
    player.textures[ATCK_RIGHT] = sfTexture_createFromFile(BOY_A_RIGHT, NULL);
    player.textures[DEAD] = sfTexture_createFromFile(BOY_DEAD_PLAYER, NULL);
    return player;
}

static character_t init_player_texture_girl(void)
{
    character_t player = create_character(GIRL_DOWN, (sfVector2f){PLAYER_POSX,
        PLAYER_POSY}, (sfVector2f){PLAYER_SPEED, PLAYER_SPEED});

    player.textures[WALK_DOWN] = sfTexture_createFromFile(GIRL_DOWN, NULL);
    player.textures[WALK_UP] = sfTexture_createFromFile(GIRL_UP, NULL);
    player.textures[WALK_LEFT] = sfTexture_createFromFile(GIRL_LEFT, NULL);
    player.textures[WALK_RIGHT] = sfTexture_createFromFile(GIRL_RIGHT, NULL);
    player.textures[IDLE_DOWN] = sfTexture_createFromFile(GIRL_I_DOWN, NULL);
    player.textures[IDLE_UP] = sfTexture_createFromFile(GIRL_I_UP, NULL);
    player.textures[IDLE_LEFT] = sfTexture_createFromFile(GIRL_I_LEFT, NULL);
    player.textures[IDLE_RIGHT] = sfTexture_createFromFile(GIRL_I_RIGHT, NULL);
    player.textures[ATCK_DOWN] = sfTexture_createFromFile(GIRL_A_DOWN, NULL);
    player.textures[ATCK_UP] = sfTexture_createFromFile(GIRL_A_UP, NULL);
    player.textures[ATCK_LEFT] = sfTexture_createFromFile(GIRL_A_LEFT, NULL);
    player.textures[ATCK_RIGHT] = sfTexture_createFromFile(GIRL_A_RIGHT, NULL);
    player.textures[DEAD] = sfTexture_createFromFile(GIRL_DEAD_PLAYER, NULL);
    return player;
}

static void init_basic_player(struct rpg_s *rpg)
{
    rpg->player.frame = 0;
    rpg->player.rect = (sfIntRect){0, 0, 16, 16};
    rpg->player.state = IDLE;
    rpg->player.has_moved = true;
    rpg->player.last_direction = WAS_DOWN;
    rpg->player.quest = TUTO;
    rpg->player.is_button_pressed = false;
    rpg->player.xp = 0;
    rpg->player.lvl = 1;
    rpg->player.hp = 100;
    rpg->player.hit_clock = sfClock_create();
}

void create_name(rpg_t *rpg, text_t *text, char *name)
{
    text->text = sfText_create();
    text->font = sfFont_createFromFile(FONT);
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, name);
    sfText_setCharacterSize(text->text, 25);
    sfText_setFillColor(text->text, sfBlack);
    sfText_setPosition(text->text, (VECT){PP_POS_X + 10, PP_POS_Y + 294});
}

void make_pp_name(rpg_t *rpg, char *filepath, char *name)
{
    CMD_INV.name = malloc(sizeof(text_t));
    CMD_INV.pp = init_object(filepath, (VECT){PP_POS_X, PP_POS_Y});
    create_name(rpg, CMD_INV.name, name);
}

void init_player(rpg_t *rpg)
{
    switch (rpg->tool.who) {
        case 0:
            rpg->player = init_player_texture_boy();
            make_pp_name(rpg, BOY_PICTURE, "Titouan");
            break;
        case 1:
            rpg->player = init_player_texture_frog();
            make_pp_name(rpg, FROG_PICTURE, "Camille");
            break;
        case 2:
            rpg->player = init_player_texture_girl();
            make_pp_name(rpg, GIRL_PICTURE, "Leo");
            break;
        default:
            rpg->player = init_player_texture_frog();
            make_pp_name(rpg, FROG_PICTURE, "Camille");
            break;
    }
    sfSprite_setScale(CMD_INV.pp.sprite, (VECT){5, 5});
    init_basic_player(rpg);
}
