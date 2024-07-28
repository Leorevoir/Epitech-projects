/*
** EPITECH PROJECT, 2024
** menu.h
** File description:
** menu
*/


#include "enum.h"
#include "object.h"
#include <stdbool.h>

#ifndef MENU_H_
    #define MENU_H_

typedef struct menu_t {
    bool display;
    bool escape;
    sfTexture *back;
    sfSprite *back_sprite;
    sfTexture *name;
    sfSprite *name_sprite;
    sfTexture *ingame_eng;
    sfTexture *hngame_eng;
    sfTexture *pngame_eng;
    sfTexture *ingame_fr;
    sfTexture *hngame_fr;
    sfTexture *pngame_fr;
    sfSprite *ngame_sprite;
    sfRectangleShape *ngame_rect;
    sfTexture *ilgame_eng;
    sfTexture *hlgame_eng;
    sfTexture *plgame_eng;
    sfTexture *ilgame_fr;
    sfTexture *hlgame_fr;
    sfTexture *plgame_fr;
    sfSprite *lgame_sprite;
    sfRectangleShape *lgame_rect;
    sfTexture *isetting_eng;
    sfTexture *hsetting_eng;
    sfTexture *psetting_eng;
    sfTexture *isetting_fr;
    sfTexture *hsetting_fr;
    sfTexture *psetting_fr;
    sfSprite *settings_sprite;
    sfRectangleShape *setting_rect;
    sfTexture *iexit_eng;
    sfTexture *hexit_eng;
    sfTexture *pexit_eng;
    sfTexture *iexit_fr;
    sfTexture *hexit_fr;
    sfTexture *pexit_fr;
    sfSprite *exit_sprite;
    sfRectangleShape *exit_rect;
    sfTexture *iresume_eng;
    sfTexture *hresume_eng;
    sfTexture *presume_eng;
    sfTexture *iresume_fr;
    sfTexture *hresume_fr;
    sfTexture *presume_fr;
    sfSprite *resume_sprite;
    sfRectangleShape *r_rect;
    object_t save;
    sfTexture *save_i;
    sfTexture *save_h;
    sfTexture *save_p;
    sfTexture *save_i_fr;
    sfTexture *save_h_fr;
    sfTexture *save_p_fr;
} menu_t;

typedef struct characters_s {
    bool display;
    sfTexture *log;
    sfSprite *log_sprite;
    sfTexture *boy;
    sfSprite *boy_sprite;
    sfRectangleShape *boy_rect;
    sfSprite *cadre_boy;
    sfTexture *frog;
    sfSprite *frog_sprite;
    sfRectangleShape *frog_rect;
    sfSprite *cadre_frog;
    sfTexture *girl;
    sfSprite *girl_sprite;
    sfRectangleShape *girl_rect;
    sfSprite *cadre_girl;
    sfTexture *cadre;
    sfTexture *choosed;
    sfTexture *icontinue;
    sfTexture *hcontinue;
    sfTexture *pcontinue;
    sfSprite *continue_sprite;
    sfRectangleShape *continue_rect;
    int who;
} characters_t;

typedef struct settings_s {
    bool display;
    sfFont *font;
    sfTexture *plate;
    sfSprite *plate_sprite;
    sfTexture *ienglish;
    sfTexture *henglish;
    sfTexture *penglish;
    sfSprite *english_sprite;
    sfRectangleShape *english_rect;
    sfTexture *ifrench;
    sfTexture *hfrench;
    sfTexture *pfrench;
    sfSprite *french_sprite;
    sfRectangleShape *french_rect;
    sfText *language;
    sfText *volume;
    bool display_res;
    sfText *resolution;
    sfSprite **res_sprite;
    sfTexture *res_round;
    sfText *res1920;
    sfText *resfull;
    sfText *res_choosed;
    sfSprite *triangle_sprite;
    sfTexture *triangle;
    bool sound_check;
    bool music_check;
    sfText *music;
    sfText *sound;
    sfSprite **square_sprite;
    sfSprite **check_sprite;
    sfTexture *check;
    sfTexture *square;
    sfRectangleShape *vol_bar;
    sfCircleShape *vol_point;
} settings_t;

typedef struct menu_show_s {
    sfTexture *boy[MAX_COUNT];
    sfTexture *girl[MAX_COUNT];
    sfTexture *frog[MAX_COUNT];
    object_t my_boy;
    object_t my_girl;
    object_t my_frog;
} menu_show_t;

////////// MENU SHOW PLAYERS ////////////////

typedef struct hud_s {
    bool display;
    menu_t *menu;
    menu_show_t *players;
    sfTexture *iback_eng;
    sfTexture *hback_eng;
    sfTexture *pback_eng;
    sfTexture *iback_fr;
    sfTexture *hback_fr;
    sfTexture *pback_fr;
    sfSprite *back_sprite;
    sfRectangleShape *back_rect;
    characters_t *chars;
    settings_t *sett;
} hud_t;

#endif /* !MENU_H_ */
