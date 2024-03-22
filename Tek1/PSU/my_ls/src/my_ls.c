/*
** EPITECH PROJECT, 2023
** my ls
** File description:
** my_ls
*/

#include "../include/my_ls.h"

int my_error(const char *str)
{
    write(2, str, my_strlen(str));
    return 84;
}

int process_option(struct opt *options, const char *arg)
{
    for (int j = 1; arg[j] != '\0'; ++j) {
        if (!is_allowed(arg[j])) {
            my_printf("ls: invalid option -- '%c'\n", arg[j]);
            my_printf("Try 'ls --help' for more information.");
            return 84;
        }
        if (arg[j] == 'a')
            options->show_hidden = 1;
        if (arg[j] == 'l')
            options->long_type = 1;
        if (arg[j] == 'd')
            options->show_directory_only = 1;
    }
}

struct opt parse_options(int argc, char **argv)
{
    struct opt options = {0};

    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-')
            process_option(&options, argv[i]);
    }
    return options;
}

static void backslash(struct opt *options)
{
    if (!options->long_type) {
        my_putchar('\n');
    }
}

static void print_directory(const char *dirname)
{
    my_printf("%s\n", dirname);
}

int main(int argc, char **argv)
{
    const char *repertory = (argc > 1 && argv[1][0] != '-') ? argv[1] : ".";
    struct opt options = parse_options(argc, argv);
    DIR *dir = opendir(repertory);
    struct dirent *entree;

    if (dir == NULL) {
        my_error("No such file or directory");
        return 84;
    }
    if (options.show_directory_only) {
        print_directory(repertory);
        return 0;
    }
    for (; entree = readdir(dir); entree != NULL) {
        smart_ls(entree->d_name, &options, repertory);
    }
    closedir(dir);
    backslash(&options);
    return 0;
}
