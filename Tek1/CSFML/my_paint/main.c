/*
** EPITECH PROJECT, 2024
** MAIN
** File description:
** main
*/

#include "my_string.h"
#include "game.h"

int display_help(void)
{
    write(1, "USAGE\n\t./my_paint\n", 18);
    write(1, "DESCRIPTION\n\tmy_paint is a paint-like software\n", 47);
    write(1, "HANDLES\n\t.png .jpg files \n", 27);
    write(1, "\tCTRL + S = save\n", 18);
    write(1, "\tCTRL + O = open\n", 18);
    write(1, "\tCTRL + N = new\n", 17);
    return EXIT_SUCCESS;
}

void run_paint(game_t *game)
{
    sfEvent event;

    game->slide = 0;
    game->create_pop = 0;
    while (sfRenderWindow_isOpen(game->window)) {
        handle_events(game);
        if (game->mouse_pressed)
            pencil_draw(game);
        display_paint(game);
        if (game->pop_about != sfFalse)
            about_pop_up(game, event);
        if (game->pop_help != sfFalse)
            help_pop_up(game, event);
    }
}

int main(int ac, char **av)
{
    game_t game;

    if (ac == 1) {
        init_paint(&game);
        run_paint(&game);
        destroy_paint(&game);
        return EXIT_SUCCESS;
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return display_help();
    write(1, "Wrong flag or too many arguments; try using -h\n", 48);
    return 84;
}
