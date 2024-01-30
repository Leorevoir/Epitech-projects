/*
** EPITECH PROJECT, 2023
** MY_EVIL_STR
** File description:
** Swap string
*/

char *my_evil_str(char *str)
{
    int leng = my_strlen(str);
    char temp = ' ';
    int i = 0;

    if (!str) {
        return (str);
    }
    for (i = 0; i < leng / 2; i++) {
        temp = str[i];
        str[i] = str[leng - 1 - i];
        str[leng - 1 - i] = temp;
    }
    return (str);
}
