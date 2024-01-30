/*
** EPITECH PROJECT, 2023
** MY_PRINT_ALPHA
** File description:
** Alphabet in lowercase
*/

int my_print_alpha(void)
{
    char letter = 'a';

    while (letter <= 'z') {
        my_putchar(letter);
        letter++;
    }
    return (0);
}
