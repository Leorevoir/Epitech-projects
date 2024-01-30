/*
** EPITECH PROJECT, 2023
** MY_REV_PARAMS
** File description:
** Displays arg rev
*/

void my_putchar2(char c)
{
    write(1, &c, 1);
}

int my_putstr2(char const *str)
{
    while (*str != '\0') {
        my_putchar2(*str);
        str++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int a = 0;

    while (argv[a] != '\0') {
        a++;
    }
    while (a != 0) {
        a--;
        my_putstr2(argv[a]);
        my_putchar2('\n');
    }
    return (0);
}
