/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** update_ui
*/

#include "update.h"

static void switch_life_rect(sfIntRect *hp_rect, int life)
{
    switch (life) {
        case 5:
            hp_rect->left = 0;
            break;
        case 4:
            hp_rect->left = 16;
            break;
        case 3:
            hp_rect->left = 32;
            break;
        case 2:
            hp_rect->left = 48;
            break;
        case 1:
            hp_rect->left = 64;
            break;
        default:
            hp_rect->left = 64;
            break;
    }
}

static void update_ui_hp(ui_t *ui, rpg_t *rpg)
{
    sfIntRect hp_rect = {0, 0, 16, 16};
    int life = rpg->player.hp / 20;

    switch_life_rect(&hp_rect, life);
    sfSprite_setTextureRect(ui->hp.sprite, hp_rect);
}

static void update_ui_pos(ui_t *ui, rpg_t *rpg)
{
    sfVector2f center = {0};
    sfVector2f size = {0};
    sfVector2f top_left = {0};

    center = sfView_getCenter(rpg->view);
    size = sfView_getSize(rpg->view);
    top_left.x = (center.x - size.x / 2) + 1.5;
    top_left.y = center.y - size.y / 2;
    sfSprite_setPosition(ui->hp.sprite, top_left);
}

static void death_vibrant(rpg_t *rpg)
{
    sfRectangleShape *filter = sfRectangleShape_create();

    sfRectangleShape_setSize(filter, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(filter, (sfColor){255, 255, 255, 45});
    sfRenderWindow_drawRectangleShape(rpg->window, filter, NULL);
}

static void update_death(character_t *p, rpg_t *rpg)
{
    if (p->hp == 0) {
        p->has_moved = false;
        p->state = IS_DEAD;
        sfSprite_setTexture(p->object.sprite, p->textures[DEAD], sfTrue);
        p->frame = 0;
        death_vibrant(rpg);
    }
}

void update_ui(ui_t *ui, rpg_t *rpg)
{
    update_ui_hp(ui, rpg);
    update_ui_pos(ui, rpg);
    update_death(&(rpg->player), rpg);
}
