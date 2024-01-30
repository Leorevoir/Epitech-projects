/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_showstr
*/

int my_showstr(char const *str)
{
    while (*str != '\0') {
        if (*str >= 32 && *str <= 126) {
            my_putchar(*str);
        } else {
            my_putchar('\\');
            my_putchar((*str >> 4) + '0');
            my_putchar((*str & 0x0F) + '0');
        }
        str++;
    }
    return 0;
}
