/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** my_int_to_str.c
*/

void my_int_to_str(long int nb, char *str, int *index)
{
    if (nb >= 10)
        my_int_to_str(nb / 10, str, index);
    str[*index] = (nb % 10) + '0';
    (*index)++;
}

char *int_to_str(int nb, char *str)
{
    long int unb = nb;
    int index = 0;

    if (nb < 0) {
        str[index] = '-';
        index++;
        unb = -unb;
    }
    my_int_to_str(unb, str, &index);
    str[index] = '\0';
    return str;
}

int my_intlen(int nb)
{
    int res = 1;

    if (nb < 0) {
        nb = nb * -1;
        res ++;
        for (res; nb != 0; res++)
            nb = nb / 10;
    } else {
        for (res; nb > 9; res++)
            nb = nb / 10;
    }
    return (res);
}
