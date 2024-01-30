/*
** EPITECH PROJECT, 2023
** MY_STRUPCASE
** File description:
** Every letters uppercase
*/

char *my_strupcase(char *str)
{
    int a = 0;

    if (str[0] == '\0') {
        return (str);
    }
    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] >= 'a' && str[a] <= 'z') {
            str[a] = str[a] - ('a' - 'A');
            }
    }
    return (str);
}
