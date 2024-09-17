##
## EPITECH PROJECT, 2020
## mk
## File description:
## mk
##

SRCS	=	src/main.c	\
			src/get_map.c	\
			src/read_file.c	\
			src/move_player.c	\
			src/draw_map.c	\
			src/initiate_game.c	\
			src/deal_box.c	\
			src/end.c	\
			src/gameloop.c	\
			src/display_usage.c	\
			src/stuck.c	\
			src/macro.c	\
			src/save_coins.c	\
			src/direction_move.c	\

SRCS_two =  get_table1.c	\

SRCS_UNIT =     tests/test_sokoban.c		\
			src/deal_box.c	\
			src/direction_move.c	\
			src/draw_map.c	\
			src/end.c	\
			src/gameloop.c	\
			src/get_map.c	\
			src/macro.c	\
			src/initiate_game.c	\
			src/read_file.c	\
			src/move_player.c	\
			src/stuck.c	\
			src/save_coins.c	\

OBJS	=	$(SRCS:.c=.o)

NAME	=	my_sokoban

RM	=		rm -f

INC	=		-I./include

LIB	=		-L./lib/my -lmy

CC	=		gcc

CFLAGS	=	$(INC) -W -Wall -Wextra -g3

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C lib/my/
			$(CC) -lncurses -o $(NAME) $(OBJS) $(CFLAGS) $(LIB)

clean:
			make clean -C ./lib/my/
			$(RM) $(OBJS)

fclean:	 $(NAME)
			$(RM) $(NAME)
			$(RM) *.gcno
			$(RM) *.gcda
			$(RM) -f *.o
			$(RM) unit_tests

re:			fclean all

tests_run:	fclean
			clear
			gcc -o unit_tests $(SRCS_UNIT) $(INC) -L./lib/my -lmy -lncurses --coverage -lcriterion
			./unit_tests
			gcovr