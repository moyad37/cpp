
NAME = ZombieBrain

SRC	= main.cpp 

OBJ = $(SRC:%.cpp=%.o)


FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

all :	$(NAME)

%.o	:	%.cpp
	@c++ $(FLAGS) -c $<

$(NAME) :	$(OBJ)
	@c++ $(OBJ) -o $(NAME)
	@echo "Make Ok"

clean:
	@rm -f $(OBJ)
	@echo "clean Ok"

fclean :	clean
	@rm -f $(NAME)
	@echo "fclean Ok"

re :	fclean all