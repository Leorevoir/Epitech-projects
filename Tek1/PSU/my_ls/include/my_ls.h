/*
** EPITECH PROJECT, 2023
** my ls h
** File description:
** my ls header
*/

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef MY_LS_H_
    #define MY_LS_H_

struct opt {
    int show_directory_only;
    int show_hidden;
    int long_type;
};

typedef void(*format_function)(va_list args);

void print_char(va_list args);
void print_string(va_list args);
void print_int(va_list args);
void print_percent(va_list args);
int my_printf(const char *format, ...);
int is_allowed(char c);
void my_putchar(char c);
void my_group(gid_t gid);
void my_put_nbr(int num);
void my_passwd(uid_t uid);
void my_time(time_t mtime);
int my_error(const char *str);
void my_rights(mode_t mode);
void my_put_str(char *str);
int my_strlen(const char *str);
int is_hidden(const char *name);
void my_sort(char **arg, int n);
char *my_strdup(const char *str);
int	my_strcmp(char *s1, char *s2);
int compare_names(char *a, char *b);
void sort_my(char **arg, int i, int j);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);
int long_format(const char *filename, const char *repertory);
void smart_ls(const char *filename, struct opt *options, const char *repo);

#endif /* !MY_LS_H_ */
