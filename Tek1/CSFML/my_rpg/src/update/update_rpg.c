/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** upadte_rpg
*/

#include "update.h"

void update_character_frame(character_t *player, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float elapsed = sfTime_asSeconds(time);

    if (elapsed >= 0.2f) {
        player->frame = (player->frame + 1) % 4;
        player->rect.top = player->frame * 16;
        sfClock_restart(clock);
    }
}

static void map_village(rpg_t *rpg)
{
    sfVector2f end = {303.91, 484.71};

    if (rpg->player.quest < 8)
        return;
    rpg->cinema = true;
    sfClock_restart(rpg->boss->clock);
    rpg->background = &(rpg->maps.map_village);
    rpg->player.object.position = end;
    rpg->player.has_moved = true;
    rpg->maps.current = rpg->maps.map_village_collision;
    rpg->maps.name_curr = strcpy(rpg->maps.name_curr, "village");
    sfSprite_setPosition(rpg->player.object.sprite, end);
}

static void map_road(rpg_t *rpg)
{
    sfVector2f pos = {27, 366};

    if (rpg->player.quest >= 19)
        rpg->weather->autumn = true;
    rpg->background = &(rpg->maps.map_road);
    rpg->player.object.position = pos;
    rpg->player.has_moved = true;
    rpg->maps.current = rpg->maps.map_road_collision;
    rpg->maps.name_curr = strcpy(rpg->maps.name_curr, "road");
    sfSprite_setPosition(rpg->player.object.sprite, pos);
}

static void map_boss(rpg_t *rpg, sfEvent *event)
{
    sfVector2f pos = {238, 347};

    if (rpg->player.quest == 35
        || rpg->player.quest == 36) {
        rpg->player.quest++;
        rpg->weather->autumn = false;
        check_quest_status(rpg, event);
    }
    rpg->background = &(rpg->maps.map_boss);
    rpg->player.object.position = pos;
    rpg->player.has_moved = true;
    rpg->maps.current = rpg->maps.map_boss_collision;
    rpg->maps.name_curr = strcpy(rpg->maps.name_curr, "boss");
    sfSprite_setPosition(rpg->player.object.sprite, pos);
}

static void last_cinematic(rpg_t *rpg)
{
    rpg->player.object.position = (sfVector2f){217.78, 386.42};
    sfSprite_setPosition(
        rpg->player.object.sprite, rpg->player.object.position);
    rpg->last_cinema = true;
    rpg->rebuilt = true;
    rpg->player.has_moved = true;
    rpg->background = &(rpg->maps.map_road);
    rpg->maps.current = rpg->maps.map_road_collision;
    rpg->maps.name_curr = strcpy(rpg->maps.name_curr, "road");
}

static void update_map(rpg_t *rpg, sfVector2f pos, sfEvent *event)
{
    if (pos.x >= 566.22 && pos.x <= 577.42 && pos.y >= 203.25
        && pos.y <= 208.85 && rpg->background == &(rpg->maps.map_road))
        rpg->inventory.has_spear = true;
    if (pos.x >= 3 && pos.x <= 12 && pos.y >= 348 && pos.y <= 390
        && rpg->background == &(rpg->maps.map_road))
        map_village(rpg);
    if (pos.x >= 531 && pos.x <= 542 && pos.y >= 277 && pos.y <= 319
        && rpg->background == &(rpg->maps.map_village))
        map_road(rpg);
    if (pos.x >= 91 && pos.x <= 220 && pos.y >= -13 && pos.y <= 4
        && rpg->background == &(rpg->maps.map_road))
        map_boss(rpg, event);
    if (pos.x >= 223 && pos.x <= 257 && pos.y >= 343 && pos.y <= 352
        && rpg->background == &(rpg->maps.map_boss) && !rpg->boss->alive
        && rpg->player.quest >= 44) {
        rpg->weather->night = false;
        last_cinematic(rpg);
    }
}

void update_quest(rpg_t *rpg)
{
    if (rpg->player.quest >= MOVE_HUNTER1) {
        if (rpg->lang == ENGLISH) {
            sfText_setString(rpg->text->quest, "A spiteful spirit");
            sfText_setString(rpg->text->description,
            "We must know more\nabout this spirit !!!");
        } else {
            sfText_setString(rpg->text->quest, "Un esprit tegnieux");
            sfText_setString(rpg->text->description,
            "Il faut en apprendre plus\nsur cet esprit !!!");
        }
    }
}

static void update_text(rpg_t *rpg)
{
    if (rpg->lang == ENGLISH) {
        sfText_setString(rpg->lvl_up, "LEVEL UP !!!!");
        sfText_setString(rpg->text->quest, "A new start");
        sfText_setString(rpg->text->description,
        "Learn how to\nget along\nin this new world");
        sfText_setString(rpg->death.youre_dead, "YOU ARE DEAD.");
        sfText_setString(rpg->death.try_again,
        "Press r to reload\nan old save...");
    } else {
        sfText_setString(rpg->lvl_up, "NIVEAU SUPERIEUR !!!!");
        sfText_setString(rpg->text->quest, "Un nouveau depart");
        sfText_setString(rpg->text->description,
        "Apprenez comment vous\ndebrouiller dans ce tout\nnouveau monde");
        sfText_setString(rpg->death.youre_dead, "VOUS ETES MORT.");
        sfText_setString(rpg->death.try_again,
        "Appuyer sur r pour recharger\nune ancienne sauvegarde...");
    }
    update_quest(rpg);
}

static void update_my_rpg(rpg_t *rpg, sfEvent *event, sfTimeSpan time_span)
{
    update_boss(rpg->boss, rpg->boss->clock, rpg);
    handle_mouse_input(rpg, time_span);
    update_view(rpg);
    update_ui(rpg->ui, rpg);
    sfSprite_setPosition(rpg->player.object.sprite,
        rpg->player.object.position);
    check_quest_status(rpg, event);
    check_npc_proximity(rpg, event);
    if (rpg->boss->alive == false && rpg->player.quest >= 42)
        rpg->weather->night = false;
    if (rpg->boss->alive == false && rpg->player.quest == 44) {
        update_last_quest(rpg->npc, rpg, event);
    }
    update_text(rpg);
}

void update_rpg(rpg_t *rpg, sfEvent *event, sfTimeSpan time_span)
{
    if (rpg->player.quest >= MOVE3)
        rpg->inventory.has_sword = true;
    if (rpg->player.quest == 29 && rpg->inventory.has_spear)
        rpg->player.quest = 30;
    if (rpg->last_cinema) {
        update_last_cinema(rpg);
        return;
    }
    if (rpg->cinema) {
        update_cinema(rpg);
    } else {
        update_map(rpg, rpg->player.object.position, event);
        handle_keyboard_input(rpg);
        if (rpg->player.state == WALKING) {
            update_character_frame(&rpg->player, rpg->clock);
            sfSprite_setTextureRect(rpg->player.object.sprite,
                rpg->player.rect);
        }
        update_my_rpg(rpg, event, time_span);
    }
}
