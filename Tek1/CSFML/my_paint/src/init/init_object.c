/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** init_object
*/

#include "init.h"

game_object_t create_drawing(game_t *game)
{
    game_object_t obj;
    sfVector2f size = {RECT_WIDTH, RECT_HEIGHT};
    sfFloatRect bounds = sfSprite_getGlobalBounds(game->background.sprite);
    sfVector2f position = {(bounds.width - size.x) / 2,
        (bounds.height - size.y) / 1.3563};

    obj.texture = sfTexture_create(RECT_WIDTH, RECT_HEIGHT);
    obj.sprite = sfSprite_create();
    sfSprite_setTexture(obj.sprite, obj.texture, sfTrue);
    sfSprite_setPosition(obj.sprite, position);
    obj.position = position;
    return obj;
}

game_object_t create_object(const char *path, sfVector2f position)
{
    game_object_t obj;

    obj.texture = sfTexture_createFromFile(path, NULL);
    obj.sprite = sfSprite_create();
    sfSprite_setTexture(obj.sprite, obj.texture, sfTrue);
    obj.position = position;
    sfSprite_setPosition(obj.sprite, obj.position);
    return obj;
}

void init_menus(game_t *game)
{
    game->file_png.menu_sprite = create_object(
        FILE_PNG, (sfVector2f){0, 85});
    game->file_png.is_visible = false;
    game->edit_png.menu_sprite = create_object(
        EDIT_PNG, (sfVector2f){70, 85});
    game->edit_png.is_visible = false;
    game->help_png.menu_sprite = create_object(
        HELP_PNG, (sfVector2f){140, 85});
    game->help_png.is_visible = false;
    game->color_png.menu_sprite = create_object(
        COLOR_PNG, (sfVector2f){1540, 260});
    game->color_png.is_visible = false;
    game->size_png.menu_sprite = create_object(
        SIZE_PNG, (sfVector2f){1260, 200});
    game->size_png.is_visible = false;
}

void init_object(game_t *game)
{
    game->background = create_object(BACKGROUND, (sfVector2f){0, 0});
    game->about = create_object(ABOUT_PNG, (sfVector2f){0, 0});
    game->help = create_object(HELP_SLIDES, (sfVector2f){0, 0});
    game->drawing_zone = create_drawing(game);
    init_menus(game);
    game->color_circle = create_circle((float)20.7f,
        (sfVector2f){1445, 108});
    game->second_circle = create_circle((float)20.7f,
        (sfVector2f){1445, 158});
}
