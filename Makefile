##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/display_basics.c	\
		src/window_basics.c	\
		src/rpg.c	\
		src/handling/events_handeling.c	\
		src/destroyer.c	\
		src/init/init.c	\
		src/sound.c	\
		src/get.c	\
		src/start.c	\
		src/choose_scene.c	\
		src/game.c	\
		src/buttons/button_start.c	\
		src/text.c	\
		src/end.c	\
		src/display_car_choice.c	\
		src/handling/analyse_events.c	\
		src/handling/car_handling.c	\
		src/move_texture_rect.c	\
		src/create_starter_cars.c	\
		src/init/init_cars.c	\
		src/handling/dealership_events.c	\
		src/init/init2.c	\
		src/handling/check_game_pos.c	\
		src/buttons/button_start2.c	\
		src/handling/inv_handling.c	\
		src/race.c	\
		src/buttons/detect_button_pressing.c	\
		src/handling/race_handling.c	\
		src/handling/analyse_events_garage.c	\
		src/rules_scene.c	\
		src/display_garage_cars.c	\
		src/handling/garage_events.c	\
		src/init/init_return_and_so.c	\
		src/handling/manage_return.c	\
		src/draw_rect.c	\
		src/init/init_boss_cars.c 	\
		src/init/init_more_boss_cars.c	\
		src/handling/analyse_speedlist.c	\
		src/race_end.c	\
		src/init/init_parts_shop.c	\
		src/display_parts_shop.c	\
		src/handling/analyse_part_shop_events.c	\
		src/display_money.c	\
		src/display_gear_up.c	\
		src/item.c	\
		src/init/init_inv_buttons.c	\
		src/handling/analyse_purchase_item.c	\
		src/beginning_anim.c	\
		src/display_text_bubbles.c	\
		src/init/init_parts.c	\
		src/display_parts.c		\
		src/display_engine_parts.c 	\
		src/handling/analyse_engine_shop_events.c	\
		src/init/init_engine_parts.c	\
		src/init/init_beginner_cars.c	\
		src/init/init_intermediate_cars.c	\
		src/init/init_sports_cars.c	\
		src/init/init_hard_cars.c 	\
		src/init/init_oponents.c 	\
		src/music.c	\
		src/handling/analyse_purchase_item_turbo.c	\
		src/handling/analyse_purchase_item_filter.c	\
		src/rewards.c	\
		src/quest.c	\
		src/display_quests.c	\
		src/handling/analyse_purchase_item_cartos.c	\
		src/challenge.c	\
		src/display_start_animation.c	\
		src/display_alt_inv.c 	\
		src/equip.c	\
		src/display_selected.c	\
		src/handling/car_inv_handling.c	\
		src/handling/analyse_item_pressing.c	\
		src/unequip.c	\
		src/remove_items.c	\
		src/tune_car.c	\
		src/handle_boss_anim.c	\
		src/particle_effects.c	\
		src/init/init_particles.c	\
		src/do_race.c	\
		src/set_race.c	\
		src/handling/handle_derkha.c	\
		src/init/init_map.c	\
		src/display_xp.c	\
		src/error.c	\
		src/display_dealership.c	\
		src/display_inventory.c	\
		src/colision.c	\
		src/handling/analyse_buttons.c	\
		src/display_end_anim.c	\
		src/handling/analyse_pause.c	\
		src/handling/handle_move_right.c 	\
		src/init/init_musics.c	\
		src/choose_time.c	\

OBJ    =    $(SRC:.c=.o)

LDFLAGS    =    -Llib/my/ -lmy

CFLAGS    =     -g

CPPFLAGS    =    -Iincludes/

CSFML    =    -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

NAME    =    my_rpg

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CSFML)
	make fclean -C lib/my/
	make clean
	@echo -e "\x1b[32mCompilation Success\e[0m"

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C lib/my/
	$(RM) $(NAME)

re: fclean all

.PHONY : all re clean fclean