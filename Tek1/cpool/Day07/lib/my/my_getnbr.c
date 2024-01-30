/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_getnbr
*/

int check_sign(const char *str, int *i)
{
    int sign = 1;

    while (str[*i] == ' ' || str[*i] == '+'
        || str[*i] == '-') {
        if (str[*i] == '-')
            sign *= -1;
        (*i)++;
    }
    if (str[*i] < '0' || str[*i] > '9')
        return 0;
    return sign;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = check_sign(str, &i);
    int res = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        if (res > 2147483647 / 10
            || (res == 2147483647 / 10
            && (str[i] - '0') > (2147483647 % 10))) {
            return 0;
        }
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res * sign;
}
