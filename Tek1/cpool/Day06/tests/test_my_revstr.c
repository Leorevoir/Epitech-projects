/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** test_my_revstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_revstr, reverse_string)
{
    char str1[] = "Hello";
    char str2[] = "World";
    
    my_revstr(str1);
    my_revstr(str2);
    cr_assert_str_eq(str1, "olleH");
    cr_assert_str_eq(str2, "dlroW");
}
