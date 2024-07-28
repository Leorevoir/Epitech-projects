/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** handle_save
*/

#include "my_rpg.h"
#include "display.h"

static FILE *create_save_file(void)
{
    FILE *file = NULL;

    chmod(".save", S_IRUSR | S_IWUSR);
    file = fopen(".save", "w");
    if (file == NULL) {
        fprintf(stderr, "ERROR: create_save_file()\n");
        fprintf(stderr, "failed to fopen(\".save\")\n");
        return NULL;
    }
    return file;
}

static void stock_npc_to_save(rpg_t *rpg, FILE *file)
{
    for (npc_t *current = rpg->npc; current; current = current->next) {
        if (strcmp(current->name, "sensei") == 0) {
            fprintf(file, "senseix=%.2f\n", current->object.position.x);
            fprintf(file, "senseiy=%.2f\n", current->object.position.y);
            fprintf(file, "senseim=%d\n", current->map);
        }
        if (strcmp(current->name, "sklt") == 0) {
            fprintf(file, "skltx=%.2f\n", current->object.position.x);
            fprintf(file, "sklty=%.2f\n", current->object.position.y);
            fprintf(file, "sklt=%d\n", current->is_alive);
        }
        if (strcmp(current->name, "hunter") == 0) {
            fprintf(file, "hunterx=%.2f\n", current->object.position.x);
            fprintf(file, "huntery=%.2f\n", current->object.position.y);
            fprintf(file, "hunterm=%d\n", current->map);
        }
    }
}

static void stock_weapons_to_save(rpg_t *rpg, FILE *file)
{
    fprintf(file, "sword=%d\n", rpg->inventory.has_sword);
    fprintf(file, "spear=%d\n", rpg->inventory.has_spear);
}

static void stock_info_to_file(rpg_t *rpg, FILE *file)
{
    sfVector2f view_pos = sfView_getCenter(rpg->view);

    fprintf(file, "posx=%.2f\n", rpg->player.object.position.x);
    fprintf(file, "posy=%.2f\n", rpg->player.object.position.y);
    fprintf(file, "quest=%d\n", rpg->player.quest);
    fprintf(file, "rebuilt=%d\n", rpg->rebuilt);
    fprintf(file, "map=%d\n", get_map_id(rpg));
    fprintf(file, "viewx=%.2f\n", view_pos.x);
    fprintf(file, "viewy=%.2f\n", view_pos.y);
    fprintf(file, "hp=%.2f\n", rpg->player.hp);
    fprintf(file, "skin=%d\n", rpg->tool.who);
    fprintf(file, "a=%d\n", rpg->weather->autumn);
    fprintf(file, "n=%d\n", rpg->weather->night);
    fprintf(file, "l=%d\n", rpg->lang);
    stock_npc_to_save(rpg, file);
    stock_weapons_to_save(rpg, file);
}

void save_progression(rpg_t *rpg)
{
    FILE *file = create_save_file();

    if (file == NULL)
        return;
    stock_info_to_file(rpg, file);
    fclose(file);
    if (chmod(".save", 0000) != 0) {
        fprintf(stderr, "ERROR: handle_save()\n");
        fprintf(stderr, "failed to chmod(\".save\")\n");
    }
}

void handle_save(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyF5)
        save_progression(rpg);
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyF9)
        load_progression(rpg);
}
