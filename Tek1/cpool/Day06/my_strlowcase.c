/*
** EPITECH PROJECT, 2023
** MY_STRLOWCASE
** File description:
** Every world in lowercase
*/

char *my_strlowcase(char *str)
{
    int a = 0;

    if (str[0] == '\0') {
        return (str);
    }
    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] >= 'A' && str[a] <= 'Z') {
            str[a] = str[a] - ('A' - 'a');
                }
    }
    return (str);
}
