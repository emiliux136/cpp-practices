SRC = animal.cpp dog.cpp main.cpp cat.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = abstract

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re