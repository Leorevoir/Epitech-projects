/*
** EPITECH PROJECT, 2023
** MY_STRNCAT
** File description:
** Concatenates n char of str
*/


int my_strlen3(char const *str)
{
    int nbr = 0;

    while (str[nbr] != '\0') {
        nbr++;
    }
    return (nbr);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int a = 0;
    int l = my_strlen3(dest);

    while (src[a] != '\0' && a < nb) {
        dest[l + a] = src[a];
        a++;
    }
    return (dest);
}
