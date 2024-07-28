/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** tab
*/

#include "core.h"

char *my_hex_code[] = {
    "0x01", "0x02", "0x03", "0x04",
    "0x05", "0x06", "0x07", "0x08", "0x09",
    "0x0a", "0x0b", "0x0c", "0x0d",
    "0x0e", "0x0f", "0x10",
    NULL
};

inst_func_t func[] = {
    &my_live, &my_ld, &my_st, &my_add,
    &my_sub, &my_and, &my_or, &my_xor, &my_zjmp,
    &my_ldi, &my_sti, &my_ffork, &my_lld,
    &my_lldi, &my_lfork, &my_aff,
    NULL
};
