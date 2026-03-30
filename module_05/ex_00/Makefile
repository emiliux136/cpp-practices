SRC = Bureaucrat.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = bure

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re