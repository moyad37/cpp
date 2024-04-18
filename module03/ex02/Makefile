
NAME = FragTrap

SRC	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ = $(SRC:%.cpp=%.o)

INC		=	ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

all :	$(NAME)

%.o	:	%.cpp $(INC)
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