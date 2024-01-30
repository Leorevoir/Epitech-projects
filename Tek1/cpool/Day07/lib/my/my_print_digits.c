/*
** EPITECH PROJECT, 2023
** MY_PRINT_DIGITS
** File description:
** Print all digits
*/

int my_print_digits(void)
{
    char digit = '0';

    while (digit <= '9') {
        my_putchar(digit);
        digit++;
            }
    return (0);
}
