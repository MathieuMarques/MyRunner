##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	main.c				\
		window.c			\
		window2.c			\
		create_rect.c		\
		event.c				\
		create_vector.c		\
		game_object.c		\
		create_color.c		\
		player.c			\
		player2.c			\
		player3.c			\
		background.c		\
		background2.c		\
		open_map.c			\
		tile_map.c			\
		tile_map2.c			\
		game_object2.c		\
		collide.c			\
		collide2.c			\
		title_screen.c		\
		title_screen2.c		\
		title_screen3.c		\
		title_screen4.c		\
		display_score.c		\
		create_text.c		\
		screen_game_over.c	\
		screen_game_over2.c	\
		screen_game_over3.c	\
		screen_game_over4.c	\
		pause_game.c		\
		pause_game2.c		\
		pause_game3.c		\
		pause_game4.c		\
		enemy.c				\
		enemy2.c

OBJ	=	$(SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system

NAME	=	my_runner

CPPFLAGS += -I include

all: $(NAME)

lib/libmy.a:
	make -C lib/my

$(NAME): lib/libmy.a $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFML) -L lib -lmy

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:
	make clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all

.PHONY:	all	clean fclean re
