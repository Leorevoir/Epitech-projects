/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_text
*/

#include "my_rpg.h"

static void set_font(rpg_t *rpg)
{
    sfText_setFont(rpg->text->text, rpg->text->font);
    sfText_setFont(rpg->text->name, rpg->text->font);
    sfText_setFont(rpg->text->quest, rpg->text->font);
    sfText_setFont(rpg->text->description, rpg->text->font);
    sfText_setFont(rpg->text->validate, rpg->text->font);
    sfText_setFont(rpg->lvl_up, rpg->text->font);
    sfText_setFont(rpg->death.youre_dead, rpg->text->font);
    sfText_setFont(rpg->death.try_again, rpg->text->font);
}

static void set_size(rpg_t *rpg)
{
    sfText_setCharacterSize(rpg->text->text, 35);
    sfText_setCharacterSize(rpg->text->name, 30);
    sfText_setCharacterSize(rpg->text->quest, 25);
    sfText_setCharacterSize(rpg->text->description, 20);
    sfText_setCharacterSize(rpg->text->validate, 25);
    sfText_setCharacterSize(rpg->lvl_up, 40);
    sfText_setCharacterSize(rpg->death.youre_dead, 150);
    sfText_setCharacterSize(rpg->death.try_again, 40);
}

static void set_color(rpg_t *rpg)
{
    sfText_setFillColor(rpg->text->text, sfBlack);
    sfText_setFillColor(rpg->lvl_up, sfBlue);
    sfText_setFillColor(rpg->text->quest, sfBlack);
    sfText_setFillColor(rpg->text->description, sfBlack);
    sfText_setFillColor(rpg->text->name, sfWhite);
    sfText_setFillColor(rpg->text->validate, sfRed);
    sfText_setFillColor(rpg->death.youre_dead, (sfColor){109, 7, 26, 255});
    sfText_setFillColor(rpg->death.try_again, (sfColor){109, 7, 26, 255});
}

static void init_text_font(rpg_t *rpg)
{
    set_font(rpg);
    set_size(rpg);
    set_color(rpg);
}

static bool init_create_text(rpg_t *rpg)
{
    rpg->text->text = sfText_create();
    rpg->text->name = sfText_create();
    rpg->text->quest = sfText_create();
    rpg->text->description = sfText_create();
    rpg->text->validate = sfText_create();
    rpg->lvl_up = sfText_create();
    rpg->death.youre_dead = sfText_create();
    rpg->death.try_again = sfText_create();
    if (rpg->text->text == NULL || rpg->text->name == NULL
        || rpg->text->quest == NULL || rpg->text->validate == NULL)
        return false;
    return true;
}

static void first_start_text_init(rpg_t *rpg)
{
    sfText_setString(rpg->lvl_up, "LEVEL UP !!!!");
    sfText_setString(rpg->text->validate, "X");
    sfText_setString(rpg->text->quest, "A new start");
    sfText_setString(rpg->text->description,
    "Learn how to\nget along\nin this new world");
    sfText_setString(rpg->death.youre_dead, "YOU ARE DEAD.");
    sfText_setString(rpg->death.try_again,
    "Press r to reload\nan old save...");
    rpg->text->picture = init_object(SENSEI_PICTURE, (sfVector2f){0, 0});
}

void init_text(rpg_t *rpg)
{
    rpg->text = (text_t *)malloc(sizeof(text_t));
    if (!init_create_text(rpg)) {
        fprintf(stderr, "ERROR: failed to create text.\n");
        exit(FAILURE);
    }
    rpg->text->font = sfFont_createFromFile(FONT);
    if (rpg->text->font == NULL) {
        fprintf(stderr, "ERROR: failed to load font file.\n");
        exit(FAILURE);
    }
    init_text_font(rpg);
    first_start_text_init(rpg);
    rpg->text->txt_to_print = NULL;
    rpg->text->continue_display = false;
}
