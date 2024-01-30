/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** test_my_str_is_lower
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_islower, test_with_lowercase_characters)
{
    cr_assert(my_str_islower("abcdefghijklmnopqrstuvwxyz"));
}

Test(my_str_islower, test_with_mixed_characters)
{
    cr_assert_not(my_str_islower("abcDeFG"));
}

Test(my_str_islower, test_with_empty_string)
{
    cr_assert(my_str_islower(""));
}
