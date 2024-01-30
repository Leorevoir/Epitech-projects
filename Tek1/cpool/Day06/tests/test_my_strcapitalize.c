/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** test_my_strcapitalize
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_strcapitalize, empty_string)
{
    char str[] = "";

    cr_assert_str_eq(my_strcapitalize(str), "");
}

Test(my_strcapitalize, all_uppercase)
{
    char str[] = "HELLO WORLD";

    cr_assert_str_eq(my_strcapitalize(str), "Hello World");
}

Test(my_strcapitalize, all_lowercase)
{
    char str[] = "hello world";

    cr_assert_str_eq(my_strcapitalize(str), "Hello World");
}

Test(my_strcapitalize, special_characters_and_digits)
{
    char str[] = "hey, how are you? 42words forty-two; fifty+one";

    cr_assert_str_eq(my_strcapitalize(str),
        "Hey, How Are You? 42words Forty-Two; Fifty+One");
}

Test(my_strcapitalize, mixed_case)
{
    char str[] = "HeLLo, woRLd!";

    cr_assert_str_eq(my_strcapitalize(str), "Hello, World!");
}
