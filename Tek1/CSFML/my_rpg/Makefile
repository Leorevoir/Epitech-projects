##
## EPITECH PROJECT, 2024
## rpg
## File description:
## Makefile
##

CFLAGS = -I./include

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

INIT_DIR = src/init
DISP_DIR = src/display
DEST_DIR = src/destroy
UPDATE_DIR = src/update
EVENT_DIR = src/events
TILES_DIR = src/tiles
COLL_DIR = src/collisions
VERTEX_DIR = src/vertex
OBJ_DIR = object

MAIN = \
	src/main.c				\
	src/game_loop.c			\
	src/first_load_screen.c	\
	src/load_screen_esc.c

INIT = \
	$(INIT_DIR)/init_rpg.c			\
	$(INIT_DIR)/init_npc.c			\
	$(INIT_DIR)/init_boss.c			\
	$(INIT_DIR)/init_maps.c			\
	$(INIT_DIR)/init_menu.c			\
	$(INIT_DIR)/init_window.c		\
	$(INIT_DIR)/init_object.c		\
	$(INIT_DIR)/init_player.c		\
	$(INIT_DIR)/init_chat_box.c		\
	$(INIT_DIR)/init_text.c			\
	$(INIT_DIR)/init_ui.c			\
	$(INIT_DIR)/init_weapon.c		\
	$(INIT_DIR)/init_inventory.c 	\
	$(INIT_DIR)/init_stats.c		\
	$(INIT_DIR)/init_menu_choose.c	\
	$(INIT_DIR)/init_player_choose.c\
	$(INIT_DIR)/init_settings_hud.c \
	$(INIT_DIR)/init_resolution.c \
	$(INIT_DIR)/init_musical_settings.c \
	$(INIT_DIR)/init_escape_menu.c	\
	$(INIT_DIR)/init_music.c

UPDATE = \
	$(UPDATE_DIR)/update_ui.c						\
	$(UPDATE_DIR)/update_npc.c						\
	$(UPDATE_DIR)/update_rpg.c						\
	$(UPDATE_DIR)/update_view.c						\
	$(UPDATE_DIR)/update_menu.c						\
	$(UPDATE_DIR)/update_escape_menu.c				\
	$(UPDATE_DIR)/update_hover_buttons.c 			\
	$(UPDATE_DIR)/update_settings_hud.c				\
	$(UPDATE_DIR)/update_musical.c					\
	$(UPDATE_DIR)/attack/update_attack.c			\
	$(UPDATE_DIR)/attack/handle_attack_spear.c		\
	$(UPDATE_DIR)/attack/handle_attack_sword.c		\
	$(UPDATE_DIR)/update_txt_box.c 					\
	$(UPDATE_DIR)/update_movement.c					\
	$(UPDATE_DIR)/big_boss/update_big.c				\
	$(UPDATE_DIR)/big_boss/angry_boss.c				\
	$(UPDATE_DIR)/big_boss/angry_boss_animations.c	\
	$(UPDATE_DIR)/big_boss/update_smoke.c 			\
	$(UPDATE_DIR)/update_player_choose.c			\
	$(UPDATE_DIR)/update_inventory.c				\
	$(UPDATE_DIR)/update_save_menu.c				\
	$(UPDATE_DIR)/big_boss/update_big_animation.c	\
	$(UPDATE_DIR)/quests/tools.c					\
	$(UPDATE_DIR)/quests/move_npc.c					\
	$(UPDATE_DIR)/quests/what_quests.c				\
	$(UPDATE_DIR)/quests/sensei_quests.c			\
	$(UPDATE_DIR)/quests/move_hunter.c				\
	$(UPDATE_DIR)/quests/hunter_quests.c			\
	$(UPDATE_DIR)/quests/sklt_weapon_pos.c			\
	$(UPDATE_DIR)/quests/sklt/sklt_attack.c			\
	$(UPDATE_DIR)/quests/handle_tuto_move.c			\
	$(UPDATE_DIR)/quests/update_status.c			\
	$(UPDATE_DIR)/update_music.c					\
	$(UPDATE_DIR)/checkup_music.c					\
	$(UPDATE_DIR)/update_cinematic.c				\
	$(UPDATE_DIR)/update_window.c					\
	$(UPDATE_DIR)/update_last_quest.c

COLL = \
	$(COLL_DIR)/collisions.c

DISP = \
	$(DISP_DIR)/display_rpg.c			\
	$(DISP_DIR)/display_tiles.c			\
	$(DISP_DIR)/autumn.c				\
	$(DISP_DIR)/display_escape.c		\
	$(DISP_DIR)/night.c					\
	$(DISP_DIR)/display_menu.c			\
	$(DISP_DIR)/display_txt_box.c		\
	$(DISP_DIR)/display_inventory.c 	\
	$(DISP_DIR)/display_big_boss.c		\
	$(DISP_DIR)/display_player_choose.c \
	$(DISP_DIR)/display_settings_hud.c

DEST = \
	$(DEST_DIR)/destroy_rpg.c			\
	$(DEST_DIR)/destroy_object.c		\
	$(DEST_DIR)/destroy_window.c		\
	$(DEST_DIR)/destroy_menu.c			\
	$(DEST_DIR)/destroy_npc.c			\
	$(DEST_DIR)/destroy_player.c		\
	$(DEST_DIR)/destroy_maps.c			\
	$(DEST_DIR)/destroy_ui.c			\
	$(DEST_DIR)/destroy_boss.c 			\
	$(DEST_DIR)/destroy_text.c			\
	$(DEST_DIR)/destroy_dialogues.c		\
	$(DEST_DIR)/destroy_tiles.c			\
	$(DEST_DIR)/destroy_inventory.c 	\
	$(DEST_DIR)/destroy_player_choose.c	\
	$(DEST_DIR)/destroy_settings_hud.c	\
	$(DEST_DIR)/destroy_music.c

TILES = \
	$(TILES_DIR)/free_tiles.c	\
	$(TILES_DIR)/init_tiles.c	\
	$(TILES_DIR)/load_tiles.c

EVENT = \
	$(EVENT_DIR)/handle_events.c			\
	$(EVENT_DIR)/handle_key_pressed.c		\
	$(EVENT_DIR)/save_test/handle_save.c	\
	$(EVENT_DIR)/save_test/handle_load.c

VERTEX = \
	$(VERTEX_DIR)/create_vertex.c		\
	$(VERTEX_DIR)/get_vertex_bounds.c	\
	$(VERTEX_DIR)/set_vertex_color.c	\
	$(VERTEX_DIR)/is_in_vertex.c

SRC = $(MAIN) $(INIT) $(DISP) $(DEST) $(EVENT) $(UPDATE) \
	$(TILES) $(COLL) $(VERTEX)

OBJ := $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

NAME = my_rpg

all: $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@gcc $(CFLAGS) -o $(NAME) $^ $(LDFLAGS)
	@printf "[\033[1;32mSUCCESS\033[0m] Compiled %s\n" $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@printf "[\033[1;32mCLEAN\033[0m] Removed object directory\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f coding-style-reports.log
	@printf "[\033[1;32mFCLEAN\033[0m] Removed %s\n" $(NAME)

re: fclean all

.PHONY: all clean fclean re
