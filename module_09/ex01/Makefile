SRC = main.cpp main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = RPN

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re