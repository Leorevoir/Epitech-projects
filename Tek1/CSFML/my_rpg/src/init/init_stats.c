/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_stats
*/

#include "my_rpg.h"

static void add_stat(stats_t **head, stats_t *new_stats)
{
    if (!head || !new_stats)
        return;
    new_stats->next = *head;
    *head = new_stats;
}

static stats_t *create_stats(tmp_stats_t *tmp)
{
    stats_t *new_stats = malloc(sizeof(stats_t));

    if (!new_stats)
        return NULL;
    strcpy(new_stats->name, tmp->name);
    new_stats->stats = tmp->stats;
    new_stats->next = NULL;
    return new_stats;
}

void parse_stats(stats_t **stats, char *line)
{
    stats_t *new_stats;
    tmp_stats_t tmp;

    if (sscanf(line, "%s %d", tmp.name, &tmp.stats) == 2) {
        new_stats = create_stats(&tmp);
        if (new_stats)
            add_stat(stats, new_stats);
    }
}

void read_file_stats(stats_t **stats, const char *filename)
{
    FILE *file = fopen(filename, "r");
    char line[256];

    if (file == NULL)
        return;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '#')
            continue;
        parse_stats(stats, line);
    }
    fclose(file);
}

int load_stats(stats_t **stats, const char *filename)
{
    struct stat st;

    if (stat(filename, &st) != 0) {
        fprintf(stderr, "ERROR: cannot find %s\n", filename);
        return 84;
    }
    chmod(filename, 777);
    read_file_stats(stats, filename);
    chmod(filename, 000);
    return SUCCESS;
}
