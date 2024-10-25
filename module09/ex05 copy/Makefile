NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
BUILD = build
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:%.cpp=$(BUILD)/%.o)

all: $(NAME)
.PHONY: all

$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(BUILD) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)
.PHONY: clean

fclean: clean
	rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
