/*
** EPITECH PROJECT, 2023
** MY_PRINT_PARAMS
** File description:
** Displays arguments
*/

void my_putcharr(char c)
{
    write(1, &c, 1);
}

int my_putstrr(char const *str)
{
    while (*str != '\0') {
        my_putcharr(*str);
        str++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int a = 0;

    while (argv[a] != '\0') {
        my_putstrr(argv[a]);
        my_putcharr('\n');
        a++;
    }
    return (0);
}
