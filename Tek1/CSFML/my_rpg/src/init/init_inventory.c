/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_inventory
*/

#include "my_rpg.h"

void obj_text(text_t *text, char *name, stats_t *stats)
{
    stats_t *tmp = stats;
    char *str;

    text->text = sfText_create();
    text->font = sfFont_createFromFile(FONT);
    sfText_setFont(text->text, text->font);
    while (tmp) {
        if (strcmp(tmp->name, name) == 0) {
            str = malloc(20);
            snprintf(str, 20, "%d", tmp->stats);
            sfText_setString(text->text, str);
            free(str);
            break;
        }
        tmp = tmp->next;
    }
    sfText_setCharacterSize(text->text, 21);
    sfText_setFillColor(text->text, sfBlack);
}

void parse_stats_inv(rpg_t *rpg, stats_t *stats, sfVector2f pos)
{
    if (strcmp(stats->name, "level") == 0) {
        obj_text(CMD_INV.level, "level", stats);
        SET_POS(CMD_INV.level->text, (VECT){pos.x + 305, pos.y + 70});
    }
    if (strcmp(stats->name, "agility") == 0) {
        obj_text(CMD_INV.agility, "agility", stats);
        SET_POS(CMD_INV.agility->text, (VECT){pos.x + 410, pos.y + 140});
    }
    if (strcmp(stats->name, "strength") == 0) {
        obj_text(CMD_INV.strength, "strength", stats);
        SET_POS(CMD_INV.strength->text, (VECT){pos.x + 410, pos.y + 185});
    }
    if (strcmp(stats->name, "constitution") == 0) {
        obj_text(CMD_INV.constitution, "constitution", stats);
        SET_POS(CMD_INV.constitution->text, (VECT){pos.x + 410, pos.y + 230});
    }
    if (strcmp(stats->name, "intelligence") == 0) {
        obj_text(CMD_INV.intelligence, "intelligence", stats);
        SET_POS(CMD_INV.intelligence->text, (VECT){pos.x + 410, pos.y + 275});
    }
}

void init_inv_text(rpg_t *rpg, stats_t **stats)
{
    stats_t *tmp = *stats;
    sfVector2f pos = CMD_INV.inventory.position;

    CMD_INV.level = malloc(sizeof(stats_t));
    CMD_INV.agility = malloc(sizeof(stats_t));
    CMD_INV.strength = malloc(sizeof(stats_t));
    CMD_INV.constitution = malloc(sizeof(stats_t));
    CMD_INV.intelligence = malloc(sizeof(stats_t));
    while (tmp != NULL) {
        parse_stats_inv(rpg, tmp, pos);
        tmp = tmp->next;
    }
    CMD_INV.show_quest = false;
}

static void init_quest_text_pos(rpg_t *rpg)
{
    sfVector2f v1 = CMD_INV.inventory.position;
    sfVector2f v2 = CMD_INV.inventory.position;

    v1.x += 82;
    v1.y += 134;
    v2.x += 127;
    v2.y += 137;
    sfText_setPosition(rpg->text->quest, v2);
    sfText_setPosition(rpg->text->description, (VECT){v2.x, v2.y + 50});
    v2.x += 280;
    sfText_setPosition(rpg->text->validate, v2);
    sfSprite_setPosition(rpg->text->picture.sprite, v1);
}

void init_french_and_english(rpg_t *rpg, sfVector2f pos)
{
    CMD_INV.inventory = init_object(INVENTORY, pos);
    CMD_INV.quests = init_object(QUESTS, pos);
    CMD_INV.inventaire = init_object(INVENTAIRE, pos);
    CMD_INV.quetes = init_object(QUETES, pos);
}

void init_inventory(rpg_t *rpg, stats_t **stats)
{
    sfVector2u win_pos = sfRenderWindow_getSize(rpg->window);
    sfVector2f pos = {(win_pos.x / 2) - 432, (win_pos.y / 2) - 432};

    init_french_and_english(rpg, pos);
    CMD_INV.sword_obj = init_object(SWORD_PIC,
        (VECT){pos.x + 125, pos.y + 537});
    CMD_INV.spear_obj = init_object(SPEAR_PIC,
        (VECT){pos.x + 225, pos.y + 537});
    sfSprite_setScale(CMD_INV.sword_obj.sprite, (VECT){11, 11});
    sfSprite_setScale(CMD_INV.spear_obj.sprite, (VECT){11, 11});
    CMD_INV.button = create_vertex(360.f, 76.f, 32.f);
    CMD_INV.transform_btn = sfTransform_Identity;
    sfTransform_translate(&(CMD_INV.transform_btn), pos.x + 85, pos.y + 336);
    CMD_INV.states_btn = (sfRenderStates){.blendMode = sfBlendAlpha,
        .transform = CMD_INV.transform_btn, .texture = NULL, .shader = NULL };
    init_weapon(rpg);
    init_inv_text(rpg, stats);
    init_quest_text_pos(rpg);
}
