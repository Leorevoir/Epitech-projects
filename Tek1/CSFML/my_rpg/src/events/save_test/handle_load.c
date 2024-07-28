/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** handle_load
*/

#include "update.h"
#include "display.h"

static FILE *try_open(void)
{
    FILE *file = NULL;
    struct stat st;

    if (stat(".save", &st) != 0)
        return NULL;
    chmod(".save", S_IRUSR | S_IWUSR);
    file = fopen(".save", "r");
    return file;
}

static void switch_other_map(rpg_t *rpg, int map)
{
    switch (map) {
        case 3:
            rpg->rebuilt = true;
            rpg->background = (&rpg->maps.map_boss);
            rpg->maps.current = rpg->maps.map_boss_collision;
            break;
        default:
            rpg->background = (&rpg->maps.map_road);
            rpg->maps.current = rpg->maps.map_road_collision;
            break;
    }
}

static void switch_map(rpg_t *rpg, int map)
{
    switch (map) {
        case 0:
            rpg->background = (&rpg->maps.map_road);
            rpg->maps.current = rpg->maps.map_road_collision;
            break;
        case 1:
            rpg->background = (&rpg->maps.map_village);
            rpg->maps.current = rpg->maps.map_village_collision;
            break;
        case 2:
            rpg->rebuilt = true;
            rpg->background = (&rpg->maps.map_village);
            rpg->maps.current = rpg->maps.map_village_collision;
            break;
        default:
            switch_other_map(rpg, map);
            break;
    }
}

static void load_npc_pos(rpg_t *rpg, sfVector2f se, sfVector2f sp, t_t *t)
{
    for (npc_t *current = rpg->npc; current; current = current->next) {
        if (strcmp(current->name, "sensei") == 0) {
            current->map = t->sem;
            current->object.position = se;
            sfSprite_setPosition(current->object.sprite,
                current->object.position);
        }
        if (strcmp(current->name, "sklt") == 0) {
            current->object.position = sp;
            sfSprite_setPosition(current->object.sprite,
                current->object.position);
            current->is_alive = (bool)t->ska;
        }
        if (strcmp(current->name, "hunter") == 0) {
            current->map = t->hm;
            current->object.position = t->ht;
            sfSprite_setPosition(current->object.sprite,
                current->object.position);
        }
    }
}

static void load_rpg_stuff(rpg_t *rpg, t_t *t)
{
    rpg->rebuilt = t->r;
    rpg->player.hp = t->hp;
    sfView_setCenter(rpg->view, t->v);
    rpg->tool.who = t->w;
    rpg->player.quest = t->q;
    rpg->player.object.position = t->pos;
    switch_map(rpg, t->m);
    load_npc_pos(rpg, t->se, t->sk, t);
    rpg->inventory.has_sword = (bool)t->sw;
    rpg->inventory.has_spear = (bool)t->sp;
    rpg->weather->autumn = (bool)t->au;
    rpg->weather->night = (bool)t->ni;
    rpg->lang = (bool)t->au;
    rpg->player.object.position = t->pos;
}

static void parse_save_file(FILE *file, rpg_t *rpg)
{
    t_t t = {0};

    if (fscanf(file, "posx=%f\nposy=%f\nquest=%d\nrebuilt=%d\nmap=%d\n"
        "viewx=%f\nviewy=%f\nhp=%f\nskin=%d\na=%d\nn=%d\nl=%d\nskltx=%f\n"
        "sklty=%f\nsklt=%d\nsenseix=%f\nsenseiy=%f\nsenseim=%d\nhunterx=%f\n"
        "huntery=%f\nhunterm=%d\nsword=%d\n" "spear=%d\n", &t.pos.x, &t.pos.y,
        &t.q, &t.r, &t.m, &t.v.x, &t.v.y, &t.hp, &t.w, &t.au, &t.ni, &t.la,
        &t.sk.x, &t.sk.y, &t.ska, &t.se.x, &t.se.y, &t.sem, &t.ht.x, &t.ht.y,
        &t.hm, &t.sw, &t.sp) != 23) {
        fprintf(stderr, "ERROR: you nasty cheater...\n");
        fprintf(stderr, "don't modify this file ^_^\n");
        return;
    }
    load_rpg_stuff(rpg, &t);
}

void load_progression(rpg_t *rpg)
{
    FILE *file = try_open();

    if (!file) {
        fprintf(stderr, "ERROR: try_open()\n");
        fprintf(stderr, "failed to fopen(\".save\")\n");
        fprintf(stderr, "Did you really create a save file in game?\n");
        return;
    }
    parse_save_file(file, rpg);
    if (rpg->tool.menu) {
        init_player(rpg);
        rpg->tool.menu = false;
        load_progression(rpg);
    }
    fclose(file);
    if (chmod(".save", 0000) != 0) {
        fprintf(stderr, "ERROR: handle_save()\n");
        fprintf(stderr, "failed to chmod(\".save\")\n");
    }
}
