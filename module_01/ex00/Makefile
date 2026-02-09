SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f
FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

HOT_PINK			=	\033[38;5;169m
DEF_COLOR			=	\033[0;39m
CYAN_2				=	\033[38;5;50m

NAME = zombie

all: $(NAME)

.SILENT:

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(CYAN_2)"
						@echo "  ______               _     _      "
						@sleep 0.1
						@echo " |___  /              | |   (_)     "
						@sleep 0.1
						@echo "    / / ___  _ __ ___ | |__  _  ___ "
						@sleep 0.1
						@echo "   / / / _ \\| '_ \` _ \\| '_ \\| |/ _ \\"
						@sleep 0.1
						@echo "  / /_| (_) | | | | | | |_) | |  __/"
						@sleep 0.1
						@echo " /_____\___/|_| |_| |_|_.__/|_|\___|"
						@sleep 0.1
						@echo
						@echo "$(HOT_PINK)     --->  Compiling ex01  <---$(DEF_COLOR)"
						@echo

.UNSILENT:
                                    
clean:
	$(RM) $(OBJ)
	@echo "$(HOT_PINK)Limpiando objetos...$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(HOT_PINK)Limpiando ejecutable...$(DEF_COLOR)"
	
re: fclean $(NAME)

.PHONY: all clean fclean re