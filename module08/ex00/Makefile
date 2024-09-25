# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 19:59:14 by mmanssou          #+#    #+#              #
#    Updated: 2024/09/25 21:56:06 by mmanssou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable
TARGET = easyfind_test

# Source files
SRC = main.cpp

# Header files
HEADER = easyfind.hpp

# Build rules
all: $(TARGET)

$(TARGET): $(SRC) $(HEADER)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

re: clean all