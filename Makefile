SRC	=	./src/main.c					\
		./src/Game.c					\
		./src/ErrorHandling.c			\
		./src/Object.c					\
		./src/ObjectList.c				\
		./src/System.c					\
		./src/BasicSystems.c			\
		./src/ApplyGravity.c			\
		./src/VectorOperations.c		\
		./src/CalculateAcceleration.c	\
		./src/Utils.c					\
		./src/Constants.c				\
		./src/FileParsing.c				\
		./src/LinkedList.c				\
		./src/ParserValidators.c		\
		./src/FileReader.c				\
		./src/addCharToWord.c			\
		./src/runValidators.c			\
		

OBJ	=	$(SRC:.c=.o)

NAME	=	out

CFLAGS	=	-I./include -Wall -Wextra -DDEBUG

CC	=	gcc

LD	=	-lraylib -lm

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LD)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean	all

.PHONY:	all	clean	fclean	re
