/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** test_my_str_is_alpha
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_isalpha, test_with_alphabetical_characters)
{
    cr_assert(my_str_isalpha("abcdefghijklmnopqrstuvwxyz"));
}

Test(my_str_isalpha, test_with_non_alphabetical_characters)
{
    cr_assert_not(my_str_isalpha("123abc"));
}

Test(my_str_isalpha, test_with_empty_string)
{
    cr_assert(my_str_isalpha(""));
}
