/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** stats
*/

#ifndef STATS_H_
    #define STATS_H_

typedef struct tmp_stats_s {
    char name[50];
    int stats;
} tmp_stats_t;

typedef struct stats_s {
    char name[50];
    int stats;
    struct stats_s *next;
} stats_t;

int load_stats(stats_t **stats, const char *filename);

#endif /* !STATS_H_ */
