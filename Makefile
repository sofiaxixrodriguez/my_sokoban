##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## sokoban
##

CC			=	gcc

SRC			=	src/get_map.c		\
				src/window.c	\
				src/move.c	\
				src/get_pos.c		\
				src/game.c	\
				src/check_w_l.c		\
				src/main.c			\
				src/lib_1.c		\
				src/lib_2.c		\

OBJ			=	$(SRC:.c=.o)

NAME		=	my_sokoban

CPPFLAGS	=	-I./include/

LIBS		=	-lncurses

all:	$(NAME)

$(NAME):	 $(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS) $(LIBS)


clean:
				rm -f $(OBJ)

fclean: clean
				rm -f $(NAME)

re:	fclean all
