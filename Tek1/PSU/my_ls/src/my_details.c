/*
** EPITECH PROJECT, 2023
** my_details
** File description:
** my_details for ls
*/

#include "../include/my_ls.h"

void my_rights(mode_t mode)
{
    my_printf((S_ISDIR(mode)) ? "d" : "-");
    my_printf((mode & S_IRUSR) ? "r" : "-");
    my_printf((mode & S_IWUSR) ? "w" : "-");
    my_printf((mode & S_IXUSR) ? "x" : "-");
    my_printf((mode & S_IRGRP) ? "r" : "-");
    my_printf((mode & S_IWGRP) ? "w" : "-");
    my_printf((mode & S_IXGRP) ? "x" : "-");
    my_printf((mode & S_IROTH) ? "r" : "-");
    my_printf((mode & S_IWOTH) ? "w" : "-");
    my_printf((mode & S_IXOTH) ? "x" : "-");
}

void my_passwd(uid_t uid)
{
    struct passwd *pw = getpwuid(uid);

    if (pw != NULL) {
        my_printf(" %s", pw->pw_name);
    } else {
        my_printf(" %d", uid);
    }
}

void my_group(gid_t gid)
{
    struct group *gr = getgrgid(gid);

    if (gr != NULL)
        my_printf(" %s", gr->gr_name);
    else
        my_printf(" %d", gid);
}

void my_time(time_t mtime)
{
    char *time_str = ctime(&mtime);
    int len = my_strlen(time_str);

    if (len > 0 && time_str[len] == '\0') {
        time_str[len - 9] = '\0';
    }
    my_printf(" %s", time_str + 4);
}
