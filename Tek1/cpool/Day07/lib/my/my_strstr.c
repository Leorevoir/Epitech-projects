/*
** EPITECH PROJECT, 2023
** MY_STRSTR
** File description:
** Reproduce strstr function
*/

int compare_str(const char *str1, const char *str2, int length)
{
    for (int a = 0; a < length; a++) {
        if (str1[a] != str2[a]) {
            return (0);
        }
    }
    return (1);
}

char *my_strstr(char *str, const char *to_find)
{
    int length_str = my_strlen(str);
    int length_find = my_strlen(to_find);
    int i = 0;

    if (length_str == 0 || length_find == 0 || length_find > length_str) {
        return (0);
    }
    for (i = 0; i < (length_str - length_find + 1); i++) {
        if (compare_str(str + i, to_find, length_find)) {
            return str + i;
        }
    }
    return (0);
}
