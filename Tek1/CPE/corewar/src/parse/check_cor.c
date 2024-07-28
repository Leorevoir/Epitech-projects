/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** parse_cor
*/

#include "core.h"

int check_extension(const char *file, const char *ext)
{
    size_t file_len = my_strlen(file);
    size_t ext_len = my_strlen(ext);

    if (file_len < ext_len)
        return 0;
    return my_strcmp(file + file_len - ext_len, ext) == 0;
}

int try_file(const char *file, war_t *war, champ_t *head, int count)
{
    struct stat st;
    int fd = open(file, O_RDONLY);

    if (stat(file, &st) != 0 || fd == -1)
        return 84;
    if (!check_extension(file, ".cor")) {
        close(fd);
        return 84;
    }
    return create_champ(fd, war, head, count);
}

static bool is_num(const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

static void only_increment_if(const int argc, int **i)
{
    int j = **i;

    if (j + 1 < argc) {
        **i = **i + 1;
    }
}

static int check_flags(int argc, int *i, char **argv, war_t *war)
{
    if (my_strcmp(argv[*i], "-n") == 0) {
        only_increment_if(argc, &i);
        if (!is_num(argv[*i]))
            return 84;
        only_increment_if(argc, &i);
        try_file(argv[*i], war, war->head, my_atoi(argv[*i - 1]));
        only_increment_if(argc, &i);
    }
    return 0;
}

static int get_num_champ(champ_t *head)
{
    champ_t *current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int parse_cor_file(int argc, char **argv, int index, war_t *war)
{
    int count = 1;
    int rtn = 0;

    if (index == argc)
        return 84;
    for (; index < argc; index++) {
        if (check_flags(argc, &index, argv, war) == 84)
            return 84;
        if (try_file(argv[index], war, war->head, count) != 84) {
            count++;
            continue;
        } else
            return 84;
    }
    war->num_champ = get_num_champ(war->head);
    launch_game(war, war->head);
    free_war(war);
    return 0;
}
