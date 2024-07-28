/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** display_rpg
*/

#include "update.h"
#include "display.h"

static void draw_heart_and_weapon(rpg_t *rpg, sfVector2f pos)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->ui->hp.sprite, NULL);
    if (CMD_INV.sword.equippied || CMD_INV.spear.equippied) {
        sfSprite_setPosition(CMD_INV.curr_weapon.sprite,
            (VECT){pos.x + 4.5, pos.y + 20});
        sfRenderWindow_drawSprite(rpg->window,
            CMD_INV.curr_weapon.sprite, NULL);
    }
}

void draw_lvl_up(rpg_t *rpg)
{
    const sfView *default_view = sfRenderWindow_getDefaultView(rpg->window);
    sfVector2f view_pos = sfView_getCenter(default_view);

    sfRenderWindow_setView(rpg->window, default_view);
    sfText_setPosition(rpg->lvl_up, (VECT){view_pos.x - 70, view_pos.y - 50});
    sfRenderWindow_drawText(rpg->window, rpg->lvl_up, NULL);
    sfRenderWindow_setView(rpg->window, rpg->view);
    sfRenderWindow_display(rpg->window);
    rpg->player.speed.x = PLAYER_SPEED;
    rpg->player.speed.y = PLAYER_SPEED;
    sleep(1);
    rpg->disp_lvl_up = false;
}

void display_death(rpg_t *rpg)
{
    const sfView *default_view = sfRenderWindow_getDefaultView(rpg->window);
    sfVector2f pos = sfView_getCenter(default_view);

    sfRenderWindow_setView(rpg->window, default_view);
    SET_POS(rpg->death.youre_dead, (VECT){pos.x / 2.5, pos.y - 150});
    SET_POS(rpg->death.try_again, (VECT){pos.x / 1.25, pos.y + 25});
    sfRenderWindow_drawText(rpg->window, rpg->death.youre_dead, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->death.try_again, NULL);
    sfRenderWindow_setView(rpg->window, rpg->view);
}

static void start_big_boss(rpg_t *rpg)
{
    rpg->weather->night = false;
    rpg->player.quest++;
    sfClock_restart(rpg->boss->fx.red2_clock);
    rpg->boss->fx.display_thunder = false;
}

void update_and_display_thunder_boom(fx_t *fx, rpg_t *rpg)
{
    sfTime dt = sfClock_getElapsedTime(fx->clock);
    float elapsed = sfTime_asSeconds(dt);
    sfTime total_time = sfClock_getElapsedTime(fx->red2_clock);
    float total_elapsed = sfTime_asSeconds(total_time);

    if (elapsed >= 0.15f) {
        fx->frame2 = (fx->frame2 + 1) % 8;
        fx->rect2.left = fx->frame2 * 20;
        sfClock_restart(fx->clock);
    }
    sfSprite_setPosition(fx->thunder.sprite, (sfVector2f){246, 75});
    sfSprite_setTextureRect(fx->thunder.sprite, fx->rect2);
    if (total_elapsed >= 0.5f && rpg->weather->night) {
        start_big_boss(rpg);
        return;
    }
    if (total_elapsed >= 2.1f && !rpg->weather->night) {
        rpg->weather->night = true;
        sfClock_restart(fx->red2_clock);
    }
}

/// @brief je jure que je mets ça là prc sinon ça marche pas
/// @param n npc head
/// @param rpg main struct
void move_hunter_to_enter(npc_t *n, rpg_t *rpg)
{
    if (rpg->player.quest < 39)
        return;
    for (npc_t *c = n; c; c = c->next) {
        if (strcmp(c->name, "hunter") == 0 && rpg->player.quest == 40)
            move_npc(c, (sfVector2f){238, 302}, HUNTER_SPEED, rpg);
    }
    if (rpg->player.quest == 41) {
        rpg->boss->alive = true;
        rpg->boss->fx.display_smoke = true;
    }
}

static void display_basic_rpg(rpg_t *rpg, tile_t *head)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    sfRenderWindow_setView(rpg->window, rpg->view);
    sfRenderWindow_drawSprite(rpg->window, rpg->background->sprite, NULL);
    display_tiles_and_player(rpg, head);
    autumn_vibrant(rpg);
    night_vibrant(rpg);
    move_hunter_to_enter(rpg->npc, rpg);
}

static void start_boss_animation(rpg_t *rpg)
{
    if (rpg->player.quest == THUNDER_BOOM
        && !rpg->boss->fx.display_thunder)
        rpg->boss->fx.display_thunder = true;
    if (rpg->boss->fx.display_thunder) {
        update_and_display_thunder_boom(&rpg->boss->fx, rpg);
        DRAW_SPRITE(rpg->window, rpg->boss->fx.thunder.sprite, NULL);
    }
}

void display_rpg(rpg_t *rpg, tile_t *head, hud_t *hud)
{
    sfVector2f pos = sfSprite_getPosition(rpg->ui->hp.sprite);

    display_basic_rpg(rpg, head);
    if (rpg->inventory.show)
        display_inventory(rpg);
    start_boss_animation(rpg);
    if (!rpg->cinema)
        draw_heart_and_weapon(rpg, pos);
    if (rpg->disp_lvl_up)
        draw_lvl_up(rpg);
    if (rpg->player.state == IS_DEAD)
        display_death(rpg);
    if (hud->menu->escape == true)
        display_escape_menu(hud, rpg);
    sfRenderWindow_display(rpg->window);
}
