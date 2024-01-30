/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** test_my_str_is_printable
*/

#include <criterion/criterion.h>

Test(my_str_isprintable, test_with_printable_characters)
{
    cr_assert(my_str_isprintable("Hello, World!"));
}

Test(my_str_isprintable, test_with_non_printable_characters)
{
    cr_assert_not(my_str_isprintable("This is a test\n"));
}

Test(my_str_isprintable, test_with_empty_string)
{
    cr_assert(my_str_isprintable(""));
}
