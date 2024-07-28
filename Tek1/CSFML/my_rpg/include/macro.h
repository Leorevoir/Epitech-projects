/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-raphael.petrequin
** File description:
** macro
*/

#ifndef MACRO_H_
    #define MACRO_H_

/////////// EXIT VALUES ///////////////
    #define SUCCESS 0
    #define FAILURE 84

/////////// DEFAULT WINDOWS ///////////
    #define DFLT_HEIGHT 1920
    #define DFLT_WIDTH 1080
    #define TWOK_HEIGHT 2048
    #define TWOK_WIDTH 1080
    #define S_WIDTH 767
    #define S_HEIGHT 512
    #define V_WIDTH 688
    #define V_HEIGHT 656
    #define TEST_WIDTH 512
    #define TEST_HEIGHT 383

/////////// UI PATH ///////////////////
    #define DIALOG_BOX "assets/hud/dialog_box.png"
    #define FONT "assets/hud/font.ttf"
    #define ARROW_UI "assets/hud/arrow.png"

/////////// BACKGROUND PATH ///////////
    #define MAP1 "./assets/background/map.png"
    #define MAP1_COLLISIONS "./assets/background/map_collisions.png"
    #define MAP2 "./assets/background/village.png"
    #define MAP2_COLLISIONS "assets/background/map_village_collision.png"
    #define MAP3 "./assets/background/map_boss.png"
    #define MAP3_COLLISIONS "./assets/background/map_boss_collisions.png"

/////////// INVENTORY/QUESTS PATH ////////////
    #define INVENTORY "./assets/hud/inventory.png"
    #define QUESTS "./assets/hud/quests.png"
    #define INVENTAIRE "./assets/hud/inventaire.png"
    #define QUETES "./assets/hud/quetes.png"
/////////// WEAPONS PATH //////////////
    #define SWORD "./assets/weapons/swords/sword_apprentice/SpriteInHand.png"
    #define SPEAR "./assets/weapons/spears/spear_apprentice/SpriteInHand.png"
    #define SWORD_PIC "./assets/weapons/swords/sword_apprentice/Sprite.png"
    #define SPEAR_PIC "./assets/weapons/spears/spear_apprentice/Sprite.png"
    #define BONE "./assets/weapons/bone/SpriteInHand.png"

/////////// PLAYER PATH ///////////////
    #define HP "assets/hud/Heart.png"

    #define FROG_UP "assets/player/frog/walk/up.png"
    #define FROG_DOWN "assets/player/frog/walk/down.png"
    #define FROG_LEFT "assets/player/frog/walk/left.png"
    #define FROG_RIGHT "assets/player/frog/walk/right.png"
    #define FROG_I_UP "assets/player/frog/idle/idle_up.png"
    #define FROG_I_DOWN "assets/player/frog/idle/idle_down.png"
    #define FROG_I_LEFT "assets/player/frog/idle/idle_left.png"
    #define FROG_I_RIGHT "assets/player/frog/idle/idle_right.png"
    #define FROG_A_UP "assets/player/frog/attack/attack_up.png"
    #define FROG_A_DOWN "assets/player/frog/attack/attack_down.png"
    #define FROG_A_LEFT "assets/player/frog/attack/attack_left.png"
    #define FROG_A_RIGHT "assets/player/frog/attack/attack_right.png"
    #define FROG_DEAD_PLAYER "assets/player/frog/others/Dead14.png"

    #define BOY_UP "assets/player/boy/walk/up.png"
    #define BOY_DOWN "assets/player/boy/walk/down.png"
    #define BOY_LEFT "assets/player/boy/walk/left.png"
    #define BOY_RIGHT "assets/player/boy/walk/right.png"
    #define BOY_I_UP "assets/player/boy/idle/idle_up.png"
    #define BOY_I_DOWN "assets/player/boy/idle/idle_down.png"
    #define BOY_I_LEFT "assets/player/boy/idle/idle_left.png"
    #define BOY_I_RIGHT "assets/player/boy/idle/idle_right.png"
    #define BOY_A_UP "assets/player/boy/attack/attack_up.png"
    #define BOY_A_DOWN "assets/player/boy/attack/attack_down.png"
    #define BOY_A_LEFT "assets/player/boy/attack/attack_left.png"
    #define BOY_A_RIGHT "assets/player/boy/attack/attack_right.png"
    #define BOY_DEAD_PLAYER "assets/player/boy/others/Dead.png"

    #define GIRL_UP "assets/player/girl/walk/up.png"
    #define GIRL_DOWN "assets/player/girl/walk/down.png"
    #define GIRL_LEFT "assets/player/girl/walk/left.png"
    #define GIRL_RIGHT "assets/player/girl/walk/right.png"
    #define GIRL_I_UP "assets/player/girl/idle/idle_up.png"
    #define GIRL_I_DOWN "assets/player/girl/idle/idle_down.png"
    #define GIRL_I_LEFT "assets/player/girl/idle/idle_left.png"
    #define GIRL_I_RIGHT "assets/player/girl/idle/idle_right.png"
    #define GIRL_A_UP "assets/player/girl/attack/attack_up.png"
    #define GIRL_A_DOWN "assets/player/girl/attack/attack_down.png"
    #define GIRL_A_LEFT "assets/player/girl/attack/attack_left.png"
    #define GIRL_A_RIGHT "assets/player/girl/attack/attack_right.png"
    #define GIRL_DEAD_PLAYER "assets/player/girl/others/Dead.png"

/////////// PLAYER PATH ///////////////
    #define BOY_IDLE_UP "assets/player/boy/idle/idle_up.png"
    #define BOY_IDLE_DOWN "assets/player/boy/idle/idle_down.png"
    #define BOY_IDLE_LEFT "assets/player/boy/idle/idle_left.png"
    #define BOY_IDLE_RIGHT "assets/player/boy/idle/idle_right.png"
    #define BOY_PICTURE "assets/hud/boy_pdp.png"

    #define FROG_IDLE_UP "assets/player/frog/idle/idle_up.png"
    #define FROG_IDLE_DOWN "assets/player/frog/idle/idle_down.png"
    #define FROG_IDLE_LEFT "assets/player/frog/idle/idle_left.png"
    #define FROG_IDLE_RIGHT "assets/player/frog/idle/idle_right.png"
    #define FROG_PICTURE "assets/hud/frog_pdp.png"

    #define GIRL_IDLE_UP "assets/player/girl/idle/idle_up.png"
    #define GIRL_IDLE_DOWN "assets/player/girl/idle/idle_down.png"
    #define GIRL_IDLE_LEFT "assets/player/girl/idle/idle_left.png"
    #define GIRL_IDLE_RIGHT "assets/player/girl/idle/idle_right.png"
    #define GIRL_PICTURE "assets/hud/girl_pdp.png"

/////////// NPC PATH ///////////////
    #define HUNTER_UP "assets/npc/hunter/walk/up.png"
    #define HUNTER_DOWN "assets/npc/hunter/walk/down.png"
    #define HUNTER_LEFT "assets/npc/hunter/walk/left.png"
    #define HUNTER_RIGHT "assets/npc/hunter/walk/right.png"
    #define HUNTER_I_UP "assets/npc/hunter/idle/idle_up.png"
    #define HUNTER_I_DOWN "assets/npc/hunter/idle/idle_down.png"
    #define HUNTER_I_LEFT "assets/npc/hunter/idle/idle_left.png"
    #define HUNTER_I_RIGHT "assets/npc/hunter/idle/idle_right.png"
    #define HUNTER_PICTURE "assets/npc/hunter/Faceset.png"
    #define HUNTER_POINT "assets/npc/hunter/others/point.png"
    #define HUNTER_JUMPP "assets/npc/hunter/others/Jump.png"

    #define SENSEI_UP "assets/npc/sensei/walk/up.png"
    #define SENSEI_DOWN "assets/npc/sensei/walk/down.png"
    #define SENSEI_LEFT "assets/npc/sensei/walk/left.png"
    #define SENSEI_RIGHT "assets/npc/sensei/walk/right.png"
    #define SENSEI_I_UP "assets/npc/sensei/idle/idle_up.png"
    #define SENSEI_I_DOWN "assets/npc/sensei/idle/idle_down.png"
    #define SENSEI_I_LEFT "assets/npc/sensei/idle/idle_left.png"
    #define SENSEI_I_RIGHT "assets/npc/sensei/idle/idle_right.png"
    #define SENSEI_PICTURE "assets/npc/sensei/Faceset.png"

/////////// ENEMY PATH //////////////////////////
    #define SKLT_UP "assets/hostile_mobs/skeleton/walk/up.png"
    #define SKLT_DOWN "assets/hostile_mobs/skeleton/walk/down.png"
    #define SKLT_LEFT "assets/hostile_mobs/skeleton/walk/left.png"
    #define SKLT_RIGHT "assets/hostile_mobs/skeleton/walk/right.png"
    #define SKLT_I_UP "assets/hostile_mobs/skeleton/idle/idle_up.png"
    #define SKLT_I_DOWN "assets/hostile_mobs/skeleton/idle/idle_down.png"
    #define SKLT_I_LEFT "assets/hostile_mobs/skeleton/idle/idle_left.png"
    #define SKLT_I_RIGHT "assets/hostile_mobs/skeleton/idle/idle_right.png"
    #define SKLT_PICTURE "assets/hostile_mobs/skeleton/Faceset.png"
    #define SKLT_ATTACK1 "assets/hostile_mobs/skeleton/attack/attack_up.png"
    #define SKLT_ATTACK2 "assets/hostile_mobs/skeleton/attack/attack_down.png"
    #define SKLT_ATTACK3 "assets/hostile_mobs/skeleton/attack/attack_left.png"
    #define SKLT_ATTACK4 "assets/hostile_mobs/skeleton/attack/attack_right.png"

/////////// WHITE THING FIRE IDK ////////////////
    #define WHITE_THING_FIRE_HIT "assets/boss/blue_spirit/Hit.png"
    #define WHITE_THING_FIRE "assets/boss/blue_spirit/Idle.png"

/////////// RED THING FIRE IDK //////////////////
    #define RED_THING_FIRE_HIT "assets/boss/red_spirit/Hit.png"
    #define RED_THING_FIRE "assets/boss/red_spirit/Idle.png"
    #define RED_SMALL1 "assets/boss/mini_red_spirit/walk/down.png"

/////////// SQUELETON ///////////////////////////
    #define UP_S "assets/hostile_mobs/skeleton/walk/up.png"
    #define DOWN_S "assets/hostile_mobs/skeleton/walk/down.png"
    #define LEFT_S "assets/hostile_mobs/skeleton/walk/left.png"
    #define RIGHT_S "assets/hostile_mobs/skeleton/walk/right.png"
    #define I_UP_S "assets/hostile_mobs/skeleton/idle/idle_up.png"
    #define I_DOWN_S "assets/hostile_mobs/skeleton/idle/idle_down.png"
    #define I_LEFT_S "assets/hostile_mobs/skeleton/idle/idle_left.png"
    #define I_RIGHT_S "assets/hostile_mobs/skeleton/idle/idle_right.png"
    #define A_UP_S "assets/hostile_mobs/skeleton/attack/attack_up.png"
    #define A_DOWN_S "assets/hostile_mobs/skeleton/attack/attack_down.png"
    #define A_LEFT_S "assets/hostile_mobs/skeleton/attack/attack_left.png"
    #define A_RIGHT_S "assets/hostile_mobs/skeleton/attack/attack_right.png"

/////////// TEST FX /////////////////////////////
    #define SMOKE "assets/fx/smoke.png"
    #define ROCKET "assets/fx/rocket.png"
    #define HEAL "assets/fx/heal.ogg"
    #define THUNDER "assets/fx/thunder.png"
    #define HEAL_SOUND "assets/fx/heal.ogg"
    #define BOSS_MUSIC "assets/musics_sounds/boss_music.ogg"
    #define ROAD_MUSIC "assets/musics_sounds/road_music.ogg"
    #define MENU_MUSIC "assets/musics_sounds/menu_music.ogg"
    #define VILLAGE_MUSIC "assets/musics_sounds/village_music.ogg"
    #define WIN_MUSIC "assets/musics_sounds/win_music.ogg"
    #define LOSE_MUSIC "assets/musics_sounds/lose_music.ogg"
    #define SWIPE_SOUND "assets/musics_sounds/swipe_sound.ogg"

/////////// PLAYER DATA /////////////////////////
    #define PLAYER_SPEED 0.8
    #define PLAYER_POSX 150
    #define PLAYER_POSY 425
    #define STATS "assets/stats.conf"
    #define CMD_INV rpg->inventory
    #define VECT sfVector2f
    #define PP_POS_X CMD_INV.inventory.position.x + 590
    #define PP_POS_Y CMD_INV.inventory.position.y + 76

/////////// MACRO FCT CSFML /////////////////////
    #define KEY_PRESSED sfKeyboard_isKeyPressed
    #define SET_POS sfText_setPosition
    #define GET_STRING sfText_getString
    #define DRAW_SPRITE sfRenderWindow_drawSprite

/////////// TILES MAGIC /////////////////////////
    #define MAGIC 14
    #define TREE strcmp(current->name, "tree")
    #define BACK strcmp(current->name, "house_back")

/////////// MAGIC NB ////////////////////////////
    #define PI 3.14159265358979323846
    #define PROXIMITY_THRESHOLD 25.0f
    #define TEXT_SPEED 50
    #define ARROW_OFFSET_X 830
    #define ARROW_OFFSET_Y 110
    #define BOX_OFFSET_X -100
    #define BOX_OFFSET_Y 50
    #define TEXT_OFFSET_X 150
    #define TEXT_OFFSET_Y 70
    #define PICTURE_OFFSET_X 17
    #define PICTURE_OFFSET_Y 42
    #define NAME_OFFSET_X 25
    #define NAME_OFFSET_Y -3
    #define SET_TEXTURE sfSprite_setTexture
    #define IPL hud->players
    #define SCALE sfSprite_setScale
    #define NPOS npc->object.position
    #define COLOR_RESET "\033[0m"
    #define COLOR_RED "\033[91m"
    #define COLOR_BOLD "\033[1;37m"
    #define COLOR_GREEN "\033[92m"

/////////// MAGIC NPC IA ///////////////
    #define DISTANCE(x, y, a, b) sqrt(pow((a) - (x), 2) + pow((b) - (y), 2))
    #define CALCULATE_RATIO(speed, distance) ((speed) / (distance))
    #define IDLE_DIRECTION(direction) ((direction) + 4)
    #define MIN_DISTANCE 24
    #define HUNTER_SPEED 1.3f

/////////// MAGIC CINEMATIC ///////////////
    #define INTERPOLATE(start, end, t) ((start) + (t) * ((end) - (start)))

#endif /* !MACRO_H_ */
