/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** display_chat_box
*/

#include "display.h"
#include "update.h"

static tmp_txt_t *init_tmp_txt(rpg_t *rpg, const char *txt_to_print)
{
    tmp_txt_t *tmp = malloc(sizeof(tmp_txt_t));

    tmp->clock = sfClock_create();
    tmp->elapsed_time = sfClock_getElapsedTime(tmp->clock);
    tmp->elapsed_seconds = 0.0f;
    tmp->text_length = strlen(txt_to_print);
    tmp->pos.x = rpg->player.object.position.x - 50;
    tmp->pos.y = rpg->player.object.position.y + 40;
    tmp->displayed_text = calloc(tmp->text_length + 1, sizeof(char));
    return tmp;
}

static void free_tmp_txt(tmp_txt_t *tmp)
{
    sfClock_destroy(tmp->clock);
    free(tmp->displayed_text);
    free(tmp);
}

void display_text_box(rpg_t *rpg, tmp_txt_t *tmp,
    const sfView *default_view, npc_t *npc)
{
    sfText_setString(rpg->text->text, tmp->displayed_text);
    sfText_setString(rpg->text->name, npc->name);
    sfRenderWindow_setView(rpg->window, default_view);
    sfRenderWindow_drawSprite(rpg->window, rpg->ui->text_box.sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, npc->picture.sprite, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->text->text, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->text->name, NULL);
    sfRenderWindow_setView(rpg->window, rpg->view);
}

static void continue_displaying_text(text_t *text, rpg_t *rpg,
    const sfView *default_view, npc_t *npc)
{
    sfTime time = sfClock_getElapsedTime(rpg->ui->clock);
    float seconds = time.microseconds / 1000000.0;

    sfText_setString(text->text, text->txt_to_print);
    sfText_setString(text->name, npc->name);
    sfRenderWindow_setView(rpg->window, default_view);
    sfRenderWindow_drawSprite(rpg->window, rpg->ui->text_box.sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, npc->picture.sprite, NULL);
    sfRenderWindow_drawText(rpg->window, text->text, NULL);
    sfRenderWindow_drawText(rpg->window, text->name, NULL);
    if (((int)(seconds * 2)) % 2 == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->ui->arrow.sprite, NULL);
    sfRenderWindow_setView(rpg->window, rpg->view);
}

static void skip_some_keys(rpg_t *rpg, sfEvent *event)
{
    sfKeyCode key = event->key.code;

    if (key != sfKeyZ && key != sfKeyQ && key != sfKeyS && key != sfKeyD &&
        key != sfKeyLShift && key != sfKeyRShift &&
        key != sfKeyUp && key != sfKeyDown &&
        key != sfKeyLeft && key != sfKeyRight) {
        rpg->text->continue_display = false;
    }
}

void do_we_continue(
    rpg_t *rpg, npc_t *npc, sfEvent *event, const sfView *default_view)
{
    while (sfRenderWindow_pollEvent(rpg->window, event)) {
        if (event->type == sfEvtKeyPressed
            || event->type == sfEvtMouseButtonReleased) {
            skip_some_keys(rpg, event);
        }
    }
    continue_displaying_text(rpg->text, rpg, default_view, npc);
    sfRenderWindow_display(rpg->window);
}

void display_text(text_t *text, rpg_t *rpg, npc_t *npc, sfEvent *event)
{
    tmp_txt_t *tmp = init_tmp_txt(rpg, text->txt_to_print);
    const sfView *default_view = sfRenderWindow_getDefaultView(rpg->window);
    size_t index = 0;

    while (index < tmp->text_length) {
        update_text_box(tmp, rpg, npc);
        if (tmp->elapsed_seconds >= 1.f / TEXT_SPEED) {
            tmp->displayed_text[index] = text->txt_to_print[index];
            tmp->displayed_text[index + 1] = '\0';
            display_text_box(rpg, tmp, default_view, npc);
            index++;
            sfClock_restart(tmp->clock);
        }
        sfRenderWindow_display(rpg->window);
    }
    rpg->text->continue_display = true;
    while (rpg->text->continue_display)
        do_we_continue(rpg, npc, event, default_view);
    free_tmp_txt(tmp);
}
