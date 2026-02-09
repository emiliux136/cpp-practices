SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f
FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

NAME = brain

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re