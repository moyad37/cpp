# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 16:58:15 by mmanssou          #+#    #+#              #
#    Updated: 2024/08/31 18:36:37 by mmanssou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = BureaucratProgram

# SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
# OBJ = $(SRC:.cpp=.o)
# INC		=	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
# FLAGS = -Wall -Wextra -Werror -std=c++98



# all :	$(NAME)

# %.o	:	%.cpp $(INC)
# 	@c++ $(FLAGS) -c $<

# $(NAME) :	$(OBJ)
# 	@c++ $(OBJ) -o $(NAME)
# 	@echo "Make Ok"

# clean:
# 	@rm -f $(OBJ)
# 	@echo "clean Ok"

# fclean :	clean
# 	@rm -f $(NAME)
# 	@echo "fclean Ok"

# re :	fclean all



# Define the compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Define the executable name
NAME = BureaucratProgram

# Define source and object files
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ = $(SRC:.cpp=.o)

# Define header files
INC = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

# Default target
all: $(NAME)

# Rule to compile .cpp files to .o files
%.o: %.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Make Ok"

# Rule to clean up object files
clean:
	rm -f $(OBJ)
	@echo "clean Ok"

# Rule to clean up object files and the executable
fclean: clean
	rm -f $(NAME)
	@echo "fclean Ok"

# Rule to clean up and rebuild everything
re: fclean all
