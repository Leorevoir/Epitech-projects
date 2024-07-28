/*
** EPITECH PROJECT, 2024
** B-CPE-200-STG-2-1-corewar-raphael.petrequin
** File description:
** fill_arena
*/

#include "core.h"

static const char *select_color(champ_t *champ, unsigned char cell, int pc)
{
    if (pc) {
        return COLOR_BOLD;
    }
    if (champ) {
        return get_color_by_id(champ->id);
    }
    if (cell == '0') {
        return COLOR_GRAY;
    }
    return COLOR_RESET;
}

static champ_t *find_champ_by_pc(champ_t *head, int pc)
{
    while (head != NULL) {
        if (head->pc == pc) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

static void print_last_line(void)
{
    my_printf(COLOR_RESET COLOR_BOLD"|\n"COLOR_RESET);
    my_printf("%s+", COLOR_BOLD);
    for (int i = 0; i < DISPLAY_WIDTH; i++)
        my_printf("-");
    my_printf("+\n%s", COLOR_RESET);
}

static void print_first_line(void)
{
    my_printf("%s+", COLOR_BOLD);
    for (int i = 0; i < DISPLAY_WIDTH; i++)
        my_printf("-");
    my_printf("+\n|%s", COLOR_RESET);
}

static int format_arena_segment(context_t *ctx)
{
    char *buf_ptr = ctx->buffer;
    int buf_len = 0;

    buf_len = my_sprintf(buf_ptr, "%s", ctx->color);
    buf_ptr += buf_len;
    buf_len = my_sprintf(buf_ptr, IS_HEX_OR_NULL, ctx->arena[ctx->i]);
    buf_ptr += buf_len;
    if (ctx->champ_by_pc) {
        buf_len = my_sprintf(buf_ptr, COLOR_RESET);
    }
    return buf_len + (buf_ptr - ctx->buffer);
}

static int fill_arena(war_t *war, const unsigned char *arena, int i, int index)
{
    char buffer[DISPLAY_WIDTH * 4 + 3];
    context_t ctx = {
        .war = war, .arena = arena, .i = i, .index = index,
        .buffer = buffer, .champ_by_pc = find_champ_by_pc(war->head, i),
        .color = select_color(find_champ_by_instruction(
            war->head, arena, i), arena[i], ctx.champ_by_pc != NULL)
    };
    int buf_len = 0;

    if (ctx.index >= DISPLAY_WIDTH) {
        if (!war->done)
            print_info(war, ctx.color);
        else
            write(1, COLOR_RESET"|\n|", 8);
        ctx.index = 0;
    }
    buf_len = format_arena_segment(&ctx);
    my_printf("%s", ctx.buffer);
    ctx.index += 2;
    return ctx.index;
}

void print_arena(const unsigned char *arena, war_t *war)
{
    int index = 0;

    print_first_line();
    for (int i = 0; i < MEM_SIZE; i++) {
        index = fill_arena(war, arena, i, index);
    }
    while (index < DISPLAY_WIDTH) {
        write(1, "  ", 2);
        index += 2;
    }
    print_last_line();
}
