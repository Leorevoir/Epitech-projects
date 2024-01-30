/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_getnbr_base
*/

int char_to_int(char c, const char *base)
{
    int base_len = my_strlen(base);

    for (int i = 0; i < base_len; i++) {
        if (base[i] == c)
            return i;
    }
    return -1;
}

int my_getnbr_base(const char *str, const char *base)
{
    int base_len = my_strlen(base);
    int result = 0;
    int sign = 1;
    int i = 0;
    int value;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        value = char_to_int(str[i], base);
        if (value == -1)
            return 0;
        result = result * base_len + value;
        i++;
    }
    return result * sign;
}
