##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

SRC 	= 	main.c \
			src/function.c \
			src/struct.c \
			src/combat.c \
			src/loop.c \
			src/quete_one.c

OBJ		=	$(SRC:.c=.o)

NAME 	=	Biotron

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda libmy.a *.gch

CFLAGS	= 	-pedantic -Wall -Wextra -W -g -O2

CSFML_FLAGS = -lncurses -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML_FLAGS)

clean:
	$(RM) $(RM_TRASH)
	cd include && $(RM) $(RM_TRASH)
	cd src && $(RM) $(RM_TRASH)

fclean: clean
	$(RM) $(NAME)

re: fclean all