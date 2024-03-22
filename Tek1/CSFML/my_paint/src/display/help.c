/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** help
*/

#include "game.h"
#include "my_string.h"

//ta fonction pour le help mapée
//elle est inclue dans event.h
//je te conseil de faire des fichiers différents
void handle_help_events(game_t *game, sfEvent event)
{
    (void)game;
    (void)event;
}

//ta fonction pour le about mapée
//elle est inclue dans event.h
//je te conseil de faire des fichiers différents
void handle_about_events(game_t *game, sfEvent event)
{
    (void)game;
    (void)event;
}

void about(game_t *game)
{
    game->pop_about = sfTrue;
    game->selected_tool = ABOUT;
}

void hhelp(game_t *game)
{
    game->pop_help = sfTrue;
    game->selected_tool = HELP;
}
