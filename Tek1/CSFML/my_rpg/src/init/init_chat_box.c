/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** init_chat_box
*/

#include "my_rpg.h"

static dialogue_t *create_dialogue(temp_t *tmp)
{
    dialogue_t *new_dialogue = (dialogue_t *)malloc(sizeof(dialogue_t));

    if (new_dialogue == NULL)
        return NULL;
    new_dialogue->name = NULL;
    new_dialogue->text = NULL;
    new_dialogue->quest = NULL;
    new_dialogue->num = 0;
    new_dialogue->next = NULL;
    if (tmp->name)
        new_dialogue->name = strdup(tmp->name);
    if (tmp->text)
        new_dialogue->text = strdup(tmp->text);
    if (tmp->quest)
        new_dialogue->quest = strdup(tmp->quest);
    new_dialogue->num = tmp->num;
    return new_dialogue;
}

static void add_dialogue(dialogue_t **head, temp_t *tmp)
{
    dialogue_t *new_dialogue = create_dialogue(tmp);
    dialogue_t *current = NULL;

    if (*head == NULL) {
        *head = new_dialogue;
    } else {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_dialogue;
    }
}

static void stock_text(temp_t *tmp, char *line)
{
    char *ptr = NULL;

    tmp->text = strdup(line + 5);
    tmp->text[strcspn(tmp->text, "\n")] = 0;
    ptr = tmp->text;
    while (*ptr) {
        if (*ptr == '"')
            memmove(ptr, ptr + 1, strlen(ptr));
        else
            ptr++;
    }
    if (strlen(tmp->text) > 42) {
        fprintf(stderr, "WARNING: line is too long\n{%s}\n", tmp->text);
        fprintf(stderr, "got:\t%ld\nmax\t%d\n", strlen(tmp->text), 42);
    }
}

static void stock_in_my_list(temp_t *tmp, char *line)
{
    if (strncmp(line, "name=", 5) == 0) {
        tmp->name = strdup(line + 5);
        tmp->name[strcspn(tmp->name, "\n")] = 0;
    }
    if (strncmp(line, "text=", 5) == 0)
        stock_text(tmp, line);
    if (strncmp(line, "quest=", 6) == 0) {
        tmp->quest = strdup(line + 6);
        tmp->quest[strcspn(tmp->quest, "\n")] = 0;
    }
    if (strncmp(line, "num=", 4) == 0) {
        tmp->num = atoi(line + 4);
    }
}

static void new_dialogue_line(temp_t *tmp, dialogue_t **head)
{
    static dialogue_t *last_dialogue = NULL;

    if (tmp->name != NULL && tmp->text != NULL && tmp->quest != NULL) {
        add_dialogue(head, tmp);
        free(tmp->name);
        free(tmp->text);
        free(tmp->quest);
        last_dialogue = *head;
        while (last_dialogue->next != NULL)
            last_dialogue = last_dialogue->next;
    }
}

static void parse_line(char *line, temp_t *tmp, dialogue_t **head)
{
    if (strncmp(line, "[Dialogue]", 10) == 0) {
        new_dialogue_line(tmp, head);
        tmp->name = NULL;
        tmp->text = NULL;
        tmp->quest = NULL;
    } else
        stock_in_my_list(tmp, line);
}

static int parse_quests_conf(dialogue_t **head, const char *filename)
{
    FILE *file = fopen(filename, "r");
    temp_t tmp = {0};
    char line[256];

    if (file == NULL)
        return FAILURE;
    while (fgets(line, sizeof(line), file) != NULL)
        parse_line(line, &tmp, head);
    if (tmp.name != NULL && tmp.text != NULL && tmp.quest != NULL) {
        add_dialogue(head, &tmp);
        free(tmp.name);
        free(tmp.text);
        free(tmp.quest);
    }
    fclose(file);
    return SUCCESS;
}

int init_chat_box_eng(dialogue_t *head, rpg_t *rpg, char *conf)
{
    struct stat st;

    head = NULL;
    if (stat(conf, &st) != 0) {
        fprintf(stderr, "ERROR: cannot find %s\n", TILES);
        return FAILURE;
    }
    chmod(conf, 777);
    if (parse_quests_conf(&head, conf) == 84)
        return FAILURE;
    if (head == NULL)
        return FAILURE;
    rpg->dialogue_eng = head;
    chmod(conf, 000);
    return SUCCESS;
}

int init_chat_box(dialogue_t *head, rpg_t *rpg, char *conf)
{
    struct stat st;

    head = NULL;
    if (stat(conf, &st) != 0) {
        fprintf(stderr, "ERROR: cannot find %s\n", TILES);
        return FAILURE;
    }
    chmod(conf, 777);
    if (parse_quests_conf(&head, conf) == 84)
        return FAILURE;
    if (head == NULL)
        return FAILURE;
    rpg->dialogue = head;
    chmod(conf, 000);
    return SUCCESS;
}
