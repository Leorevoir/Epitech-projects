/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char temp;

    while (str[j] != '\0') {
        j++;
    }
    j--;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}
