/*
** EPITECH PROJECT, 2023
** menu c
** File description:
** menu hunter
*/

#include "../include/game.h"

menu_s initialize_menu(void)
{
    menu_s menu;
    sfTexture *my_texture = sfTexture_createFromFile("data/menu/1.png", NULL);

    menu.sprite = sfSprite_create();
    sfSprite_setTexture(menu.sprite, my_texture, sfTrue);
    menu.play_txt = sfText_create();
    sfText_setString(menu.play_txt, "PLAY");
    sfText_setFont(menu.play_txt, sfFont_createFromFile(FONT_PATH));
    sfText_setCharacterSize(menu.play_txt, 50);
    sfText_setPosition(menu.play_txt, (sfVector2f){560, 300});
    menu.quit_txt = sfText_create();
    sfText_setString(menu.quit_txt, "QUIT");
    sfText_setFont(menu.quit_txt, sfFont_createFromFile(FONT_PATH));
    sfText_setCharacterSize(menu.quit_txt, 50);
    sfText_setPosition(menu.quit_txt, (sfVector2f){570, 400});
    return menu;
}

void render_menu(game_window_s *window, menu_s *menu)
{
    sfColor play_color = menu->is_play_hovered ? sfGreen : sfWhite;
    sfColor quit_color = menu->is_quit_hovered ? sfRed : sfWhite;

    sfRenderWindow_drawSprite(window->window, menu->sprite, NULL);
    sfText_setFillColor(menu->play_txt, play_color);
    sfText_setFillColor(menu->quit_txt, quit_color);
    sfRenderWindow_drawText(window->window, menu->play_txt, NULL);
    sfRenderWindow_drawText(window->window, menu->quit_txt, NULL);
    sfRenderWindow_display(window->window);
}
