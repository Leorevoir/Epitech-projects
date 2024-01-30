/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_sort_params
*/

void my_sort_params(int argc, char **argv)
{
    char *current;
    int j;

    for (int i = 1; i < argc; i++) {
        current = argv[i];
        j = i - 1;
        while (j >= 0 && my_strcmp(current, argv[j]) < 0) {
            argv[j + 1] = argv[j];
            j--;
        }
        argv[j + 1] = current;
    }
    for (int i = 0; i < argc; i++) {
        j = 0;
        while (argv[i][j] != '\0') {
            my_putchar(argv[i][j]);
            j++;
        }
        my_putchar('\n');
    }
}
