/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** champ
*/

#include "core.h"

static void init_champ_values(champ_t *new_champ)
{
    char *id = NULL;

    new_champ->dont_move = false;
    new_champ->carry = 1;
    new_champ->starting_pos = 0;
    new_champ->pc = 0;
    new_champ->reg = (char **)malloc(sizeof(char *) * (REG_NUMBER + 2));
    new_champ->reg[REG_NUMBER + 1] = NULL;
    for (int i = 0; i < REG_NUMBER + 1; i++) {
        new_champ->reg[i] = malloc(sizeof(char) * (REG_SIZE) + 1);
        new_champ->reg[i][REG_SIZE] = '\0';
    }
    new_champ->alive = 2;
    new_champ->fork = false;
    id = malloc(sizeof(char) * (my_intlen(new_champ->id) + 1));
    int_to_str(new_champ->id, id);
    new_champ->reg[1] = id;
}

champ_t *add_champ(champ_t *head, header_t new_header, int count,
    unsigned char *inst)
{
    champ_t *new_champ = malloc(sizeof(champ_t));
    char *hex_str = NULL;
    char **array = NULL;

    if (!new_champ)
        return NULL;
    for (int i = 0; i < new_header.prog_size; i++) {
        hex_str = int_to_hex_string(inst[i]);
        str_to_array(&array, hex_str);
        free(hex_str);
    }
    new_champ->tab = array;
    new_champ->inst = inst;
    new_champ->id = count;
    init_champ_values(new_champ);
    new_champ->header = new_header;
    new_champ->next = head;
    return new_champ;
}

champ_t *remove_champ_by_name(champ_t *head, champ_t *current, champ_t *prev)
{
    if (prev == NULL)
        head = current->next;
    else
        prev->next = current->next;
    free(current);
    return head;
}

champ_t *remove_champ(champ_t *head, char *name)
{
    champ_t *current = head;
    champ_t *prev = NULL;

    while (current != NULL) {
        if (my_strcmp(current->header.prog_name, name) == 0) {
            return remove_champ_by_name(head, current, prev);
        }
        prev = current;
        current = current->next;
    }
    return head;
}

unsigned char *get_instructions(int fd, header_t header)
{
    unsigned char *buffer = NULL;

    buffer = (unsigned char *)malloc((size_t)header.prog_size);
    if ((read(fd, buffer, header.prog_size)) < 0)
        return NULL;
    return buffer;
}

int create_champ(int fd, war_t *war, champ_t *head, int count)
{
    champ_t *new_champ = NULL;
    unsigned char *inst = NULL;
    header_t header = {0};
    ssize_t br = read(fd, &header, sizeof(header_t));

    if (br == -1 || header.prog_name == NULL
        || header.comment == NULL)
        return 84;
    header.magic = my_htonl(header.magic);
    header.prog_size = my_htonl(header.prog_size);
    if (header.magic != COREWAR_EXEC_MAGIC)
        return 84;
    inst = get_instructions(fd, header);
    if (inst == NULL)
        return 84;
    new_champ = add_champ(head, header, count, inst);
    war->head = new_champ;
    close(fd);
    return 0;
}
