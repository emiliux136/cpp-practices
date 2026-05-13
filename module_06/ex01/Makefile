SRCS = main.cpp Serializer.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = serialize
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all