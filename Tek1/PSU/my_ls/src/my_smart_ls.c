/*
** EPITECH PROJECT, 2023
** smart ls
** File description:
** my_smart_ls
*/

#include "../include/my_ls.h"

int is_hidden(const char *name)
{
    return name[0] == '.';
}

int is_allowed(char c)
{
    const char *allowed = "ald";

    for (int i = 0; allowed[i]; i++)
        if (allowed[i] == c)
            return 1;
    return 0;
}

int long_format(const char *filename, const char *repertory)
{
    char path[512];
    struct stat file_stat;

    my_strcpy(path, repertory);
    my_strcat(path, "/");
    my_strcat(path, filename);
    if (stat(path, &file_stat) == -1) {
        my_error("Stat error");
        return 84;
    }
    my_rights(file_stat.st_mode);
    my_printf(". %d", file_stat.st_nlink);
    my_passwd(file_stat.st_uid);
    my_group(file_stat.st_gid);
    my_printf(" %d", file_stat.st_size);
    my_time(file_stat.st_mtime);
    my_printf(" %s\n", filename);
    return 0;
}

void smart_ls(const char *filename, struct opt *options, const char *repo)
{
    char path[512];

    my_strcpy(path, repo);
    my_strcat(path, "/");
    my_strcat(path, filename);
    if (!options->show_hidden && is_hidden(filename))
       return;
    if (options->long_type)
        long_format(filename, repo);
    else
        my_printf("%s ", filename);
}
