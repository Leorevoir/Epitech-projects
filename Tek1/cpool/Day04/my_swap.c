/*
** EPITECH PROJECT, 2023
** MY_SWAP
** File description:
** swap the content of 2 int
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
