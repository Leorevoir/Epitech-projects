/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** my_showmem
*/

static void print_hex(unsigned char c)
{
    const char *hex_chars = "0123456789abcdef";

    my_putchar(hex_chars[c >> 4]);
    my_putchar(hex_chars[c & 0x0F]);
}

static int is_printable(char c)
{
    return c >= 32 && c <= 126;
}

static void print_mem(unsigned char *mem, int i, int j, int size)
{
    if (i + j < size)
        print_hex(mem[i + j]);
    else {
        my_putchar(' ');
        my_putchar(' ');
    }
    if (j % 2 == 1)
        my_putchar(' ');
}

static void mem_print(unsigned char *mem, int i, int j, int size)
{
    if (i + j < size) {
        if (is_printable(mem[i + j]))
            my_putchar(mem[i + j]);
        else
            my_putchar('.');
    }
}

int my_showmem(const char *str, int size)
{
    unsigned char *mem = (unsigned char *)str;

    for (int i = 0; i < size; i += 16) {
        print_hex(i >> 8);
        print_hex(i & 0xFF);
        my_putchar(':');
        my_putchar(' ');
        for (int j = 0; j < 16; j++)
            print_mem(mem, i, j, size);
        my_putchar(' ');
        for (int j = 0; j < 16; j++)
            mem_print(mem, i, j, size);
        my_putchar('\n');
    }
    return 0;
}
