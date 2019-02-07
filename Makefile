##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC = main.c function.c struct.c combat.c loop.c quete_one.c

OBJ = main.o function.o struct.o combat.o loop.o quete_one.o

CFLAGS = -W -Wall -Wextra

all: compi

compi: $(OBJ)
	gcc $(OBJ) -o BioTron -lncurses -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm $(OBJ)

fclean:
	rm BioTron

re : clean fclean all