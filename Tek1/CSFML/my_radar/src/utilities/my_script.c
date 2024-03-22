/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-leo.quinzler
** File description:
** my_script
*/

#include "../../include/radar.h"

void process_script_line(radar_t *radar, char *line)
{
    char **words = my_split(line);
    int result = parse_line(radar, words, my_split_length(words));

    my_free_split(words);
    if (result == 84) {
        my_putstr("ERROR:\n  invalid file\n  try ./my_radar -h\n");
        radar->value = STATUS_ERROR;
    }
}

void load_script(radar_t *radar, char *path)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    if (file == NULL) {
        my_putstr("ERROR:\n  invalid file\n  try ./my_radar -h\n");
        radar->value = STATUS_ERROR;
        return;
    }
    while (getline(&line, &len, file) != -1) {
        process_script_line(radar, line);
        if (radar->value == STATUS_ERROR) {
            break;
        }
    }
    fclose(file);
    free(line);
}

void radar_parse_arguments(radar_t *radar, int argc, char **argv)
{
    if (argc != 2) {
        handle_invalid_args(radar);
        return;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        handle_help_option(radar);
        return;
    }
    load_script(radar, argv[1]);
    if (radar->value == STATUS_ERROR)
        return;
    radar_initialize(radar);
}
