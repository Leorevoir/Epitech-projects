/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** macro
*/

#ifndef MACRO_H_
    #define MACRO_H_
    #define COLOR_BOLD "\033[1;37m"
    #define COLOR_RESET "\033[0m"
    #define COLOR_YELLOW "\033[93m"
    #define COLOR_MAGENTA "\033[95m"
    #define COLOR_RED "\033[91m"
    #define COLOR_GREEN "\033[92m"
    #define COLOR_CYAN "\033[96m"
    #define COLOR_GRAY "\033[90m"
    #define DISPLAY_WIDTH 256
    #define INFO_SPACE 8
    #define UNSIGNED_LEN c < 16 ? 2 : 2
    #define FORK (int)war->arena[(i + T_DIR) % MEM_SIZE]
    #define IS_HEX_OR_NULL ctx->arena[ctx->i] < 16 ? "0%x" : "%x"

#endif /* !MACRO_H_ */
