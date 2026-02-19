SRC = main.cpp Fixed.cpp bsp.cpp Point.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f
FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

NAME = bsp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re