SRCS = main.cpp ScalarConverter.cpp
SRCS := $(addprefix cpp/, $(SRCS)) # Source Files Prefix

INCLUDES = "./hpp"

OBJS = $(SRCS:.cpp=.o)

NAME = skyler
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDES)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all