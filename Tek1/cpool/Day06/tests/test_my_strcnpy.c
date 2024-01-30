/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** test_my_strcnpy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[10] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_string_in_empty_array)
{
    char my_dest[10] = {0};
    char dest[10] = {0};

    my_strncpy(my_dest, "Hello", 6);
    strncpy(dest, "Hello", 6);
    cr_assert_str_eq(my_dest, dest);
}
