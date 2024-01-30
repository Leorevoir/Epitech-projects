/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
